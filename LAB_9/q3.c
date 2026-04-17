#include <stdio.h>

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main(void) {
    int arr[] = {40, 60, 1, 200, 9, 83, 17};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));
    insertion_sort(arr, n);
    print_array(arr, n);
    return 0;
}
