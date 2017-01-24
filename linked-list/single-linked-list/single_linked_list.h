

#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

#define ALLOC(t,n) (t*)malloc((n)*sizeof(t))
#define FREE(t) free(t)

/*
 *  Single linked list with key value and item.
 *  The list has only one item with a specific key.
 */

typedef struct list_node {
  int key;
  void* item;
  
  struct list_node* next;
}list_node_t;

typedef struct list_head {
  int num_of_node;
  list_node_t* start;
}list_head_t;

/*
 *  Initialize the list.
 *  
 */
int init_list(list_head_t** list_head){
  if(*list_head){
    printf("List Head is not empty!\n");
    return -1;
  }

  *list_head = ALLOC(list_head_t, 1);
  (*list_head)->num_of_node = 0;
  (*list_head)->start = NULL;

  return 0;
}

/*
 *  Insert the new node to the list.
 *  Because the list does not allow duplicated node with same key,
 *  If there is the node with a same key, it only updates the item.
 *
 *  If there is nothing errorenous, it returns 0;
 *  else return some value
 */
int insert_node(list_head_t** list_head, list_node_t** new_node){
  int find_flag = 0;

  if(*list_head == NULL){ 
    printf("list is not initialized!\n");

    if(init_list(&(*list_head)) < 0){
      fprintf(stderr, "Error: List cannot be initialized!\n");
      return -1;
    }
    
  }

  // If the list is empty,
  if((*list_head)->start == NULL){
    (*list_head)->start = (*new_node);
    (*new_node)->next = NULL;
  }
  // If there are some stuffs in the list,
  else{
    // Check if there is duplicated node,
    list_node_t* pre = NULL;
    list_node_t* node = (*list_head)->start;
    while(node){
      // If there is duplicated node,
      if(node->key == (*new_node)->key){
        // Replace the target node with new node.
        (*new_node)->next = node->next;
        FREE(node->item);
        FREE(node);

        // The target node is the head of the list
        if(pre == NULL){ 
          (*list_head)->start = (*new_node);
        }
        else{ 
          pre->next = (*new_node);
        }

        // Check the find_flag to notify there was duplicated node
        find_flag = 1;
        break;
      }
      pre = node;
      node = node->next;
    }
    // If there is no node with same key,
    if(find_flag == 0){    
      (*new_node)->next = (*list_head)->start;
      (*list_head)->start = (*new_node);
    }

  }
  (*list_head)->num_of_node++;
  return 0;
}

/*
 *  Delete the node with the key.
 *  If there is no corresponding item, just ignore. 
 */
int delete_node_by_key(list_head_t** list_head, int key){

  if(*list_head == NULL){
    fprintf(stderr, "list is empty! can not delete the node \n");
    return -1;
  }
  else{
    list_node_t* pre = NULL;
    list_node_t* node = (*list_head)->start;

    while(node){
      // Find the target node
      if(node->key == key){
        // If the target node is the start of the list,
        if(pre == NULL){
          (*list_head)->start = node->next;
        }
        else{
          pre->next = node->next;
        }
        FREE(node->item);
        FREE(node);
        (*list_head)->num_of_node--;
        break;
      }
      pre = node;
      node = node->next;
    }
  }
 
  return 0;
}

/*
 *  Get the item by the key.
 *  return the item with the key.
 */
void* get_item_by_key(list_head_t** list_head, int key){
  if(*list_head == NULL){
    fprintf(stderr, "List is empty! \n");
    return NULL;
  }
  else{
    list_node_t* node = (*list_head)->start;

    while(node){
      if(node->key == key){
        return node->item;
      }
      node = node->next;
    }
  }

  return NULL;
}


int delete_the_list(list_head_t** list_head){
  if((*list_head) == NULL){
    printf("list is already empty!\n");
    return 0;
  }

  list_node_t* node = (*list_head)->start;
  
  while(node){
    (*list_head)->start = node->next;
    FREE(node->item);
    FREE(node);

    node = (*list_head)->start;
  } 
  free((*list_head));
  *list_head = NULL;

  return 0;
}


#endif
