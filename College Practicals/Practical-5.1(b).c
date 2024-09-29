#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NAME "Dave Pujan M."
#define ENROLLMENT "230130107024"

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to insert a node before a specified position
void insertBefore() {
    int data, pos;
    printf("Enter data to insert: ");
    scanf("%d", &data);
    printf("Enter position to insert before: ");
    scanf("%d", &pos);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (!head) {
        printf("List is empty.\n");
        free(newNode);
        return;
    }

    if (pos == 1) {
        newNode->next = head;
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        head = newNode;
        return;
    }

    struct Node* current = head;
    for (int i = 1; i < pos - 1 && current->next != head; i++) {
        current = current->next;
    }

    if (current->next == head) {
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
    printf("Inserted %d before position %d.\n", data, pos);
}

int main() {
    // Print today's date and time
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Name: %s\n", NAME);
    printf("Enrollment: %s\n", ENROLLMENT);
    printf("Date and Time: %02d-%02d-%04d %02d:%02d:%02d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);

    insertBefore(); // Call the function to insert a node before a specified position

    return 0;
}
