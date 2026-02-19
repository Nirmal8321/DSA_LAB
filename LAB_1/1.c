#include <stdio.h>

int main() {
    int arr[2][2];

    // Input elements
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Enter the number for (%d,%d) in array: ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }

    // Print elements
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("The number at (%d,%d) in array is %d\n",
                   i + 1, j + 1, arr[i][j]);
        }
    }

    return 0;
}
