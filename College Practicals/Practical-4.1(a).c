#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head = NULL;

void insertFront(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
    printf("%d inserted at the front.\n", value);
}

void display() {
    struct Node* p = head;
    while (p != NULL) {
        printf("%d <-> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main() {
    insertFront(10);
    insertFront(20);
    insertFront(30);

    display();

    return 0;
}
