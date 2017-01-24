#include <stdio.h>
#include <string.h>

#include "single_linked_list.h"

// Global variable: the head of the list.
list_head_t* g_list_head = NULL; 

int main(int argc, char** argv)
{
  list_node_t* node_a = ALLOC(list_node_t, 1);
  char* str = ALLOC(char,10);

  strcpy(str, "new_item");
  str[8]='\0';
    node_a->item = (void*)str;
  node_a->key = 15;

  if(init_list(&g_list_head) < 0){ 
    exit(1);
  }

  printf("# of node in the list is %d\n", g_list_head->num_of_node); 
  printf("Let's insert the new node!\n");
  insert_node(&g_list_head, &node_a);
  printf("# of node in the list is %d\n", g_list_head->num_of_node);
  printf("Let's delete the node!\n");
  delete_node_by_key(&g_list_head, 15);
  printf("# of node in the list is %d\n", g_list_head->num_of_node);

  delete_the_list(&g_list_head);
  if(g_list_head == NULL){
    printf("List is null!\n");
  }
  else{
    printf("List is not empty!\n");
  }
  return 0;
}
