#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    printf("Enter number of elements: ");
    scanf("%d", &size);

    int *ptr = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        printf("Enter value for element %d: ", i + 1);
        scanf("%d", ptr + i);
    }

    for (int i = 0; i < size; i++) {
        printf("Element %d = %d\n", i + 1, *(ptr + i));
    }

    free(ptr);
    return 0;
}
