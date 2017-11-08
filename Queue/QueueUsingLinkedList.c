#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int value;
    struct Queue *next;
};
struct Queue{
    struct Node* front;
    struct Node* rear;
};

int main(int countArgs, char** args){

    return 0;
}