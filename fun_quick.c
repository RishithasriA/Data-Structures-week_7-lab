#include <stdio.h>

// function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// function to partition the array
int partition(int a[], int low, int high) {
    int pivot = a[high];   // choose last element as pivot
    int i = low - 1;
    int j;

    for (j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[i + 1], &a[high]);
    return i + 1;
}

// quick sort function
void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);

        quickSort(a, low, pi - 1);   // left side
        quickSort(a, pi + 1, high);  // right side
    }
}

int main() {
    int a[5] = {23, 1, 10, 5, 2};
    int n = 5;
    int i;

    quickSort(a, 0, n - 1);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}