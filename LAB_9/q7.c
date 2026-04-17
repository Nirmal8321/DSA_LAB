#include <stdio.h>

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int get_max(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > mx) mx = arr[i];
    }
    return mx;
}

void counting_sort(int arr[], int n, int exp) {
    int output[100];
    int count[10] = {0};

    for (int i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        int idx = (arr[i] / exp) % 10;
        output[count[idx] - 1] = arr[i];
        count[idx]--;
    }
    for (int i = 0; i < n; i++) arr[i] = output[i];
}

void radix_sort(int arr[], int n) {
    int max = get_max(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        counting_sort(arr, n, exp);
    }
}

int main(void) {
    int arr[] = {40, 60, 1, 200, 9, 83, 17};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));
    radix_sort(arr, n);
    print_array(arr, n);
    return 0;
}
