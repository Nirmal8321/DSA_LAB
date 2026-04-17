#include <stdio.h>

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        int t = arr[i];
        arr[i] = arr[largest];
        arr[largest] = t;
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        int t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;
        heapify(arr, i, 0);
    }
}

int main(void) {
    int arr[] = {40, 60, 1, 200, 9, 83, 17};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));
    heap_sort(arr, n);
    print_array(arr, n);
    return 0;
}
