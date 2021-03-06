/* Generated by re2c 0.16 */
#include <stdlib.h>
#include "ext_scanners.h"

bufsize_t _core_ext_scan_at(bufsize_t (*scanner)(const unsigned char *),
                            const char *s, bufsize_t offset) {
  bufsize_t res;
  bufsize_t len = strlen(s);
  unsigned char *ptr = (unsigned char *)s;

  if (ptr == NULL || offset > len) {
    return 0;
  } else {
    res = scanner(ptr + offset);
  }

  return res;
}

bufsize_t _scan_table_cell(const unsigned char *p) {
  const unsigned char *marker = NULL;
  const unsigned char *start = p;

  {
    unsigned char yych;
    unsigned int yyaccept = 0;
    static const unsigned char yybm[] = {
        64, 64, 64,  64, 64, 64, 64, 64, 64, 64, 0,  64, 64, 0,  64, 64, 64, 64,
        64, 64, 64,  64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64,  64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64,  64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64,  64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 128, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64,  64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 0,  64,
        64, 64, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,   0,
    };
    yych = *(marker = p);
    if (yych <= 0xDF) {
      if (yych <= '{') {
        if (yych != '\n')
          goto yy3;
      } else {
        if (yych <= '|')
          goto yy4;
        if (yych <= 0x7F)
          goto yy3;
        if (yych >= 0xC2)
          goto yy5;
      }
    } else {
      if (yych <= 0xEF) {
        if (yych <= 0xE0)
          goto yy7;
        if (yych == 0xED)
          goto yy9;
        goto yy8;
      } else {
        if (yych <= 0xF0)
          goto yy10;
        if (yych <= 0xF3)
          goto yy11;
        if (yych <= 0xF4)
          goto yy12;
      }
    }
  yy2 : { return 0; }
  yy3:
    yych = *++p;
    goto yy2;
  yy4:
    yyaccept = 0;
    yych = *(marker = ++p);
    if (yych <= '{') {
      if (yych <= '\n') {
        if (yych <= '\t')
          goto yy14;
        goto yy2;
      } else {
        if (yych == '\r')
          goto yy2;
        goto yy14;
      }
    } else {
      if (yych <= 0x7F) {
        if (yych <= '|')
          goto yy2;
        goto yy14;
      } else {
        if (yych <= 0xC1)
          goto yy2;
        if (yych <= 0xF4)
          goto yy14;
        goto yy2;
      }
    }
  yy5:
    yych = *++p;
    if (yych <= 0x7F)
      goto yy6;
    if (yych <= 0xBF)
      goto yy3;
  yy6:
    p = marker;
    if (yyaccept == 0) {
      goto yy2;
    } else {
      goto yy15;
    }
  yy7:
    yych = *++p;
    if (yych <= 0x9F)
      goto yy6;
    if (yych <= 0xBF)
      goto yy5;
    goto yy6;
  yy8:
    yych = *++p;
    if (yych <= 0x7F)
      goto yy6;
    if (yych <= 0xBF)
      goto yy5;
    goto yy6;
  yy9:
    yych = *++p;
    if (yych <= 0x7F)
      goto yy6;
    if (yych <= 0x9F)
      goto yy5;
    goto yy6;
  yy10:
    yych = *++p;
    if (yych <= 0x8F)
      goto yy6;
    if (yych <= 0xBF)
      goto yy8;
    goto yy6;
  yy11:
    yych = *++p;
    if (yych <= 0x7F)
      goto yy6;
    if (yych <= 0xBF)
      goto yy8;
    goto yy6;
  yy12:
    yych = *++p;
    if (yych <= 0x7F)
      goto yy6;
    if (yych <= 0x8F)
      goto yy8;
    goto yy6;
  yy13:
    yyaccept = 1;
    marker = ++p;
    yych = *p;
  yy14:
    if (yybm[0 + yych] & 64) {
      goto yy13;
    }
    if (yych <= 0xEC) {
      if (yych <= 0xC1) {
        if (yych <= '\r')
          goto yy15;
        if (yych <= '\\')
          goto yy16;
      } else {
        if (yych <= 0xDF)
          goto yy18;
        if (yych <= 0xE0)
          goto yy19;
        goto yy20;
      }
    } else {
      if (yych <= 0xF0) {
        if (yych <= 0xED)
          goto yy21;
        if (yych <= 0xEF)
          goto yy20;
        goto yy22;
      } else {
        if (yych <= 0xF3)
          goto yy23;
        if (yych <= 0xF4)
          goto yy24;
      }
    }
  yy15 : { return (bufsize_t)(p - start); }
  yy16:
    yyaccept = 1;
    marker = ++p;
    yych = *p;
    if (yybm[0 + yych] & 128) {
      goto yy16;
    }
    if (yych <= 0xDF) {
      if (yych <= '\f') {
        if (yych == '\n')
          goto yy15;
        goto yy13;
      } else {
        if (yych <= '\r')
          goto yy15;
        if (yych <= 0x7F)
          goto yy13;
        if (yych <= 0xC1)
          goto yy15;
      }
    } else {
      if (yych <= 0xEF) {
        if (yych <= 0xE0)
          goto yy19;
        if (yych == 0xED)
          goto yy21;
        goto yy20;
      } else {
        if (yych <= 0xF0)
          goto yy22;
        if (yych <= 0xF3)
          goto yy23;
        if (yych <= 0xF4)
          goto yy24;
        goto yy15;
      }
    }
  yy18:
    ++p;
    yych = *p;
    if (yych <= 0x7F)
      goto yy6;
    if (yych <= 0xBF)
      goto yy13;
    goto yy6;
  yy19:
    ++p;
    yych = *p;
    if (yych <= 0x9F)
      goto yy6;
    if (yych <= 0xBF)
      goto yy18;
    goto yy6;
  yy20:
    ++p;
    yych = *p;
    if (yych <= 0x7F)
      goto yy6;
    if (yych <= 0xBF)
      goto yy18;
    goto yy6;
  yy21:
    ++p;
    yych = *p;
    if (yych <= 0x7F)
      goto yy6;
    if (yych <= 0x9F)
      goto yy18;
    goto yy6;
  yy22:
    ++p;
    yych = *p;
    if (yych <= 0x8F)
      goto yy6;
    if (yych <= 0xBF)
      goto yy20;
    goto yy6;
  yy23:
    ++p;
    yych = *p;
    if (yych <= 0x7F)
      goto yy6;
    if (yych <= 0xBF)
      goto yy20;
    goto yy6;
  yy24:
    ++p;
    yych = *p;
    if (yych <= 0x7F)
      goto yy6;
    if (yych <= 0x8F)
      goto yy20;
    goto yy6;
  }
}

