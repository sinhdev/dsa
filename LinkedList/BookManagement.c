#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char isbn[15];
	char title[51];
	char author[51];
	float price;
}Books;
struct LinkedList{
    Books book;
    struct LinkedList* next;
};
typedef struct LinkedList ListBook;
/* Function Prototype */
void printBook(Books book);
Books getBook();
void getString(char *str, int length);
void printLine();
void printTitle();
int menu(int menuItemCount, char *menuItem[]);
int addToLast(ListBook** first, ListBook* newBook);
int addToFirst(ListBook** first, ListBook* newBook);
void printListBooks(ListBook* first);
int inputListBook(ListBook* lb);
int insert(ListBook** first, ListBook* newBook, int atIndex);
int count(ListBook* first);
ListBook* getAtIndex(ListBook* first, int index);
ListBook* searchByIsbn(ListBook* first, char* ibn);
int deleteByIsbn(ListBook** first, char* ibn);
void clearCache();
void waitEnterPress(char* msg);

int main( ) {
    int topMenuItems = 6;
    char* topMenu[] = {"Add", "Insert", "Update", "Delete", "Display List Books", "Exit"};
    ListBook *first = NULL;
    ListBook *nBook;
    int position;
    char ibn[15];
    int yourChoice;

    do{
        yourChoice = menu(topMenuItems, topMenu);
        clearCache();
        switch(yourChoice){
            case 1:
                //add book
                nBook = (ListBook*)malloc(sizeof(ListBook));
                inputListBook(nBook);
                addToLast(&first, nBook);
                break;
            case 2:
                printf("Input index: ");
                scanf("%d", &position);
                if(position < 0 || position > count(first)){
                    printf("invalid index...\n");
                }else{
                    nBook = (ListBook*)malloc(sizeof(ListBook));
                    inputListBook(nBook);
                    if(insert(&first, nBook, position)){
                        printf("Insert complete!\n");
                    }else{
                        printf("Insert error...\n");
                    }
                }
                waitEnterPress("Press Enter go to main menu...");
                break;
            case 3:
                printf("Input ISBN: ");
                getString(ibn, 15);
                nBook = searchByIsbn(first, ibn);
                if(nBook==NULL){
                    printf("ISBN: %s not found\n", ibn);
                }else{
                    printf("Input Book title: ");
                    getString(nBook->book.title, 50);
                    printf("Input Book author: ");
                    getString(nBook->book.author, 50);
                    printf("Input Book price: ");
                    scanf("%f", &(nBook->book.price));
                }
                waitEnterPress("Press Enter go to main menu...");
                break;
            case 4:
                printf("Input ISBN: ");
                getString(ibn, 15);
                if(deleteByIsbn(&first, ibn)){
                    printf("Delete book with isbn: %s complete!\n", ibn);
                }else{
                    printf("Not found book with isbn: %s\n", ibn);
                }
                waitEnterPress("Press Enter go to main menu...");
                break;
            case 5:
                printf("Number of books: %d\n", count(first));
                printListBooks(first);
                waitEnterPress("Press Enter go to main menu...");
                break;
            default:
                printf("Exit Apps\n");
        }
    }while(yourChoice!=topMenuItems);

    return 0;
}
void printListBooks(ListBook* first){
    ListBook* current = first;
    printTitle();
    while(current != NULL){
        printBook(current->book);
        current = current->next;
    }
    printLine();
}
ListBook* getAtIndex(ListBook* first, int index){
    ListBook* it = first;
    for(int i=0; i<index; i++, it=it->next);
    return it;
}
ListBook* searchByIsbn(ListBook* first, char* ibn){
    ListBook* it = first;
    for(; it!=NULL; it=it->next){
        if(strcmp(it->book.isbn, ibn)==0){
            break;
        }
    }
    return it;
}
int count(ListBook* first){
    int i = 0;
    ListBook* it = first;
    while(it != NULL){
        i++;
        it = it->next;
    }
    return i;
}
int addToFirst(ListBook** first, ListBook* newBook){
    if(first == NULL){
        return 0;
    }
    newBook->next = *first;
    *first = newBook;
    return 1;
}
int addToLast(ListBook** first, ListBook* newBook){
    if(first == NULL){
        return 0;
    }
    newBook->next = NULL;
    if(*first == NULL){
        *first = newBook;
    }else{
        ListBook *last = *first;
        while(last->next != NULL){
            last = last->next;
        }
        last->next = newBook;
    }
    return 1;
}
int insert(ListBook** first, ListBook* newBook, int atIndex){
    if(first == NULL || *first == NULL || atIndex<0 || atIndex >= count(*first)){
        return 0;
    }
    if(atIndex == 0){
        return addToFirst(first, newBook);
    }
    ListBook* current = getAtIndex(*first, atIndex-1);
    if(current != NULL){
        ListBook *nextItem = current->next;
        current->next = newBook;
        newBook->next = nextItem;
        return 1;
    }
    return 0;
}
int deleteByIsbn(ListBook** first, char* ibn){
    ListBook* current = *first;
    ListBook* pre = *first;
    while(current != NULL){
        if(strcmp(current->book.isbn, ibn)==0){
            break;
        }
        pre = current;
        current = current->next;
    }
    if(current != NULL){
        if(current == pre){
            *first = current->next;
        }else{
            pre->next = current->next;
        }
        //free memory current element
        free(current);
        return 1;
    }
    return 0;
}
int inputListBook(ListBook* lb){
    clearCache();
    printf("Input Book isbn: ");
    getString(lb->book.isbn, 14);
    printf("Input Book title: ");
    getString(lb->book.title, 50);
    printf("Input Book author: ");
    getString(lb->book.author, 50);
    printf("Input Book price: ");
    scanf("%f", &(lb->book.price));
    return 1;
}
Books getBook(){
    Books book;
    printf("Input Book isbn: ");
    getString(book.isbn, 14);
    printf("Input Book title: ");
    getString(book.title, 50);
    printf("Input Book author: ");
    getString(book.author, 50);
    printf("Input Book price: ");
    scanf("%f", &book.price);
    return book;
}
void printBook(Books book){
    printf( "| %-14s | %-26s | %-20s | %6.2f |\n",
           book.isbn, book.title, book.author, book.price);
}
void printLine(){
    printf( "+-%-14s-+-%-26s-+-%-20s-+-%-6s-+\n", "--------------",
        "--------------------------", "--------------------", "------");
}
void printTitle(){
    printLine();
    printf( "| %-14s | %-26s | %-20s | %-6s |\n", "ISBN", "Title",
        "Author", "Price");
    printLine();
}
void getString(char *str, int length){
    clearCache();
    //input string
    fgets(str, length, stdin);
    str[strlen(str)-1] = '\0';
    clearCache();
}
int menu(int menuItemCount, char *menuItem[]){
    int i=0, choice;
    printf("==============================\n");
    printf(" MENU\n");
    printf("==============================\n");
    for(; i<menuItemCount; i++){
        printf(" %d. %s \n", i+1, menuItem[i]);
    }
    printf("==============================\n");
    do{
        printf("Your choice: ");
        clearCache();
        scanf("%d", &choice);
    }while(choice<=0 || choice>menuItemCount);
    return choice;
}
void clearCache(){
    //clear keyboard buffer on UNIX
    fseek(stdin, 0, SEEK_END);
    //clear keyboard buffer on Windows
    fflush(stdin);
}
void waitEnterPress(char* msg){
    printf("%s\n", msg);
    clearCache();
    getchar();
}