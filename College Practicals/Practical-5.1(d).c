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

//delete a node after a specified position
void deleteAfter() {
    int pos;
    printf("Enter position to delete after: ");
    scanf("%d", &pos);

    if (!head) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    for (int i = 1; i < pos && current->next != head; i++) {
        current = current->next;
    }

    if (current->next == head) {
        printf("Position out of bounds.\n");
        return;
    }

    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    printf("Deleted node after position %d.\n", pos);
}

int main() {
    // today's date and time
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Name: %s\n", NAME);
    printf("Enrollment: %s\n", ENROLLMENT);
    printf("Date and Time: %02d-%02d-%04d %02d:%02d:%02d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);

    deleteAfter(); 
    return 0;
}
