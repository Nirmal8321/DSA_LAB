#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *tail = NULL, *newnode;
    int n, val, newval;

    scanf(&quot;%d&quot;, &amp;n);

    while(n--) {
        scanf(&quot;%d&quot;, &amp;val);
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode-&gt;data = val;
        newnode-&gt;next = NULL;

        if(head == NULL) {
            head = tail = newnode;
        } else {
            tail-&gt;next = newnode;
            tail = newnode;
        }
    }

    scanf(&quot;%d&quot;, &amp;newval);

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode-&gt;data = newval;
    newnode-&gt;next = NULL;
    tail-&gt;next = newnode;

    while(head) {
        printf(&quot;%d &quot;, head-&gt;data);
        head = head-&gt;next;
    }

    return 0;
}