bufsize_t _scan_table_row_end(const unsigned char *p) {
  const unsigned char *marker = NULL;
  const unsigned char *start = p;

  {
    unsigned char yych;
    yych = *(marker = p);
    if (yych <= 0xDF) {
      if (yych <= '{') {
        if (yych != '\n')
          goto yy28;
      } else {
        if (yych <= '|')
          goto yy29;
        if (yych <= 0x7F)
          goto yy28;
        if (yych >= 0xC2)
          goto yy30;
      }
    } else {
      if (yych <= 0xEF) {
        if (yych <= 0xE0)
          goto yy32;
        if (yych == 0xED)
          goto yy34;
        goto yy33;
      } else {
        if (yych <= 0xF0)
          goto yy35;
        if (yych <= 0xF3)
          goto yy36;
        if (yych <= 0xF4)
          goto yy37;
      }
    }
  yy27 : { return 0; }
  yy28:
    yych = *++p;
    goto yy27;
  yy29:
    yych = *(marker = ++p);
    if (yych == '\n')
      goto yy38;
    if (yych == '\r')
      goto yy40;
    goto yy27;
  yy30:
    yych = *++p;
    if (yych <= 0x7F)
      goto yy31;
    if (yych <= 0xBF)
      goto yy28;
  yy31:
    p = marker;
    goto yy27;
  yy32:
    yych = *++p;
    if (yych <= 0x9F)
      goto yy31;
    if (yych <= 0xBF)
      goto yy30;
    goto yy31;
  yy33:
    yych = *++p;
    if (yych <= 0x7F)
      goto yy31;
    if (yych <= 0xBF)
      goto yy30;
    goto yy31;
  yy34:
    yych = *++p;
    if (yych <= 0x7F)
      goto yy31;
    if (yych <= 0x9F)
      goto yy30;
    goto yy31;
  yy35:
    yych = *++p;
    if (yych <= 0x8F)
      goto yy31;
    if (yych <= 0xBF)
      goto yy33;
    goto yy31;
  yy36:
    yych = *++p;
    if (yych <= 0x7F)
      goto yy31;
    if (yych <= 0xBF)
      goto yy33;
    goto yy31;
  yy37:
    yych = *++p;
    if (yych <= 0x7F)
      goto yy31;
    if (yych <= 0x8F)
      goto yy33;
    goto yy31;
  yy38:
    ++p;
    { return (bufsize_t)(p - start); }
  yy40:
    ++p;
    if ((yych = *p) == '\n')
      goto yy38;
    goto yy31;
  }
}

