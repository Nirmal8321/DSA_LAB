#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, sum = 0;
    printf("Enter number of elements: ");
    scanf("%d", &size);

    int *ptr = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }

    printf("Average = %.2f\n", (float)sum / size);

    free(ptr);
    return 0;
}
