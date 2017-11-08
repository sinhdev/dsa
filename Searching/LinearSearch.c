#include <stdio.h>

int linearSearch(int* data, int dataSize, int searchValue);

int main(int countArgs, char** args){

    return 0;
}

int linearSearch(int* data, int dataSize, int searchValue){
    for(int i=0; i<dataSize; i++){
        if(data[i]==searchValue){
            return i;
        }
    }
    return -1;
}