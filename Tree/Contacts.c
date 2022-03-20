#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../snxlib/snxlib.c"
#include "../snxlib/bstsnxlib.c"

typedef struct
{
  char firstName[21];
  char middleName[21];
  char lastName[21];
  char phone[11];
} Contact;

int contactCmp(const void *c1, const void *c2);
int firstNameCmp(const void *c1, const void *c2);
Contact inputContact();
void printContact(const void *a);
void initContact(BinarySearchTree *bst);

int main(int argsCount, char **args)
{
  BinarySearchTree *bstContacts = bstInit(sizeof(Contact), contactCmp);
  initContact(bstContacts);
  char *menuItems[] = {"Add New Contact", "Search By Name", "Display All Contacts", "Exit"};
  int menuItemsCount = 4;
  int yourChoice;
  Contact contact;
  do
  {
    yourChoice = menu("CONTACTS APPLICATION", menuItemsCount, menuItems);
    clearKeyboardBuffer();
    switch (yourChoice)
    {
    case 1:
      contact = inputContact();
      if (bstInsert(bstContacts, &contact))
      {
        printf("Insert contact complete!\n");
      }
      else
      {
        printf("Insert contact not complete!\n");
      }
      break;
    case 2:
      printf("Input Name: ");
      getString((&contact)->firstName, 20);
      btNode *result = bstSearchCondition(bstContacts->root, firstNameCmp, &contact);
      if (result == NULL)
        printf("Not found.\n");
      else
      {
        bstTraversalCondition(result, firstNameCmp, &contact, printContact);
      }
      break;
    case 3:
      bstTraversal(bstContacts->root, printContact);
      break;
    }
    waitEnterPress("Press Enter to continue...");
  } while (yourChoice != menuItemsCount);
  return 0;
}
Contact inputContact()
{
  Contact c;
  printf(" - Input contact information:\n");
  printf("First Name: ");
  getString(c.firstName, 20);
  printf("Middle Name: ");
  getString(c.middleName, 20);
  printf("Last Name: ");
  getString(c.lastName, 20);
  printf("Phone: ");
  getString(c.phone, 10);
  return c;
}
int contactCmp(const void *c1, const void *c2)
{
  Contact *con1 = (Contact *)c1;
  Contact *con2 = (Contact *)c2;
  int cmp;
  if ((cmp = strcmp(con1->firstName, con2->firstName)) == 0)
  {
    if ((cmp = strcmp(con1->lastName, con2->lastName)) == 0)
    {
      cmp = strcmp(con1->middleName, con2->middleName);
    }
  }
  return cmp;
}
int firstNameCmp(const void *c1, const void *c2)
{
  return strcmp(((Contact *)c1)->firstName, ((Contact *)c2)->firstName);
}
void printContact(const void *v)
{
  Contact *c = (Contact *)v;
  printf("| %10s | %s %s %s \n", c->phone, c->lastName, c->middleName, c->firstName);
}

void initContact(BinarySearchTree *bst)
{
  Contact c1 = {"Nam", "Van", "Nguyen", "0123456789"};
  bstInsert(bst, &c1);
  Contact c2 = {"Nam", "Van", "Tran", "1234567890"};
  bstInsert(bst, &c2);
  Contact c3 = {"Nam", "Van", "Hoang", "2345678901"};
  bstInsert(bst, &c3);
  Contact c4 = {"Nam", "Hoai", "Nguyen", "3456789012"};
  bstInsert(bst, &c4);
  Contact c5 = {"Nam", "Viet", "Hoang", "4567890123"};
  bstInsert(bst, &c5);
  Contact c6 = {"Nam", "Van", "Dinh", "5678901234"};
  bstInsert(bst, &c6);
  Contact c7 = {"Nam", "Hoang", "Nguyen", "6789012345"};
  bstInsert(bst, &c7);
  Contact c8 = {"Long", "Hoang", "Nguyen", "6789012345"};
  bstInsert(bst, &c8);
  Contact c9 = {"An", "Hoang", "Nguyen", "6789012345"};
  bstInsert(bst, &c9);
}