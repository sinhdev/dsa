#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../snxlib/snxlib.c"
#include "../snxlib/booksnxlib.c"
#include "arrlist.c"

void printArrayListBooks(ArrayList *al);

int main(int argsCount, char **args)
{
  ArrayList *alBooks;
  alBooks = alInit(sizeof(Book), 8);
  Book myBook, *pBook;

  int topMenuItems = 8;
  char *topMenu[] = {"Add", "Insert", "Update", "Delete", "Display List Books", "Load from file...", "Save to File...", "Exit"};
  int yourChoice, pos;
  do
  {
    yourChoice = menu("BOOK MANAGEMENT APPLICATION", topMenuItems, topMenu);
    clearKeyboardBuffer();
    switch (yourChoice)
    {
    case 1:
      // add book
      myBook = getBook();
      alInsert(alBooks, &myBook);
      break;
    case 2:
      printf("Input position to insert: ");
      scanf("%d", &pos);
      if (pos < 0 || pos > alBooks->count)
      {
        printf("invalid position...\n");
      }
      else
      {
        myBook = getBook();
        alInsertAt(alBooks, &myBook, pos);
      }
      break;
    case 3:
      printf("Input position to update: ");
      scanf("%d", &pos);
      pBook = (Book*)alGetAt(alBooks, pos);
      if (pBook == NULL)
      {
        printf("invalid position...\n");
      }
      else
      {
        *pBook = getBook();
        printf("update book complete!\n");
      }
      break;
    case 4:
      printf("Input position to delete: ");
      scanf("%d", &pos);
      if (alRemoveAt(alBooks, pos))
      {
        printf("delete book complete!\n");
      }
      else
      {
        printf("delete book error!\n");
      }
      break;
    case 5:
      printArrayListBooks(alBooks);
      break;
    case 6:
      alBooks = alLoadFromFile("books.dat");
      if (alBooks != NULL)
      {
        printf("Load from file complete!\n");
      }
      else
      {
        printf("Load from file has error!!!\n");
      }
      break;
    case 7:
      if (alSaveToFile(alBooks, "books.dat"))
      {
        printf("Save to file complete!\n");
      }
      else
      {
        printf("Save to file has error!!!\n");
      }
      break;
    case 8:
      alDestroy(alBooks);
      break;
    }
    waitEnterPress("Press Enter to continue...");
  } while (yourChoice != topMenuItems);
  return 0;
}
void printArrayListBooks(ArrayList *al)
{
  printTitle();
  int count = al->count;
  Book *element;
  for (int i = 0; i < count; i++)
  {
    element = (Book *)alGetAt(al, i);
    printBook(*element);
  }
  printLine();
}