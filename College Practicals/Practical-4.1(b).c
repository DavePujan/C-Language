#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head = NULL;

void insertEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        struct Node* p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = newNode;
        newNode->prev = p;
    }
    printf("%d inserted at the end.\n", value);
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
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    display();

    return 0;
}
