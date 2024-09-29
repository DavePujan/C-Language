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

// Function to insert a node at the end of the circular linked list
void insertEnd() {
    int data;
    printf("Enter data to insert at the end: ");
    scanf("%d", &data);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (!head) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    printf("Inserted %d at the end.\n", data);
}

int main() {
    // Print today's date and time
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Name: %s\n", NAME);
    printf("Enrollment: %s\n", ENROLLMENT);
    printf("Date and Time: %02d-%02d-%04d %02d:%02d:%02d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);

    insertEnd(); // Call the function to insert a node at the end

    return 0;
}
