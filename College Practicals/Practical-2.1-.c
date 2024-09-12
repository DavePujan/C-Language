#include <stdio.h>
#define MAX 5  //max sizedecide karva

int queue[MAX];
int front = -1, rear = -1;

// insert
void insert() {
    int item;
    if (rear == MAX - 1) {
        printf("Queue is full! Insertion not possible.\n");
    } else {
        printf("Enter the element to insert: ");
        scanf("%d", &item);
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = item;
        printf("%d inserted into the queue.\n", item);
    }
}

// delete 
void delete() {
    if (front == -1 || front > rear) {
        printf("Queue is empty! Deletion not possible.\n");
    } else {
        printf("%d deleted from the queue.\n", queue[front]);
        front++;
        if (front > rear) {  // empty karva
            front = rear = -1;
        }
    }
}

// display 
void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
+
int main() {
    int choice;
    do {
        printf("\nQueue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");+
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

    return 0;
}
