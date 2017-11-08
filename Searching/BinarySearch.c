#include <stdio.h>

int binarySearch(int* data, int dataSize, int searchValue);

int main(int countArgs, char** args){

    return 0;
}

int binarySearch(int* data, int dataSize, int searchValue){
    int fIndex = -1;
    int low = 0, hi = dataSize-1, mid;
    while(low <= hi){
    	if(data[low] == searchValue){
    		fIndex = low;
    		break;
    	}
    	if(data[hi] == searchValue){
    		fIndex = hi;
    		break;
    	}
    	
    	mid = (hi + low) / 2;
    	if(data[mid] == searchValue){
    		fIndex = mid;
    		break;
    	} else if(searchValue < data[mid]){
    		hi = mid - 1;
    	} else {
    		low = mid + 1;
    	}
    }
    return fIndex;
}