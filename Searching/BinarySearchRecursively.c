#include <stdio.h>

int binarySearchRecursively(int* data, int searchValue, int highIndex, int lowIndex);

int main(int countArgs, char** args){
    int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int search = 11;

    int found = binarySearchRecursively(a, 0, 20, search);
    printf("found index: %d\n", found);

    return 0;
}

int binarySearchRecursively(int* data, int lowIndex, int highIndex, int searchValue){
    if(lowIndex>=highIndex){
        return -1;
    }
    int mid = (highIndex + lowIndex) / 2;
    if(data[mid]==searchValue){
        return mid;
    }else if(data[mid]>searchValue){
        return binarySearchRecursively(data, lowIndex, mid-1, searchValue);
    }else{
        return binarySearchRecursively(data, mid+1, highIndex, searchValue);
    }
}