#include <stdio.h>
#define MAX 5  // max size nakki karva

int queue[MAX];
int front = -1, rear = -1;

// insert
void insert() {
    int item;
    if ((front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1))) {
        printf("Queue is full! Insertion not possible.\n");
    } else {
        printf("Enter the element to insert: ");
        scanf("%d", &item);

        if (front == -1) {  // Insert first element
            front = rear = 0;
        } else if (rear == MAX - 1 && front != 0) {  // queue ne Wrap karva
            rear = 0;
        } else {
            rear++;
        }
        queue[rear] = item;
        printf("%d inserted into the queue.\n", item);
    }
}

//delete
void delete() {
    if (front == -1) {
        printf("Queue is empty! Deletion not possible.\n");
    } else {
        printf("%d deleted from the queue.\n", queue[front]);

        if (front == rear) {  // Queue has only one element
            front = rear = -1;
        } else if (front == MAX - 1) {  // Wrap karva
            front = 0;
        } else {
            front++;
        }
    }
}

// display
void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements are: ");
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        } else {
            for (int i = front; i < MAX; i++) {
                printf("%d ", queue[i]);
            }
            for (int i = 0; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        }
        printf("\n");
    } }
int main() {
    int choice;
    do {
        printf("\nCircular Queue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);
    return 0;}
