// 2.1 Write a program to implement QUEUE using arrays that performs following operations (a)INSERT (b) DELETE (c) DISPLAY

/*
def max 5, int queue[max] , set front , rear -1
*/

/*
insert (value) -->
if rear =max -1 --> queue is full
else  --> if front = -1 set front = 0
rear ++ , queue[rear]=value , print value
*/

/*
delete --> 
if front = -1 || front>rear empty
else print queue[front]
front++

set again front , rear to -1 if front > rear
if front > rear --> front= rear= -1
*/

/*
display-->
for this we will check if front = -1 , if it is then we will say that our queue is empty:
if(front = -1) --> empty

other wise we will go from front to rear and print queue[i] :
else --> for(int i=front; i<=rear; i++) print queue[i]
*/

#include<stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void insert(int value){
    if(rear = MAX -1){
        printf("queue is full");
    }else(
        if(front== -1){
            front= 0;
        }
        rear++;
        queue[rear]= value;
        printf("%d inserted.\n",value);
    )
}

void delete(){
    if(front = -1 || front>rear){
        printf("queue is empty.\n");
    }else{
        printf("%d is deleted.\n",  queue[front]);
        front++;
        if(front>rear){
            front = rear = -1;
        }
    }
}

void display(){
    if(front= -1){
        printf("Queue is empty.\n");
    }else{
        for(int i=front; i<=rear; i++){
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;  // Exit the program
            default:
                printf("Invalid choice!\n");
        }
    }
}
