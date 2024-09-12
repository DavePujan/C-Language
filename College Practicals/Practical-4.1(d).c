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
void deleteBefore(int position) {
    if (position <= 1) {
        printf("Invalid position.\n");
        return;
    }
    struct Node* p = head;
    int i = 1;

    while (i < position - 1 && p != NULL) {
        p = p->next;
        i++;
    }
    if (p == NULL || p->prev == NULL) {
        printf("No node to delete before position %d.\n", position);
        return;
    }
    struct Node* toDelete = p->prev;
    if (toDelete->prev != NULL) {
        toDelete->prev->next = p;
    } else {
        head = p;
    }
    p->prev = toDelete->prev;
    free(toDelete);
    printf("Node before position %d deleted.\n", position);
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
    // Insert some nodes for testing
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);

    display();
    deleteBefore(3);
    display();

    return 0;
}
