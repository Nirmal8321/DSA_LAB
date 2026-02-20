#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *slow, *fast;
    int n, i, val;

    scanf(&quot;%d&quot;, &amp;n);

    for(i = 0; i &lt; n; i++) {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        scanf(&quot;%d&quot;, &amp;val);
        newnode-&gt;data = val;
        newnode-&gt;next = head;

        head = newnode;
    }

    slow = fast = head;

    while(fast &amp;&amp; fast-&gt;next) {
        slow = slow-&gt;next;
        fast = fast-&gt;next-&gt;next;

        if(slow == fast) {
            printf(&quot;Cycle detected&quot;);
            return 0;
        }
    }

    printf(&quot;No cycle&quot;);
    return 0;
}