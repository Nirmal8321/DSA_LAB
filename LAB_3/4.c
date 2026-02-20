#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *tail = NULL, *temp, *newnode;
    int n, i, val, ipos, ival, dpos;

    scanf(&quot;%d&quot;, &amp;n);

    for(i = 0; i &lt; n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
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

    scanf(&quot;%d&quot;, &amp;ipos);
    scanf(&quot;%d&quot;, &amp;ival);

    temp = head;
    for(i = 1; i &lt; ipos - 1; i++) {
        temp = temp-&gt;next;
    }

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode-&gt;data = ival;
    newnode-&gt;next = temp-&gt;next;
    temp-&gt;next = newnode;

    scanf(&quot;%d&quot;, &amp;dpos);

    temp = head;
    for(i = 1; i &lt; dpos - 1; i++) {
        temp = temp-&gt;next;
    }

    struct node *del = temp-&gt;next;
    temp-&gt;next = del-&gt;next;
    free(del);

    while(head != NULL) {
        printf(&quot;%d &quot;, head-&gt;data);
        head = head-&gt;next;
    }

    return 0;
}