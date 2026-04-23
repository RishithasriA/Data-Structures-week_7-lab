#include <stdio.h>
int main(){
    // initial unsorted array
    int a[5]={23,1,10,5,2};
    int i,j,key;
    int n = 5;
    // loop through all elements starting from index 1
    //(Assume first elememt is sorted)
    for(i=0;i<n;i++){
        key = a[i];  //take the curent element as key
        //compare with previous elements
        j=i-1;
        //shift elements to the right until correct position is found
        while(j>=0&&a[j]>key){
            a[j+1]=a[j];
            j=j-1;
        }
        //place the key in itscorect position
        a[j+1]=key;
    }
       // print the sorted array
       printf("Sorted array:\n");
       for(i=0;i<n;i++){
        printf("%d ",a[i]);
       }
    return 0;
}