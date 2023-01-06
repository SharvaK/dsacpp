#include<iostream>
using namespace std;

int binarysearch(int array[],int x, int low, int high){
    if (high >= low)
    {
        int mid  = low + (high - low) / 2 ;

        //found at mid
        if(array[mid] == x)
           return mid ;

        //search left half
        if(array[mid] > x)
        return binarysearch(array,x,mid -1,mid);

        //search right half
        if(array[mid] < x)
        return binarysearch(array,x,mid+1,high);   
    }
    return -1 ;
}
int main(void){
     int array[] = {3, 4, 5, 6, 7, 8, 9};
     int x = 4;
     int n = sizeof(array) / sizeof(array[0]);
     int result = binarysearch(array, x, 0, n - 1);
     if (result == -1)
       printf("Not found");
     else
       printf("Element is found at index %d", result);
}


