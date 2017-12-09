#include <stdio.h>
// sort animation compare: https://www.toptal.com/developers/sorting-algorithms
// sort animation: https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html
void quickSort(int* a, int left, int right);
int partition(int *a, int left, int right, int pivot);
void swap(int *a, int *b);

int main(int countArgs, char** args){
    int a[] = {14,33,27,10,35,19,42,44};
    quickSort(a, 0, 7);
    for(int i=0; i<8; i++){
        printf("%d  ", a[i]);
    }
    printf("\n");
    return 0;
}

void quickSort(int* a, int left, int right){
    if(right<=left){
        return;
    }
    int pivot = a[right];
    int partitionIndex = partition(a, left, right, pivot);
    
    // swap(a+right, a+partitionIndex);
    a[right] = a[partitionIndex];
    a[partitionIndex] = pivot;

    quickSort(a, left, partitionIndex-1);
    quickSort(a, partitionIndex+1, right);
}

int partition(int *a, int left, int right, int pivot){
    int leftIndex = left - 1;
    int rightIndex = right;
    int temp;
    while(1){
        while(a[++leftIndex]< pivot);
        while(rightIndex>0 && a[--rightIndex] > pivot);
        if(leftIndex >= rightIndex) {
            break;
        }else{
            //swap(a+leftIndex, a+rightIndex);
            temp = a[leftIndex];
            a[leftIndex] = a[rightIndex];
            a[rightIndex] = temp;
        }
    }
    return leftIndex;
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}