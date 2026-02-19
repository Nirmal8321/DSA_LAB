#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, key;
    printf("Enter number of elements: ");
    scanf("%d", &size);

    int *ptr = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", ptr + i);
    }

    printf("Enter number to search: ");
    scanf("%d", &key);

    int found = 0;
    for (int i = 0; i < size; i++) {
        if (*(ptr + i) == key) {
            printf("Element found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Element not found\n");

    free(ptr);
    return 0;
}
