#include <stdio.h>

// function to merge two subarrays
void merge(int a[], int left, int mid, int right) {
    int i = left, j = mid + 1, k;
    int temp[100];  // temporary array

    k = left;

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = a[i++];
    }

    while (j <= right) {
        temp[k++] = a[j++];
    }

    // copy back to original array
    for (i = left; i <= right; i++) {
        a[i] = temp[i];
    }
}

// recursive merge sort function
void mergeSort(int a[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(a, left, mid);       // sort left half
        mergeSort(a, mid + 1, right);  // sort right half

        merge(a, left, mid, right);    // merge both halves
    }
}

int main() {
    int a[5] = {23, 1, 10, 5, 2};
    int n = 5;
    int i;

    mergeSort(a, 0, n - 1);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}