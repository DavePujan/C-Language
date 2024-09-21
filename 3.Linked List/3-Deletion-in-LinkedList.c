#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};


//Traversal
void LinkedListTraversal(struct Node *ptr){
    while(ptr!=NULL){ 
        printf("Element: %d\n",ptr->data);
    ptr=ptr->next;
    }
}

//Case 1
struct Node * deleteAtFirst(struct Node* head){
    struct Node * ptr = head;
    head=ptr->next;
    free(ptr);
    return head;
}

//Case 2
struct Node * deleteAtBetween(struct Node * head,int index){
    struct Node* p= head;
    struct Node * q= p->next;
    int i=0;
    while(i!=index-1){
           p=p->next;
           i++;
    } 
    p->next=q->next;
    free(q);
    return head;
}

//Case 3
struct Node * deleteAtEnd(struct Node * head){
    struct  Node * p = head;
    struct Node * q=p->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

//Case 4
struct Node * deleteAtGivenValue(struct Node * head,int value){
    struct Node * p= head;
    struct Node * q=p->next;

    while(q->data!=value && q->next!=NULL){
    p=p->next;
    q=q->next;
    }
    if(q->data == value){
    p->next=q->next;
    free(q);
    }
    return head;    
}

int main() {
    struct Node * head = (struct Node*)malloc(sizeof(struct Node));
    struct Node * second = (struct Node*)malloc(sizeof(struct Node));
    struct Node * third = (struct Node*)malloc(sizeof(struct Node));

    head->data=7;
    head->next=second;

    second->data=8;
    second->next=third;

    third->data=9;
    third->next=NULL;

    printf("Linked list before deletion\n");
    LinkedListTraversal(head);

    // head= deleteAtFirstAtFirst(head);
    // head= deleteAtBetween(head,1);

    // head= deleteAtEnd(head);

    head= deleteAtGivenValue(head,8);

    printf("\nLinked list after Deletion\n");
    LinkedListTraversal(head);
    return 0;
}