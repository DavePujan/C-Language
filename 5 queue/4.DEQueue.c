#include <stdio.h>
#include <stdlib.h>

struct DEQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct DEQueue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct DEQueue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

void enqueuer(struct DEQueue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue is full");
    }
    else
    {
        q->r = q->r + 1;
        q->arr[q->r] = val;
        printf("Enqueued at rear %d\n",val);    
        }
}

void enqueuef(struct DEQueue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue is full");
    }
    else
    {
        q->arr[q->f] = val;
        q->f = q->f - 1;
        printf("Enqueued at front %d\n",val);    
    }
}

int dequeuef(struct DEQueue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("Queue is empty");
    }
    else
    {
        q->f = q->f + 1;
        a = q->arr[q->f];
    }
    return a;
}

int dequeuer(struct DEQueue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("Queue is empty");
    }
    else
    {
        a = q->arr[q->r];
        q->r = q->r - 1;
    }
    return a;
}

void printDEQueue(struct DEQueue *q)
{
    int i = q->f + 1;
    printf("Elements are: ");
    while (i <= q->r)
    {
        printf("%d ", q->arr[i]);
        i++;
    }
    printf("\n");
}


int main()
{
    struct DEQueue *q = (struct DEQueue *)malloc(sizeof(struct DEQueue));
    q->size = 100;
    q->r = -1;
    q->f = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    printDEQueue(q);
    enqueuer(q, 12);
    enqueuer(q, 15);
    enqueuer(q, 17);
    printDEQueue(q);

    printf("Dequeuing element from front which is %d\n", dequeuef(q));
    printf("Dequeuing element from rear which is %d\n", dequeuer(q));
    printDEQueue(q);

    enqueuef(q, 45);
    enqueuef(q, 45);
    enqueuef(q, 45);
    printDEQueue(q);

    printf("Dequeuing element from front which is %d\n", dequeuef(q));
    printf("Dequeuing element from rear which is %d\n", dequeuer(q));
    printDEQueue(q);

    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    if (isFull(q))
    {
        printf("Queue is Full\n");
    }
    return 0;
}