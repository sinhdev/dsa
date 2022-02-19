#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node * next;
} intLinkedList;

int insertToHead();
void display(intLinkedList *head);
void displayForLoop(intLinkedList *head);
bool deleteFromHead(intLinkedList **head);
bool delete(int value, intLinkedList **head);
int indexOf(int value, intLinkedList *head);
int menu(const char* title, int menuItemCount, char *menuItem[]);
void clearKeyboardBuffer();

int main(int argCount, char* args[]){
    int mainMenuChoice;
    char* mainMenu[] = {"Insert to head", "Delete", "Display", "Search Element", "Delete by position", "Exit"};
    intLinkedList* head;
    head = NULL;
    int value;
    do{
        mainMenuChoice = menu("Linked List Demo", 6, mainMenu);
        switch(mainMenuChoice){
            case 1:
                printf("Input new Value to Linked List: ");
                scanf("%d", &value);
                insertToHead(value, &head);
                break;
            case 2:
                printf("Input new Value to delete: ");
                scanf("%d", &value);
                if(delete(value, &head)){
                    printf("%d removed from linked list\n", value);
                }else{
                    printf("%d not in linked list\n", value);
                }
                break;
            case 3:
                //display(head);
                displayForLoop(head);
                break;
            case 4:
                printf("Input value to search: ");
                scanf("%d", &value);
                int found = indexOf(value, head);
                if(found<0){
                    printf("%d isn't in Linked List\n", value);
                }else{
                    printf("%d is in linked list at %d position\n", value, found);
                }
                break;
        }
        printf("Press enter key to continue...");
        clearKeyboardBuffer();
        getchar();
    }while(mainMenuChoice!=6);
}

int insertToHead(int value, intLinkedList** head){
    intLinkedList *newElement;
    //allocate memory for new element
    newElement = (intLinkedList*)malloc(sizeof(intLinkedList));
    //assign new element value for value parameter
    newElement->data = value;
    //step 1: assign next new element for head element
    newElement->next = *head;
    //step 2: assign head element for new element
    *head = newElement;
    return 1;
}

void display(intLinkedList *head){
    intLinkedList *iterator;
    iterator = head;
    while(iterator != NULL){
        printf("|data:%d|->", iterator->data);
        iterator = iterator->next;
    }
    printf("NULL\n");
}
void displayForLoop(intLinkedList *head){
    intLinkedList *iterator;
    for(iterator=head; iterator!=NULL; iterator=iterator->next){
        printf("|data:%d|->", iterator->data);
    }
    printf("NULL\n");
}
bool deleteFromHead(intLinkedList **head){
    //check Linked List don't have any element -> can't delete
    if(*head == NULL){
        return false;
    }
    //get delete element (first element)
    intLinkedList *del;
    del = *head;
    //step 1: move head element to next head element
    *head = del->next;
    //step 2: free memory deleted element
    free(del);
    return true;
}
bool delete(int value, intLinkedList **head){
    intLinkedList *current;
    intLinkedList *pre;
    current = *head;
    pre = *head;
    bool deleted = false;
    while(current != NULL){
        if(current->data == value){
            deleted = true;
            if(current==*head){
                //delete head
                deleteFromHead(head);
                current = *head;
                pre = *head;
            }else{
                //delete not head
                //step 1: assign next pre element for after deleted element
                pre->next = current->next;
                //step 2: free memory deleted element
                free(current);
                current = pre->next;
            }
            //continue to delete the same element value
            continue;
        }
        pre = current;
        current = current->next;
    }
    return deleted;
}

int indexOf(int value, intLinkedList *head){
    intLinkedList *iterator;
    int i;
    for(iterator=head, i=0; iterator!=NULL; iterator=iterator->next, i++){
        if(iterator->data==value){
            return i;
        }
    }
    //not found value
    return -1;
}

int menu(const char* title, int menuItemCount, char *menuItem[]){
    int i=0, choice;
    printf("\n==============================\n");
    printf(" %s\n", title);
    printf("==============================\n");
    for(; i<menuItemCount; i++){
        printf(" %d. %s \n", i+1, menuItem[i]);
    }
    printf("==============================\n");
    do{
        printf("Your choice: ");
        clearKeyboardBuffer();
        scanf("%d", &choice);
    }while(choice<=0 || choice>menuItemCount);
    return choice;
}
void clearKeyboardBuffer(){
    //clear keyboard buffer on UNIX
    fseek(stdin, 0, SEEK_END);
    //clear keyboard buffer on Windows
    fflush(stdin);
}