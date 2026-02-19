#include <stdio.h>

int main() {
    int a = 5;                 // primitive
    int arr[5] = {1,2,3,4,5};  // non-primitive

    printf("Primitive value: %d\n", a);
    printf("Primitive address: %p\n", &a);
    printf("Primitive size: %zu bytes\n", sizeof(a));

    printf("\nNon-primitive first value: %d\n", arr[0]);
    printf("Non-primitive address: %p\n", arr);
    printf("Non-primitive size: %zu bytes\n", sizeof(arr));

    return 0;
}
