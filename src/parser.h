#ifndef CMARK_AST_H
#define CMARK_AST_H

#include <stdio.h>
#include "node.h"
#include "buffer.h"
#include "memory.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_LINK_LABEL_LENGTH 1000

struct cmark_parser {
  struct cmark_mem *mem;
  struct cmark_reference_map *refmap;
  struct cmark_node *root;
  struct cmark_node *previous;
  struct cmark_node *current;
  int line_number;
  bufsize_t offset;
  bufsize_t line_offset; /* Total offset for this line, in bytes from the start of the document */
  bufsize_t last_block_offset; /* Allow for multiple blocks to happen on the same line */
  bufsize_t column;
  bufsize_t first_nonspace;
  bufsize_t first_nonspace_column;
  int indent;
  bool blank;
  bool partially_consumed_tab;
  cmark_strbuf curline;
  bufsize_t last_line_length;
  cmark_strbuf linebuf;
  int options;
  bool last_buffer_ended_with_cr;
};

#ifdef __cplusplus
}
#endif

#endif
