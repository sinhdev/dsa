#include <stdio.h>
#include <stdlib.h>

struct stack{
    int value;
    struct stack *next;
};
typedef struct stack Stack;
//function declaration
int push(Stack** first, int newValue);
int pop(Stack** first);
Stack* convertToBinary(int decimalNumber);
void printAndRemoveStack(Stack* binaryStack);

int main(int count, const char* args[]){
    int decimal;
    printf("Input an integer number: ");
    scanf("%d", &decimal);
    Stack* binaryStack = convertToBinary(decimal);
    printAndRemoveStack(binaryStack);
    return 0;
}
Stack* convertToBinary(int decimalNumber){
    Stack *stack = NULL;
    int mod;
    while(decimalNumber >0){
        push(&stack, decimalNumber %  2);
        decimalNumber /= 2;
    }
    return stack;
}
void printAndRemoveStack(Stack* binaryStack){
    printf("Binary number: ");
    int i=1;
    while(binaryStack != NULL){
        if(i%4 == 0){
            printf(" ");
        }
        printf("%d", pop(&binaryStack));
        i++;
    }
    printf("\n");
}
int push(Stack** first, int newValue){
    if(first == NULL && *first == NULL){
        return 0;
    }
    Stack* newElement = (Stack*)malloc(sizeof(Stack));
    newElement->value = newValue;
    newElement->next = *first;
    *first = newElement;
    return 1;
}
int pop(Stack** first){
    Stack* firstElement = *first;
    *first = firstElement->next;
    int iValue = firstElement->value;
    free(firstElement);
    firstElement = NULL;
    return iValue;
}