bufsize_t _scan_table_start(const unsigned char *p) {
  const unsigned char *marker = NULL;
  const unsigned char *start = p;

  {
    unsigned char yych;
    static const unsigned char yybm[] = {
        0, 0,   0, 0, 0, 0, 0, 0, 0, 64, 0,  64, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0,   0, 0, 0, 0, 0, 0, 0, 0,  64, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 128, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0,   0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0,   0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0,   0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0,   0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0,   0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0,   0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0,   0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0,   0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0,   0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0,
    };
    yych = *(marker = p);
    if (yych <= 0xDF) {
      if (yych <= '{') {
        if (yych != '\n')
          goto yy44;
      } else {
        if (yych <= '|')
          goto yy45;
        if (yych <= 0x7F)
          goto yy44;
        if (yych >= 0xC2)
          goto yy46;
      }
    } else {
      if (yych <= 0xEF) {
        if (yych <= 0xE0)
          goto yy48;
        if (yych == 0xED)
          goto yy50;
        goto yy49;
      } else {
        if (yych <= 0xF0)
          goto yy51;
        if (yych <= 0xF3)
          goto yy52;
        if (yych <= 0xF4)
          goto yy53;
      }
    }
  yy43 : { return 0; }
  yy44:
    yych = *++p;
    goto yy43;
  yy45:
    yych = *(marker = ++p);
    if (yybm[0 + yych] & 64) {
      goto yy54;
    }
    if (yych == '-')
      goto yy56;
    goto yy43;
  yy46:
    yych = *++p;
    if (yych <= 0x7F)
      goto yy47;
    if (yych <= 0xBF)
      goto yy44;
  yy47:
    p = marker;
    goto yy43;
  yy48:
    yych = *++p;
    if (yych <= 0x9F)
      goto yy47;
    if (yych <= 0xBF)
      goto yy46;
    goto yy47;
  yy49:
    yych = *++p;
    if (yych <= 0x7F)
      goto yy47;
    if (yych <= 0xBF)
      goto yy46;
    goto yy47;
  yy50:
    yych = *++p;
    if (yych <= 0x7F)
      goto yy47;
    if (yych <= 0x9F)
      goto yy46;
    goto yy47;
  yy51:
    yych = *++p;
    if (yych <= 0x8F)
      goto yy47;
    if (yych <= 0xBF)
      goto yy49;
    goto yy47;
  yy52:
    yych = *++p;
    if (yych <= 0x7F)
      goto yy47;
    if (yych <= 0xBF)
      goto yy49;
    goto yy47;
  yy53:
    yych = *++p;
    if (yych <= 0x7F)
      goto yy47;
    if (yych <= 0x8F)
      goto yy49;
    goto yy47;
  yy54:
    ++p;
    yych = *p;
    if (yybm[0 + yych] & 64) {
      goto yy54;
    }
    if (yych != '-')
      goto yy47;
  yy56:
    ++p;
    yych = *p;
    if (yybm[0 + yych] & 128) {
      goto yy56;
    }
    if (yych <= '\f') {
      if (yych == '\t')
        goto yy58;
      if (yych <= '\n')
        goto yy47;
    } else {
      if (yych <= ' ') {
        if (yych <= 0x1F)
          goto yy47;
      } else {
        if (yych == '|')
          goto yy60;
        goto yy47;
      }
    }
  yy58:
    ++p;
    yych = *p;
    if (yych <= '\f') {
      if (yych == '\t')
        goto yy58;
      if (yych <= '\n')
        goto yy47;
      goto yy58;
    } else {
      if (yych <= ' ') {
        if (yych <= 0x1F)
          goto yy47;
        goto yy58;
      } else {
        if (yych != '|')
          goto yy47;
      }
    }
  yy60:
    ++p;
    yych = *p;
    if (yybm[0 + yych] & 64) {
      goto yy54;
    }
    if (yych <= '\r') {
      if (yych <= 0x08)
        goto yy47;
      if (yych >= '\v')
        goto yy63;
    } else {
      if (yych == '-')
        goto yy56;
      goto yy47;
    }
  yy61:
    ++p;
    { return (bufsize_t)(p - start); }
  yy63:
    ++p;
    if ((yych = *p) == '\n')
      goto yy61;
    goto yy47;
  }
}
