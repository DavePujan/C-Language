#include <stdio.h>

struct Node{
    int data;
    struct Node * next;
};
void CircularLinkedListTraversal(struct Node * head){
    struct Node * ptr= head;

    do{
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
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
    third->next = head;

    CircularLinkedListTraversal(head);

    return 0;
}