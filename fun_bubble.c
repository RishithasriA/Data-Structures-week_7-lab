#include <stdio.h>

// function for bubble sort
void bubbleSort(int a[], int n) {
    int i, j, temp;

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - 1 - i; j++) {  // optimized version
            if(a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// function to print array
void printArray(int a[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

int main() {
    int a[5] = {5, 3, 8, 4, 2};
    int n = 5;

    bubbleSort(a, n);   // function call

    printf("Sorted array:\n");
    printArray(a, n);   // function call

    return 0;
}