#include <stdio.h>

unsigned long fibonacci(unsigned int index);

int main(int count, char* args[]){
    unsigned int num;
    printf("Input number of fibonacci series: ");
    scanf("%d", &num);
    printf("Fibonacci series: ");
    for(int i=1; i<=num; i++){
        printf("%lu, ", fibonacci(i));
    }
    printf("\n");
    return 0;
}

unsigned long fibonacci(unsigned int index){
    if(index==1 || index==2){
        return 1;
    }
    return fibonacci(index-1) + fibonacci(index-2);
}