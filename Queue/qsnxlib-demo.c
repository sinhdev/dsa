#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../snxlib/qsnxlib.c"

int main(int argsCount, char** args){
  Queue *q;
  q = initQueue(sizeof(int));
  int value=1, *p;
  qEnqueue(q, &value);
  value = 2;
  qEnqueue(q, &value);
  value = 3;
  qEnqueue(q, &value);
  value = 4;
  qEnqueue(q, &value);
  value = 5;
  qEnqueue(q, &value);

  while((p=qDequeue(q))!=NULL){
    printf("dqueue: %d\n", *p);
    free(p);
  }
  return 0;
}