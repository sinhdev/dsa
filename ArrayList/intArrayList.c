#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct IntArrayList{
    int *a;
    int count;
    int maxCount;
};

int menu(const char* title, int menuItemCount, char *menuItem[]);
void clearKeyboardBuffer();

int initArrayList(struct IntArrayList *intArrayList, int maxElement);
bool insert(struct IntArrayList *intArrayList, int e, int position);
bool removeElement(struct IntArrayList *intArrayList, int e);
int find(struct IntArrayList intArrayList, int e);
int findKth(struct IntArrayList intArrayList, int k);
bool isEmpty(struct IntArrayList intArrayList);
void makeEmpty(struct IntArrayList *intArrayList);

int main(int argCount, char* args[]){
    struct IntArrayList intArrayList;
    int mainMenuChoice;
    int e, position;
    char yn;
    char* mainMenu[] = {"Init Array List", "Insert", "Update", "Delete", "Display Array List", "Find Element", "Get Element", "Check Empty", "Exit"};
    initArrayList(&intArrayList, 16);
    do{
        mainMenuChoice = menu("int Array List Demo", 9, mainMenu);
        switch(mainMenuChoice){
            case 1:
                initArrayList(&intArrayList, 16);
                break;
            case 2:
                printf("input element value: ");
                scanf("%d", &e);
                printf("input position to insert: ");
                scanf("%d", &position);
                if(insert(&intArrayList, e, position)){
                    printf("Insert complelte!\n");
                }else {
                    printf("Can't insert %d to Array List at position %d\n", e, position);
                }
                break;
            case 3:
                printf("input position to update: ");
                scanf("%d", &position);
                if(position<0 || position>=intArrayList.count){
                    printf("invalid position!!!\n");
                }else{
                    printf("old value: %d\ninput new value: ", intArrayList.a[position]);
                    scanf("%d", &(intArrayList.a[position]));
                }
                break;
            case 4:
                printf("input element to remove: ");
                scanf("%d", &e);
                if(removeElement(&intArrayList, e)){
                    printf("Remove element complete!!!\n");
                }else{
                    printf("Don't have %d in Array List!!!\n", e);
                }
                break;
            case 5:
                for(int i=0; i<intArrayList.count; i++){
                    printf("%d  ", intArrayList.a[i]);
                }
                printf("\n");
                break;
            case 6:
                printf("input element to find: ");
                scanf("%d", &e);
                int found = find(intArrayList, e);
                if(found<0){
                    printf("%d not in Array List!!!\n", e);
                }else{
                    printf("%d found at position %d in ArrayList!\n", e, found);
                }
                break;
            case 7:
                printf("input position: ");
                scanf("%d", &position);
                if(position<0 || position>=intArrayList.count){
                    printf("invalid position!!!\n");
                }else{
                    printf("Value of element at position %d is: %d\n", position, findKth(intArrayList, position));
                }
                break;
            case 8:
                if(isEmpty(intArrayList)){
                    printf("Array List is Empty!!!\n");
                }else{
                    printf("Array List isn't Empty!!!\n");
                    printf("max element: %d\n", intArrayList.maxCount);
                }
                break;
        }
    }while(mainMenuChoice != 9);
    makeEmpty(&intArrayList);
    return 0;
}

int initArrayList(struct IntArrayList *intArrayList, int maxElement){
    intArrayList->count = 0;
    intArrayList->maxCount = maxElement;
    intArrayList->a = (int*)malloc(sizeof(int)*maxElement);
    return 1;
}
bool insert(struct IntArrayList *intArrayList, int e, int position){
    if(position < 0 || position > intArrayList->count){
        return false;
    }
    if(intArrayList->count == intArrayList->maxCount){
        intArrayList->maxCount = intArrayList->maxCount + intArrayList->maxCount/2;
        intArrayList->a = (int*)realloc(intArrayList->a, sizeof(int)*intArrayList->maxCount);
    } 
    for(int i=intArrayList->count; i>position; i--){
        intArrayList->a[i] = intArrayList->a[i-1];
    }
    intArrayList->a[position] = e;
    intArrayList->count++;
    return true;
}
bool removeElement(struct IntArrayList *intArrayList, int e){
    bool complete = false;
    for(int i=0; i<intArrayList->count; i++){
        if(intArrayList->a[i] == e){
            for(int j=i; j<intArrayList->count;j++){
                intArrayList->a[j] = intArrayList->a[j+1];
            }
            intArrayList->count--;
            complete = true;
        }
    }
    return complete;
}
int find(struct IntArrayList intArrayList, int e){
    for(int i=0; i<intArrayList.count; i++){
        if(intArrayList.a[i] == e){
            return i;
        }
    }
    return -1;
}
int findKth(struct IntArrayList intArrayList, int k){
    return intArrayList.a[k];
}
bool isEmpty(struct IntArrayList intArrayList){
    return intArrayList.count == 0;
}
void makeEmpty(struct IntArrayList *intArrayList){
    if(intArrayList->count>0){
        intArrayList->maxCount = 0;
        intArrayList->count = 0;
        free(intArrayList->a);
    }
}
int menu(const char* title, int menuItemCount, char *menuItem[]){
    int i=0, choice;
    printf("==============================\n");
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