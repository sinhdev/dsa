#include <stdio.h>

unsigned long factorial(unsigned int index);

int main(int count, char* args[]){
    unsigned int num;
    printf("Input number of factorial series: ");
    scanf("%d", &num);
    printf("%d! = %lu\n", num, factorial(num));
    return 0;
}

unsigned long factorial(unsigned int index){
    if(index==0 || index==1){
        return 1;
    }
    return index*factorial(index-1);
}