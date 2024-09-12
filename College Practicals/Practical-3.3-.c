#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int value) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("Queue overflow, unable to enqueue %d\n", value);
        return;
    }
    ptr->data = value;
    ptr->next = NULL;
    if (rear == NULL) {
        // jo Queue empty hoi to
        front = rear = ptr;
    } else {
        rear->next = ptr;
        rear = ptr;
    }
    printf("%d enqueued to the queue.\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue underflow, no element to dequeue.\n");
        return;
    }
    struct Node* ptr = front;
    printf("%d dequeued from the queue.\n", ptr->data);
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(ptr);
}

void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* p = front;
    printf("Queue elements are:\n");
    while (p != NULL) {
        printf("%d\n", p->data);
        p = p->next;
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();-

    dequeue();
    dequeue();

    dequeue();
    display();

    return 0;
}
