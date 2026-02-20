#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *tail = NULL;
    struct node *prev = NULL, *curr, *next;
    int n, i, val;

    scanf(&quot;%d&quot;, &amp;n);

    for(i = 0; i &lt; n; i++) {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        scanf(&quot;%d&quot;, &amp;val);
        newnode-&gt;data = val;
        newnode-&gt;next = NULL;

        if(head == NULL) {
            head = tail = newnode;
        } else {
            tail-&gt;next = newnode;
            tail = newnode;
        }
    }

    curr = head;
    while(curr != NULL) {
        next = curr-&gt;next;
        curr-&gt;next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;

    while(head != NULL) {
        printf(&quot;%d &quot;, head-&gt;data);
        head = head-&gt;next;
    }

    return 0;
}