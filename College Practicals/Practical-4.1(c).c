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

void deleteLast() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    if (p->prev != NULL) {
        p->prev->next = NULL;
    } else {
        head = NULL;
    }
    free(p);
    printf("Last node deleted.\n");
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
    deleteLast();
    display();
    return 0;
}
