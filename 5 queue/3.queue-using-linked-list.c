#include <stdio.h>
#include <stdlib.h>

struct Node *f = NULL;
struct Node *r = NULL;
struct Node
{
    int data;
    struct Node *next;
};


void LinkedListTraversal(struct Node * ptr){
    while(ptr!=NULL){
    printf("Element: %d\n",ptr->data);
    ptr->next;
    }
}

void enqueue( int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("Is Full\n");
    }
    else
    {
        n->data = val;
        r->next = n;
        n->next = NULL;

        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}


int dequeue()
{
    int val=-1;
    struct Node *ptr = f;
    if (f == NULL)
    {
        printf("IsEmpty\n");
    }
    else
    {
        f=f->next;
        val=ptr->data;
        free(ptr);
        return val;
    }
}

int main()
{
    LinkedListTraversal(f);
    printf("Dequeuing Element %d\n",dequeue());
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    printf("Dequeuing Element %d\n",dequeue());
    LinkedListTraversal(f);
    return 0;
}