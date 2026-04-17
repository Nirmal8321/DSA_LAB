#include <stdio.h>

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

int main(void) {
    int arr[] = {40, 60, 1, 200, 9, 83, 17};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));
    bubble_sort(arr, n);
    print_array(arr, n);
    return 0;
}
