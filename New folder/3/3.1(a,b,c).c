// Write a menu driven program to implement following operations on the singly linked list.   
//       (a) Insert a node at the front of the linked list. 
//       (b) Insert a node at the end of the linked list. 
//       (c) Insert a node such that linked list is in ascending order.(According to INFO field) 

/*
create Node structure having data and next ptr

add all head,first , second... srtuct in main
give data and next ptr to all of them
*/

/*
traversal ptr -->
while ptr!=nulll --> print ptr data --> ptr = ptr next
*/

/*
insert at first struct head, data
create ptr and do ptr=ptr data

 set ptr next = head
 return ptr
*/

/*
insert between struct head , data, index

create ptr set ptr data= data
create p = head

int i=0  ,  while i!=index-1 --> do p->p->next i++

ptr next = p next;
p next= ptr
return head
*/

/*
insert at end head data
create ptr do ptr data= data
create p = head

jab tk last element tk na pohche tab tk increment karte raho
while p next!= null do p=p->next

p->next=ptr
ptr next = null
*/

/*
insert after given node head prevnode data
create ptr do ptr data = data

ptr next = prev next
prev next = ptr
*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
}

void LinkedListTraversal(struct Node * ptr){
    while(ptr!=NULL){
        printf("Element: %d",ptr->data);
        ptr->ptr->next;
    }
}

void insertAtFirst(struct Node * head,int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;

    prt->next = head;
    return ptr;
}

void insertAtBetween(struct Node * head,int data,int index){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node * p = head;

    int i = 0;
    while(i!=index -1){
        p=p->next;
        i++
    }
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

void insertAfterGivenNode(struct Node * head,struct Node * prevNode,int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;

    ptr->next=prevNode->next;
    prevNode->next=ptr;
    return head;
}


int main(){
    struct Node * head=(struct Node*)malloc(sizeof(struct Node));
    struct Node * first = (struct Node *)malloc(sizeof(struct Node));
    struct Node * second = (struct Node *)malloc(sizeof(struct Node));
    struct Node * third = (struct Node*)malloc(sizeof(struct Node));
    struct Node * fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=fourth;

    fourth->data=4;
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