#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node * prev;
    struct Node * next;
};

void traversal(struct Node * ptr){
    while (ptr!=NULL)
    {
       printf("Element: %d\n",ptr->data);
       ptr=ptr->next;
    }
}

struct Node * insertAtFirst(struct Node * head,int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;

    ptr->next=head;
    ptr->prev=NULL;

     if (head != NULL) {
        head->prev = ptr;  // Update old head's prev to new node
    }
    return ptr;
}

struct Node * insertAtEnd(struct Node * head,int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node * p = head;

    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    ptr->prev=p;
    return head;
}

struct Node * insertAtGivenIndex(struct Node * head, int data,int index){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node * p = head;

    int i=0;
    while (i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    
     if (p->next != NULL) {  // Step 2: Update p->next's prev, if it exists
        p->next->prev = ptr;
    }
    p->next=ptr;
    ptr->prev=p;
    return head;
}

int main() {
    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    struct Node * second = (struct Node *)malloc(sizeof(struct Node));
    struct Node * third = (struct Node *)malloc(sizeof(struct Node));
    struct Node * fourth = (struct Node *)malloc(sizeof(struct Node));
    
    head->data=1;
    head->prev=NULL;
    head->next=second;

    second->data=2;
    second->prev=head;
    second->next=third;

    third->data=3;
    third->prev=second;
    third->next=fourth;

    fourth->data=4;
    fourth->prev=third;
    fourth->next=NULL;

    printf("List before insertion:\n");
    traversal(head);

    head = insertAtFirst(head, 0);
    printf("List after insertion at beginning:\n");
    traversal(head);

    head = insertAtEnd(head, 5);
    printf("List after insertion at end:\n");
    traversal(head);

    head = insertAtGivenIndex(head, 6,second);
    printf("List after insertion at end:\n");
    traversal(head);

    return 0;
}