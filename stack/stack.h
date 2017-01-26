
#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

/* maximum stack size */
#define MAX_STACK_SIZE 100

typedef struct {
  int key;
  void* item;
}element_t;

element_t g_stack[MAX_STACK_SIZE];
int top=-1;

bool is_empty(element_t* stack){
  return (stack) ? true : false;
}

bool is_full(element_t* stack){
  return (top==MAX_STACK_SIZE-1) ? true : false;
}

void push(element_t* element){
  if(is_full(g_stack) == true){
    fprintf(stderr, "Stack is full!\n");
  }
  
  g_stack[++top] = element;
}
element_t pop(){
  if(top == -1){
    fprintf(stderr, "Stcak is empty!\n");
    return NULL;
  }
  return g_stack[top--];
}




#endif
