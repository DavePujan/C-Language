#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

//insert
void insertFront(int value) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = value;
    ptr->next = head;
    head = ptr;
    printf("%d inserted at the front.\n", value);
}

//insert a node at the end
void insertEnd(int value) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = value;
    ptr->next = NULL;
    
    if (head == NULL) {
        head = ptr;
    } else {
        struct Node* p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = ptr;
    }
    printf("%d inserted at the end.\n", value);
}

// insert a node in ascending order based on data value
void insertSorted(int value) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = value;

    if (head == NULL || head->data >= value) {
        ptr->next = head;
        head = ptr;
    } else {
        struct Node* p = head;
        while (p->next != NULL && p->next->data < value) {
            p = p->next;
        }
        ptr->next = p->next;
        p->next = ptr;
    }
    printf("%d inserted in sorted order.\n", value);
}

// delete the first node
void deleteFront() {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    struct Node* p = head;
    head = head->next;
    printf("%d deleted from the front.\n", p->data);
    free(p);
}

// delete a node before a specified index
void deleteBeforeIndex(int index) {
    if (head == NULL || index <= 1) {
        printf("Invalid index or no node exists before the specified index.\n");
        return;
    }
    struct Node* p = head;
    struct Node* prev = NULL;
    int i = 1;
    while (i < index - 1 && p->next != NULL) {
        prev = p;
        p = p->next;
        i++;
    }
    if (prev == NULL) {
        head = p->next;
    } else {
        prev->next = p->next;
    }
    printf("Node before index %d deleted.\n", index);
    free(p);
}

//delete a node after a specified index
void deleteAfterIndex(int index) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* p = head;
    int i = 1;
    while (i < index && p != NULL) {
        p = p->next;
        i++;
    }
    if (p == NULL || p->next == NULL) {
        printf("Index out of range.\n");
        return;
    }
    struct Node* toDelete = p->next;
    p->next = toDelete->next;
    printf("Node after index %d deleted.\n", index);
    free(toDelete);
}

// Function to Traverse the list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* ptr = head;
    printf("Current Linked List: ");
    while (p != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}


int main() {
    int choice, value, index;
    do {
        printf("\nSingly Linked List Operations:\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Insert in sorted order\n");
        printf("4. Delete first node\n");
        printf("5. Delete node before specified index\n");
        printf("6. Delete node after specified index\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 3:
                printf("Enter value to insert in sorted order: ");
                scanf("%d", &value);
                insertSorted(value);
                break;
            case 4:
                deleteFront();
                break;
            case 5:
                printf("Enter the index before which node should be deleted: ");
                scanf("%d", &index);
                deleteBeforeIndex(index);
                break;
            case 6:
                printf("Enter the index after which node should be deleted: ");
                scanf("%d", &index);
                deleteAfterIndex(index);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}
