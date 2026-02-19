#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    int n, d[20], i = 0;
    scanf("%d", &n);

    while (n > 0) {
        d[i++] = n % 10;
        n /= 10;
    }

    struct node *head = NULL, *tail = NULL;

    for (int j = i - 1; j >= 0; j--) {
        struct node *t = (struct node *)malloc(sizeof(struct node));
        t->data = d[j];
        t->next = NULL;

        if (head == NULL) {
            head = tail = t;
        } else {
            tail->next = t;
            tail = t;
        }
    }

    struct node *p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }

    return 0;
}
