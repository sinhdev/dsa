#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../snxlib/stacksnxlib.c"

int main(int argCount, char *args[])
{
  Stack *s;
  s = initStack(sizeof(int));
  int decimal, dec2;
  printf("Input an integer number: ");
  scanf("%d", &decimal);
  while (decimal > 0)
  {
    dec2 = decimal % 2;
    sPush(s, &dec2);
    decimal /= 2;
  }
  printf("Binary value: ");
  int *sValue;
  while (!sIsEmpty(s))
  {
    sValue = (int *)sPop(s);
    printf("%d", *sValue);
    free(sValue);
  }
  printf("\n");
  return 0;
}