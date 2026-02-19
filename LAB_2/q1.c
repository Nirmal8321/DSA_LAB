#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x) {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = x;
    n->next = top;
    top = n;
}

void pop() {
    if (top == NULL)
        return;
    struct node *t = top;
    top = top->next;
    free(t);
}

void peek() {
    if (top != NULL)
        printf("%d\n", top->data);
}

void display() {
    struct node *t = top;
    while (t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    peek();
    pop();
    display();
    return 0;
}
