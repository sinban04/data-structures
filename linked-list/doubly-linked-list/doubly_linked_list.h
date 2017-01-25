

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

#define ALLOC(t,n) (t*)malloc((n)*sizeof(t))
#define FREE(t) free(t)

/*
 * Doubly linked list with key value and item.
 * 
 */

/*
 * Data structures
 */
typedef struct list_node {
  int key;
  void* item;
  
  struct list_node* prev;
  struct list_node* next;
}list_node_t;

typedef struct list_head {
  int num_of_node;
  list_node_t* start;
  list_node_t* end;
}list_head_t;

/*
 * Initialize the list.
 * 
 */
int init_list(list_head_t** list_haed){
  if(*list_head){
    printf("List head is not empty\n");
    return -1;
  }
  *list_head = ALLOC(list_head_t, 1);
  (*list_head)->num_of_node = 0;
  (*list_head)->start = NULL;
  (*list_head)->end = NULL;
  return 0;
}










#endif
