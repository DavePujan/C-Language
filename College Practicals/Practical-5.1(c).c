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

//delete the first node
void deleteFirst() {
    if (!head) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        free(head);
        head = temp->next;
    }
    printf("Deleted the first node.\n");
}

int main() {
    // today's date and time
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Name: %s\n", NAME);
    printf("Enrollment: %s\n", ENROLLMENT);
    printf("Date and Time: %02d-%02d-%04d %02d:%02d:%02d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);

    deleteFirst();

    return 0;
}
