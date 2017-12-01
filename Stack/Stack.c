#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack{
    int *data;
    int max;
    int top;
};

bool initStack(struct stack *s, unsigned int maxElements);
bool push(struct stack* s, int value);
bool pop(struct stack *s, int *topValue);

int main(int count, char** args){
    //init stack
    struct stack myStack;
    initStack(&myStack, 16);

    //push data to myStack
    push(&myStack, 5);
    push(&myStack, 6);
    push(&myStack, 7);
    push(&myStack, 8);

    int topElement;
    //pop operation
    while(pop(&myStack, &topElement)){
        printf("%d\n", topElement);
    }

    return 0;
}

bool initStack(struct stack *s, unsigned int maxElements){
    s->data = (int *)malloc(sizeof(int)*maxElements);
    s->max = maxElements - 1;
    s->top = -1;
}
bool push(struct stack* s, int value){
    //Step 1:
    if(s->top==s->max){
        //Step 2:
        return false;
    }
    //Step 3:
    s->top += 1;
    //Step 4:
    s->data[s->top] = value;
    //Step 5:
    return true;
}
bool pop(struct stack *s, int *topValue){
    //Step 1:
    if(s->top < 0){
        //Step 2:
        return false;
    }
    //Step 3:
    *topValue = s->data[s->top];
    //Step 4:
    s->top -= 1;
    //Step 5:
    return true;
}