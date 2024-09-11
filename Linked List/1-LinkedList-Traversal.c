#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
}

void LinkedListTraversal(struct Node * ptr){
    while(ptr!=NULL){
    printf("Element: %d\n",ptr->data);
    ptr->next;
    }
}

int main() {
    struct Node * head;
    struct Node * second;
    struct Node * third;

    // Allocate memory for nodes in the linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    //Link first and second node
    head->data = 7;
    head->next = second;    
    //Link second and third node
    second->data = 11;
    second->next = third;
    //terminate the list at the third node
    third->data = 66;
    third->next = NULL;

    LinkedListTraversal(head);
    return 0;
}