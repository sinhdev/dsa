#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arrlist.c"

int main(int argsCount, char **args){
  ArrayList *al;
  al = alInit(sizeof(int), 0);

  int newInt = 4;
  alInsert(al, &newInt);

  newInt = 5;
  alInsert(al, &newInt);
  newInt = 9;
  alInsert(al, &newInt);
  newInt = 2;
  alInsertAt(al, &newInt, 0);
  newInt = 7;
  alInsertAt(al, &newInt, 1);
  alRemoveAt(al, 3);

  int *vPos;
  for(int i=0; i<al->count; i++){
    vPos = (int*) alGetAt(al, i);
    printf("array list [%d] = %d\n", i, *vPos);
  }
  alShowInfo(al);

  alDestroy(al);
  return 0;
}