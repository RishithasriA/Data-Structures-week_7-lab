#include <stdio.h>

int main() {
    int a[5] = {23, 1, 10, 5, 2};
    int n = 5;

    int stack[10];
    int top = -1;

    int low = 0, high = n - 1;

    // push initial values
    stack[++top] = low;
    stack[++top] = high;

    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];

        int pivot = a[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (a[j] < pivot) {
                i++;
                // swap
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        // place pivot in correct position
        int temp = a[i + 1];
        a[i + 1] = a[high];
        a[high] = temp;

        int pi = i + 1;

        // push left side
        if (pi - 1 > low) {
            stack[++top] = low;
            stack[++top] = pi - 1;
        }

        // push right side
        if (pi + 1 < high) {
            stack[++top] = pi + 1;
            stack[++top] = high;
        }
    }

    // print sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}