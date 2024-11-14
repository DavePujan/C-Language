#include <stdio.h>
#include <stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int * arr;
};

int isFull(struct queue * q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}

int isEmpty(struct queue * q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}

void enqueue(struct queue * q,int val){
    if(isFull(q)){
        printf("Queue is full");
    }else{
        q->r=q->r+1;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue * q){
    int a = -1;
    if(isEmpty(q)){
        printf("Queue is empty");
    }else{
        q->f=q->f+1;
        a= q->arr[q->f];
    }
    return a;
}


int main() {
    struct queue *q{
        q->size=100;
        q->r=-1;
        q->f=-1;
        q->arr=(int *)malloc(q->size*sizeof(int));
    }

    enqueue(&q,12);
    enqueue(&q,15);
    enqueue(&q,17);
    printf("Dequeuing element %d\n",dequeue(&q));
    printf("Dequeuing element %d\n",dequeue(&q));
    printf("Dequeuing element %d\n",dequeue(&q));
    enqueue(&q,45);
    enqueue(&q,45);
    enqueue(&q,45);
    printf("Dequeuing element %d\n",dequeue(&q));
    printf("Dequeuing element %d\n",dequeue(&q));
    printf("Dequeuing element %d\n",dequeue(&q));

    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    if(isFull(&q)){
        printf("Queue is Full\n");
    }
    return 0;
}