#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "queue.h"
#include "string.h"

typedef struct q_item *q_item;

struct q_item {
  int item;
  q_item next;
};

struct queue {
  q_item first;
  q_item last;
  int length;
};

queue queue_new(){
  queue result = emalloc(sizeof *result);
  result->length = 0;
  result->first = NULL;
  return result;
}

void enqueue(queue q, int item){
  q_item n = emalloc(sizeof *n);
  n->item = item; 
  if (q->first == NULL){
    q->first = n;
  }
  else{
    q->last->next = n;
  }
  n->next =NULL;
  q->last = n;
  q->length ++;
}

int dequeue(queue q){
  if(q->length >0){
    q_item temp = q->first;
    q->first = q->first->next;
    q->length --; 
    return temp->item; 
  }
  return 0; 
}


void queue_print(queue q){
  q_item pos = q->first;
 
  while (pos != NULL){
    printf("%d\n", pos->item);
    pos = pos->next;
  }
}

int queue_size(queue q){
  return q->length; 
}

void queue_free(queue q){
  q_item pos = q->first;
  while (pos != NULL){
    free(pos);
    pos = pos->next;
  }
}
