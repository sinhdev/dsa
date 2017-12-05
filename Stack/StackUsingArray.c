#include <stdio.h>

struct stack{
    int data[50];
    int maxIndex;
    int topIndex;
};

int push(int value, struct stack *s);
int pop(int *topValue, struct stack *s);

int main(int count, char **args){
    //init myStack
    struct stack myStack;
    myStack.maxIndex = 49;
    myStack.topIndex = -1;

    push(1, &myStack);
    push(2, &myStack);
    push(3, &myStack);
    push(4, &myStack);
    push(5, &myStack);

    int top;
    while(pop(&top, &myStack)){
        printf("%d | ", top);
    }
    return 0;
}
int pop(int *topValue, struct stack *s){
    //Step 1:
    if(s->topIndex == -1){
        //Step 2:
        return 0;
    }
    //Step 3:
    *topValue = s->data[s->topIndex];
    //Step 4:
    s->topIndex -= 1;
    //Step 5:
    return 1;
}
int push(int value, struct stack *s){
    //Step 1:
    if(s->maxIndex == s->topIndex){
        //Step 2:
        return 0;
    }
    //Step 3:
    s->topIndex += 1;
    //Step 4:
    s->data[s->topIndex] = value;
    //Step 5:
    return 1;
}