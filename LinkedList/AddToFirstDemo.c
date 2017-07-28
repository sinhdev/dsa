#include <stdio.h>
#include <stdlib.h>

struct sLinkedList{
    int value;
    struct sLinkedList * next;
};
typedef struct sLinkedList LinkedList;

LinkedList* addToHead(LinkedList *newElement, LinkedList *head);

int main(int count, const char* args[]){
    LinkedList *head;
    head = NULL;

    //cap phat 1 phan tu
    LinkedList* newE1 = (LinkedList*)malloc(sizeof(LinkedList));
    newE1->value = 5;
    head = addToHead(newE1, head);

    LinkedList* newE2 = (LinkedList*)malloc(sizeof(LinkedList));
    newE2->value = 8;
    head = addToHead(newE2, head);

    LinkedList* newE3 = (LinkedList*)malloc(sizeof(LinkedList));
    newE3->value = 9;
    head = addToHead(newE3, head);

    //hien thi du lieu
    LinkedList *iterator;
    iterator = head;
    while(iterator != NULL){
        LinkedList e = *iterator;
        printf("|value:%d|next|->", e.value);
        iterator = e.next;
    }
    printf("NULL");
    return 0;
}

LinkedList* addToHead(LinkedList *newElement, LinkedList *head){
    if(head==NULL){
        newElement->next = NULL;
    }else{
        newElement->next = head;
    }
    head = newElement;
    return head;
}