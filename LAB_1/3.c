#include <stdio.h>

int main() {
    int matrix[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Value at (%d,%d) is %d\n",
                   i + 1, j + 1, matrix[i][j]);
        }
    }

    printf("\nMemory Addresses:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Address of (%d,%d) is %p\n",
                   i + 1, j + 1, &matrix[i][j]);
        }
    }

    return 0;
}
