#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "memory.h"
#include "cmark.h"
#include "node.h"
#include "registry.h"

#if defined(_WIN32) && !defined(__CYGWIN__)
#include <io.h>
#include <fcntl.h>
#endif

typedef enum {
  FORMAT_NONE,
  FORMAT_HTML,
  FORMAT_XML,
  FORMAT_MAN,
  FORMAT_COMMONMARK,
  FORMAT_LATEX
} writer_format;

void print_usage() {
  printf("Usage:   cmark [FILE*]\n");
  printf("Options:\n");
  printf("  --to, -t FORMAT                Specify output format (html, xml, man, "
         "commonmark, latex)\n");
  printf("  --width WIDTH    Specify wrap width (default 0 = nowrap)\n");
  printf("  --sourcepos      Include source position attribute\n");
  printf("  --hardbreaks     Treat newlines as hard line breaks\n");
  printf("  --nobreaks       Render soft line breaks as spaces\n");
  printf("  --safe           Suppress raw HTML and dangerous URLs\n");
  printf("  --smart          Use smart punctuation\n");
  printf("  --validate-utf8  Replace UTF-8 invalid sequences with U+FFFD\n");
  printf("  -e, --extension EXTENSION_NAME Specify an extension name to use\n");
  printf("  --list-extensions              List available extensions and quit\n");
  printf("  --help, -h       Print usage information\n");
  printf("  --version        Print version\n");
}

static bool print_document(cmark_node *document, writer_format writer,
                           int options, int width) {
  char *result;

  switch (writer) {
  case FORMAT_HTML:
    result = cmark_render_html(document, options);
    break;
  case FORMAT_XML:
    result = cmark_render_xml(document, options);
    break;
  case FORMAT_MAN:
    result = cmark_render_man(document, options, width);
    break;
  case FORMAT_COMMONMARK:
    result = cmark_render_commonmark(document, options, width);
    break;
  case FORMAT_LATEX:
    result = cmark_render_latex(document, options, width);
    break;
  default:
    fprintf(stderr, "Unknown format %d\n", writer);
    return false;
  }

  printf("%s", result);
  cmark_node_mem(document)->free(result);

  return true;
}

static void print_extensions(void) {
  cmark_llist *syntax_extensions;
  cmark_llist *tmp;

  printf ("Available extensions:\n");

  syntax_extensions = cmark_list_syntax_extensions();
  for (tmp = syntax_extensions; tmp; tmp=tmp->next) {
    cmark_syntax_extension *ext = (cmark_syntax_extension *) tmp->data;
    printf("%s\n", ext->name);
  }

  cmark_llist_free(syntax_extensions);
}

