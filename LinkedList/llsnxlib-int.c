#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../snxlib/llsnxlib.c"

int main(int argCount, char *args[])
{
  LinkedList *llInt;
  llInt = llInit(sizeof(int));
  int value = 7;
  llInsert(llInt, &value);
  value = 6;
  llInsert(llInt, &value);
  value = 5;
  llInsert(llInt, &value);
  llRemove(llInt);

  int *curValue;
  // if (llInitIterator(llInt))
  // {
  //   while (llHasNext(llInt))
  //   {
  //     curValue = (int *)llNext(llInt);
  //     printf("| %d |->", *curValue);
  //   }
  //   printf("NULL\n");
  // }
  value = 9;
  if (llInsertAt(llInt, &value, 1))
  {
    printf("insert complete!\n");
  }
  else
  {
    printf("insert not complete!\n");
  }
  value = 10;
  if (llInsertAt(llInt, &value, 3))
  {
    printf("insert complete!\n");
  }
  else
  {
    printf("insert not complete!\n");
  }

  if (llRemoveAt(llInt, -5))
  {
    printf("delete complete!\n");
  }
  else
  {
    printf("delete not complete!\n");
  }

  for (llInitIterator(llInt); llHasNext(llInt);)
  {
    curValue = (int *)llNext(llInt);
    printf("|%d| -> ", *curValue);
  }
  printf("NULL\n");

  llDestroy(llInt);
  return 0;
}