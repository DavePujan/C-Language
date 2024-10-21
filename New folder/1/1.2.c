// 1.2
// Implement a program for stack that performs following operations using array. (a) PUSH (b) POP (c) PEEP (d) CHANGE (e) DISPLAY


//def MAX 5
//stack[MAX] , top -1

/*
push -->
if top = max -1 --> overflow
else top++ --> stack[top]= value --> print value
 */

 /*
 pop -->
 if top = -1 underflow
 else print stack[top] --> top--
 */

/*
peep --> 
same as pop just don't do top--
*/

/*
change -->
for change we need two things --> position and newValue
if position is between 1 and top+1 then change

if position <1 || position >top+1 --> invalid
else stack[position -1] = newValue --> print position newValue
*/

/*
display -->
if top = -1 empty
else go from top to 0 to print stack[i]
like for(int i = top;i>=0;i--)
*/

#include<stdio.h>
#define MAX 5 

int stack[MAX];
int top = -1;

void push(int value){
    if(top == MAX - 1){
        printf("overflow can't push %d.\n",value);
    }else{
        top++;
        stack[top]=value;
        printf("%d pushed. \n",value);
    }
}

void pop(){
    if(top == -1){
        printf("underflow.\n");
    }else{
        printf("%d popped.\n",stack[top]);
        top--;
    }
}

void peep(){
    if(top == -1){
        printf("empty.\n");
    }else{
        printf("last element is: %d.\n",stack[top]);
    }
}

void change(int position, int newValue){
    if(position < 1 || position > top + 1){
        printf("invalid position");
    }else{
        stack[position - 1 ]= newValue;
        printf("element at position %d changed to %d.\n",position,newValue);
    }
}

void display(){
    if(top == -1){
        printf("empty");
    }else{
        printf("elements are: ");
        for(int i=top;i>=0;i--){
            printf("%d ",stack[i]);
        }
    }
}

//main

int main() {
    int choice, value, position;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEP\n");
        printf("4. CHANGE\n");
        printf("5. DISPLAY\n");
        printf("6. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peep();
                break;
            case 4:
                printf("Enter position to change (1-based index): ");
                scanf("%d", &position);
                printf("Enter new value: ");
                scanf("%d", &value);
                change(position, value);
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
