#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

//Traversal
void LinkedListTraversal(struct Node *ptr ){
    while(ptr!=NULL){
        printf("Element: %d\n",ptr->data);
    ptr=ptr->next;
    }
}

//Case 1 
struct Node * insertAtFirst (struct Node * head,int data){
        struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data=data;

        ptr->next=head;
        return ptr;
};

//Case 2
struct Node * insertAtBetween (struct Node * head,int data,int index){
        struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data=data;
        struct Node * p = head;
        int i=0;
        while(i!=index-1){
            p=p->next;
            i++;
        }
        
        ptr->next=p->next;
        p->next=ptr;
        return head;
}

//Case 3
struct Node * insertAtEnd(struct Node * head,int data){
    struct Node * ptr= (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    ptr->data=data;
    
    while(p->next!=NULL){
    p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}

//Case 4
struct Node * insertAfterGivenNode(struct Node * head,struct Node * prevNode,int data){
    struct Node * ptr = (struct Node * )malloc(sizeof ( struct Node));
    ptr->data=data;

    ptr->next=prevNode->next;
    prevNode->next=ptr;
    return head; 
}

int main() {
    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    struct Node * second = (struct Node *)malloc(sizeof(struct Node));
    struct Node * third = (struct Node *)malloc(sizeof(struct Node));
    struct Node * fourth = (struct Node *)malloc(sizeof(struct Node));

head->data=7;
head->next = second;

second->data= 11;
second->next=third;

third->data=66;
third->next= fourth;

fourth->data=77;
fourth->next=NULL;

printf("linkedlist before insertion\n");
LinkedListTraversal(head);

// head = insertAtFirst(head,88);

// head = insertAtBetween(head,56,1);

// head = insertAtEnd(head,56);

// head = insertAfterGivenNode(head,second,69);

printf("\nlinkedlist after insertion\n");
LinkedListTraversal(head);
    return 0;
}