#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    printf("Enter number of elements: ");
    scanf("%d", &size);

    int *ptr = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", ptr + i);
    }

    int max = *ptr, min = *ptr;

    for (int i = 0; i < size; i++) {
        if (*(ptr + i) > max)
            max = *(ptr + i);
        if (*(ptr + i) < min)
            min = *(ptr + i);
    }

    printf("Maximum value = %d\n", max);
    printf("Minimum value = %d\n", min);

    free(ptr);
    return 0;
}
