#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *tail = NULL;
    int a[] = {2, 3, 5};

    for (int i = 0; i < 3; i++) {
        struct node *t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = NULL;

        if (head == NULL) {
            head = tail = t;
        } else {
            tail->next = t;
            tail = t;
        }
    }

    struct node *prev = NULL, *cur = head, *next;

    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    head = prev;
    struct node *p = head;

    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }

    return 0;
}
