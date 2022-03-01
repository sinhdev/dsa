#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../snxlib/bstsnxlib.c"

int compare(const void *v1, const void *v2);
void printElement(const void *a);

int main(int argsCount, char **args)
{
  BinarySearchTree *bst;
  bst = bstInit(sizeof(int), compare);
  int value = 7;
  bstInsert(bst, &value);
  value = 9;
  bstInsert(bst, &value);
  value = 5;
  bstInsert(bst, &value);
  value = 14;
  bstInsert(bst, &value);
  value = 2;
  bstInsert(bst, &value);
  value = 18;
  bstInsert(bst, &value);
  value = 12;
  bstInsert(bst, &value);
  int delValue = 7;
  if (bstRemove(bst, &delValue))
  {
    printf("deleted value: %d\n", delValue);
  }
  else
  {
    printf("can't delete\n");
  }

  int searchValue = 9;
  btNode *found = bstSearch(bst, &searchValue);
  if (found != NULL)
  {
    printf("found\n");
  }
  else
  {
    printf("not found\n");
  }
  bstTraversal(bst->root, printElement);
  bstDestroy(bst);
  return 0;
}

int compare(const void *a, const void *b)
{
  return (*(int *)a - *(int *)b);
}
void printElement(const void *a)
{
  printf("element: %d\n", *((int *)a));
}