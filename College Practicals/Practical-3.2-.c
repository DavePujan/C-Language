#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* top = NULL;

void push(int value) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("Stack overflow, unable to push %d\n", value);
        return;
    }
    ptr->data = value;
    ptr->next = top;
    top = ptr;
    printf("%d pushed to the stack.\n", value);
}

void pop() {
    if (top == NULL) {
        printf("Stack underflow, no element to pop.\n");
        return;
    }
    struct Node* ptr = top;
    printf("%d popped from the stack.\n", ptr->data);
    top = top->next;
    free(ptr);
}

void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* p = top;
    printf("Stack elements are:\n");
    while (p != NULL) {
        printf("%d\n", p->data);
        p = p->next;
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    
    display();

    pop();
    display();

    pop();
    pop();
    return 0;
}
