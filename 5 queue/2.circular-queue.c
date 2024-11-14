#include <stdio.h>
#include <stdlib.h>

struct circularqueue{
    int size;
    int f;
    int r;
    int * arr;
};

int isFull(struct circularqueue * q){
    if((q->r+1)%q->size==q->f){
        return 1;
    }
    return 0;
}

int isEmpty(struct circularqueue * q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}

void enqueue(struct circularqueue * q,int val){
    if(isFull(q)){
        printf("Queue is full");
    }else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r] = val;
        printf("Enqueued Value: %d",val);
    }
}

int dequeue(struct circularqueue * q){
    int a = -1;
    if(isEmpty(q)){
        printf("Queue is empty");
    }else{
        q->f=(q->f+1)%q->size;
        a= q->arr[q->f];
    }
    return a;
}


int main() {
    struct circularqueue *q{
        q->size=100;
        q->r=0;
        q->f=0;
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