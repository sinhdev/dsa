#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack{
    int *data;
    int max;
    int top;
};

bool initStack(struct Stack* stack, int maxElement);
bool push(struct Stack* stack, int value);
bool pop(struct Stack* stack, int* topValue);
bool peek(struct Stack stack, int* topValue);
bool isFull(struct Stack stack);
bool isEmpty(struct Stack stack);

int main(int countArgs, char** args){
    struct Stack s;
    //init stack
    initStack(&s, 16);

    //push data
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);

    int topElement;
    /*
    while(s.top >= 0){
        if(pop(&s, &topElement)){
            printf("%d\n", topElement);
        }
    }*/
    while(pop(&s, &topElement)){
        printf("%d\n", topElement);
    }
    return 0;
}

bool initStack(struct Stack* stack, int maxElement){
    stack->data = (int*)malloc(sizeof(int)*maxElement);
    stack->max = maxElement;
    stack->top = -1;
    return true;
}
bool push(struct Stack* stack, int value){
    //Step 1 − Checks if the stack is full    
    if(stack->top == stack->max){
        //Step 2 − If the stack is full, produces an error and exit
        return false;
    }
    //Step 3 − If the stack is not full, increments top to point next empty space
    stack->top += 1;
    //Step 4 − Adds data element to the stack location, where top is pointing
    stack->data[stack->top] = value;
    //Step 5 − Returns success
    return true;
}

bool pop(struct Stack* stack, int* topValue){
    //Step 1 − Checks if the stack is empty.
    if(stack->top < 0){
        //Step 2 − If the stack is empty, produces an error and exit.
        return false;
    }
    //Step 3 − If the stack is not empty, accesses the data element at which top is pointing.
    *topValue = stack->data[stack->top];
    //Step 4 − Decreases the value of top by 1
    stack->top -= 1;
    //Step 5 − Returns success.
    return true;
}

bool peek(struct Stack stack, int* topValue){
    if(stack.top < 0){
        return false;
    }
    *topValue = stack.data[stack.top];
    return true;
}
bool isFull(struct Stack stack){
    return stack.top == stack.max;
}
bool isEmpty(struct Stack stack){
    return stack.top<0;
}