#include <stdio.h>

int main() {
    int arr[3][3] = {
        {1,2,3},
        {5,6,8},
        {10,45,67}
    };

    int i = 1, j = 2;
    int base = (int)&arr[0][0];
    int size = sizeof(int);
    int rows = 3, cols = 3;

    int row_major = base + size * (i * cols + j);
    int col_major = base + size * (j * rows + i);

    printf("Element arr[1][2]\n");
    printf("Row-Major Address: %d\n", row_major);
    printf("Column-Major Address: %d\n", col_major);
    printf("Actual Address: %d\n", (int)&arr[1][2]);

    return 0;
}
