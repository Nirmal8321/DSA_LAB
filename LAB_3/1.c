#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *temp, *newnode;
    int n, i, val;

    scanf(&quot;%d&quot;, &amp;n);

    for(i = 0; i &lt; n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf(&quot;%d&quot;, &amp;val);
        newnode-&gt;data = val;
        newnode-&gt;next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp-&gt;next = newnode;
            temp = newnode;
        }
    }

    temp = head;
    while(temp != NULL) {
        printf(&quot;%d &quot;, temp-&gt;data);
        temp = temp-&gt;next;
    }

    return 0;
}