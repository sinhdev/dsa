#include <stdio.h>

void selectionSort(int* a, int itemsCount);

int main(int countArgs, char** args){
    int a[] = {14,33,27,10,35,19,42,44};
    selectionSort(a, 8);
    for(int i=0; i<8; i++){
        printf("%d  ", a[i]);
    }
    return 0;
}

void selectionSort(int* a, int itemsCount){
    int minIndex, temp;
    for(int i=0; i<itemsCount-1; i++){
        minIndex = i;
        for(int j=i+1; j<itemsCount; j++){
            if(a[minIndex]>a[j]){
                minIndex = j;
            }
        }
        if(minIndex>i){
            temp = a[minIndex];
            a[minIndex] = a[i];
            a[i] = temp;
        }
    }
}