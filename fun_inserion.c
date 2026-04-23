#include <stdio.h>

// function to perform insertion sort
void insertionSort(int a[], int n) {
    int i, j, key;

    for(i = 1; i < n; i++) {   // start from index 1
        key = a[i];
        j = i - 1;

        while(j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }

        a[j + 1] = key;
    }
}

// function to print array
void printArray(int a[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[5] = {23, 1, 10, 5, 2};
    int n = 5;

    insertionSort(a, n);

    printf("Sorted array:\n");
    printArray(a, n);

    return 0;
}