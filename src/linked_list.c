#include <stdlib.h>

#include "cmark.h"

cmark_llist *cmark_llist_append(cmark_llist *head, void *data) {
  cmark_llist *tmp;
  cmark_llist *new_node = malloc(sizeof(cmark_llist));

  new_node->data = data;
  new_node->next = NULL;

  if (!head)
    return new_node;

  for (tmp = head; tmp->next; tmp=tmp->next);

  tmp->next = new_node;

  return head;
}

void cmark_llist_free_full(cmark_llist *head, CMarkListFreeFunc free_func) {
  cmark_llist *tmp, *prev;

  for (tmp = head; tmp;) {
    if (free_func)
      free_func(tmp->data);

    prev = tmp;
    tmp = tmp->next;
    free(prev);
  }
}

void cmark_llist_free(cmark_llist *head) {
  cmark_llist_free_full(head, NULL);
}
