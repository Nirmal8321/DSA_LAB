#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *tail = NULL, *temp;
    int n, i, val, pos, len = 0;

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

    scanf(&quot;%d&quot;, &amp;pos);

    temp = head;

    while(temp != NULL) {
        len++;
        temp = temp-&gt;next;
    }

    int dpos = len - pos + 1;

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