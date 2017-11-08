#include <stdio.h>

void bubbleSort(int* a, int itemsCount);

int main(int countArgs, char** args){
    int a[] = {14,33,27,10,35,19,42,44};
    bubbleSort(a, 8);
    for(int i=0; i<8; i++){
        printf("%d  ", a[i]);
    }
    printf("\n");
    return 0;
}

void bubbleSort(int* a, int itemsCount){
    int temp;
    for(int i=0; i<itemsCount-1; i++){
        for(int j=0; j<itemsCount-1-i; j++){
            if(a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}