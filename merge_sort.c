#include <stdio.h>

int main() {
    int a[5] = {23, 1, 10, 5, 2};
    int n = 5;

    int temp[5];
    int size, left, mid, right;
    int i, j, k;

    // size = current subarray size (1, 2, 4, ...)
    for (size = 1; size < n; size = size * 2) {

        // pick starting point of left subarray
        for (left = 0; left < n - size; left = left + 2 * size) {

            mid = left + size - 1;

            // calculate right end
            if (left + 2 * size - 1 < n - 1)
                right = left + 2 * size - 1;
            else
                right = n - 1;

            // merge the two subarrays
            i = left;
            j = mid + 1;
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
    }

    // print sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}