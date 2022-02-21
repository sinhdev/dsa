#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../snxlib/snxlib.c"
#include "../snxlib/booksnxlib.c"
#include "../snxlib/llsnxlib.c"

void printLinkedListBooks(LinkedList *ll);

int main(int argsCount, char **args)
{
  LinkedList *llBooks;
  llBooks = llInit(sizeof(Book));
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
      llInsert(llBooks, &myBook);
      break;
    case 2:
      printf("Input position to insert: ");
      scanf("%d", &pos);
      if (pos < 0)
      {
        printf("invalid position...\n");
      }
      else
      {
        myBook = getBook();
        llInsertAt(llBooks, &myBook, pos);
      }
      break;
    case 3:
      printf("Input position to update: ");
      scanf("%d", &pos);
      pBook = (Book*)llGetAt(llBooks, pos);
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
      if (llRemoveAt(llBooks, pos))
      {
        printf("delete book complete!\n");
      }
      else
      {
        printf("delete book error!\n");
      }
      break;
    case 5:
      printLinkedListBooks(llBooks);
      break;
    case 6:
      llBooks = llLoadFromFile("books.dat");
      if (llBooks != NULL)
      {
        printf("Load from file complete!\n");
      }
      else
      {
        printf("Load from file has error!!!\n");
      }
      break;
    case 7:
      if (llSaveToFile(llBooks, "books.dat"))
      {
        printf("Save to file complete!\n");
      }
      else
      {
        printf("Save to file has error!!!\n");
      }
      break;
    case 8:
      llDestroy(llBooks);
      break;
    }
    waitEnterPress("Press Enter to continue...");
  } while (yourChoice != topMenuItems);
  return 0;
}
void printLinkedListBooks(LinkedList *ll)
{
  printTitle();
  Book *element;
  for (llInitIterator(ll); llHasNext(ll);)
  {
    element = (Book *)llNext(ll);
    printBook(*element);
  }
  printLine();
}