int main(int argc, char *argv[]) {
  int i, numfps = 0;
  int *files;
  char buffer[4096];
  cmark_parser *parser = NULL;
  size_t bytes;
  cmark_node *document = NULL;
  int width = 0;
  char *unparsed;
  writer_format writer = FORMAT_HTML;
  int options = CMARK_OPT_DEFAULT;
  int res = 1;

  cmark_init();

#if defined(_WIN32) && !defined(__CYGWIN__)
  _setmode(_fileno(stdin), _O_BINARY);
  _setmode(_fileno(stdout), _O_BINARY);
#endif

  files = (int *)calloc(argc, sizeof(*files));

  for (i = 1; i < argc; i++) {
    if (strcmp(argv[i], "--version") == 0) {
      printf("cmark %s", CMARK_VERSION_STRING);
      printf(" - CommonMark converter\n(C) 2014-2016 John MacFarlane\n");
      goto success;
    } else if (strcmp(argv[i], "--list-extensions") == 0) {
      print_extensions();
      goto success;
    } else if (strcmp(argv[i], "--sourcepos") == 0) {
      options |= CMARK_OPT_SOURCEPOS;
    } else if (strcmp(argv[i], "--hardbreaks") == 0) {
      options |= CMARK_OPT_HARDBREAKS;
    } else if (strcmp(argv[i], "--nobreaks") == 0) {
      options |= CMARK_OPT_NOBREAKS;
    } else if (strcmp(argv[i], "--smart") == 0) {
      options |= CMARK_OPT_SMART;
    } else if (strcmp(argv[i], "--safe") == 0) {
      options |= CMARK_OPT_SAFE;
    } else if (strcmp(argv[i], "--validate-utf8") == 0) {
      options |= CMARK_OPT_VALIDATE_UTF8;
    } else if ((strcmp(argv[i], "--help") == 0) ||
               (strcmp(argv[i], "-h") == 0)) {
      print_usage();
      goto success;
    } else if (strcmp(argv[i], "--width") == 0) {
      i += 1;
      if (i < argc) {
        width = (int)strtol(argv[i], &unparsed, 10);
        if (unparsed && strlen(unparsed) > 0) {
          fprintf(stderr, "failed parsing width '%s' at '%s'\n", argv[i],
                  unparsed);
          goto failure;
        }
      } else {
        fprintf(stderr, "--width requires an argument\n");
        goto failure;
      }
    } else if ((strcmp(argv[i], "-t") == 0) || (strcmp(argv[i], "--to") == 0)) {
      i += 1;
      if (i < argc) {
        if (strcmp(argv[i], "man") == 0) {
          writer = FORMAT_MAN;
        } else if (strcmp(argv[i], "html") == 0) {
          writer = FORMAT_HTML;
        } else if (strcmp(argv[i], "xml") == 0) {
          writer = FORMAT_XML;
        } else if (strcmp(argv[i], "commonmark") == 0) {
          writer = FORMAT_COMMONMARK;
        } else if (strcmp(argv[i], "latex") == 0) {
          writer = FORMAT_LATEX;
        } else {
          fprintf(stderr, "Unknown format %s\n", argv[i]);
          goto failure;
        }
      } else {
        fprintf(stderr, "No argument provided for %s\n", argv[i - 1]);
        goto failure;
      }
    } else if ((strcmp(argv[i], "-e") == 0) || (strcmp(argv[i], "--extension") == 0)) {
      i += 1; // Simpler to handle extensions in a second pass, as we can directly register
              // them with the parser.
    } else if (*argv[i] == '-') {
      print_usage();
      goto failure;
    } else { // treat as file argument
      files[numfps++] = i;
    }
  }

  parser = cmark_parser_new(options);

  for (i = 1; i < argc; i++) {
    if ((strcmp(argv[i], "-e") == 0) || (strcmp(argv[i], "--extension") == 0)) {
      i += 1;
      if (i < argc) {
        cmark_syntax_extension *syntax_extension = cmark_find_syntax_extension(argv[i]);
        if (!syntax_extension) {
          fprintf(stderr, "Unknown extension %s\n", argv[i]);
          goto failure;
        }
        cmark_parser_attach_syntax_extension(parser, syntax_extension);
      } else {
        fprintf(stderr, "No argument provided for %s\n", argv[i - 1]);
        goto failure;
      }
    }
  }

  for (i = 0; i < numfps; i++) {
    FILE *fp = fopen(argv[files[i]], "rb");
    if (fp == NULL) {
      fprintf(stderr, "Error opening file %s: %s\n", argv[files[i]],
              strerror(errno));
      goto failure;
    }

    while ((bytes = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
      cmark_parser_feed(parser, buffer, bytes);
      if (bytes < sizeof(buffer)) {
        break;
      }
    }

    fclose(fp);
  }

  if (numfps == 0) {

    while ((bytes = fread(buffer, 1, sizeof(buffer), stdin)) > 0) {
      cmark_parser_feed(parser, buffer, bytes);
      if (bytes < sizeof(buffer)) {
        break;
      }
    }
  }

  document = cmark_parser_finish(parser);

  if (!print_document(document, writer, options, width))
    goto failure;


success:
  res = 0;

failure:
  if (parser)
    cmark_parser_free(parser);

  if (document)
    cmark_node_free(document);

  free(files);
  cmark_deinit();

  return res;
}
