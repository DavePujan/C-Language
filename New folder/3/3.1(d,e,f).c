// Write a menu driven program to implement following operations on the singly linked list.      
//       (d) Delete a first node of the linked list. 
//       (e) Delete a node before specified position. 
//       (f) Delete a node after specified position.


/*
delete at first head -->
create ptr = head
head = ptr next
free ptr , return head
*/

/*
delete between head index
create p = head , q = p next

int i = 0
while i != index -1 --> p = p next i++

p->next = q->next
free q, return head
*/

/*
delete at end head
create p = head, q= p next
while q next!= null -> p=p next , q=q next

p next = null , free q, return head
*/

/*
delete at given value
create p=head , q=p->next

while q data !=null && q next !=null --> p=p next, q= q next

if q data = value
p next = q next
free q , return head
*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
}

void LinkedListTraversal(struct Node * ptr){
    while(ptr!=NULL){
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
}

struct Node * deleteAtFirst(struct Node * head){
    struct Node * ptr = head;

    head = ptr->next;
    free(ptr);
    return head;
}

struct Node * deleteAtBetween(struct Node * head, int index){
    struct Node * p = head;
    struct Node * q = p-> next;

    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct Node * deleteAtEnd(struct Node * head){
    struct Node * p = head;
    struct * Node q= p-> next;

    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next= NULL;
    free(q);
    return head;
}


int main(){
    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    struct Node * second = (struct Node *)malloc(sizeof(struct Node));
    struct Node * third = (struct Node *)malloc(sizeof(struct Node));
    struct Node * fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=fourth;

    fourth->data=4;
    fourth->next=NULL;

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