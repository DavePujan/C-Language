baki

// 1.3 Implement a program to convert infix notation to postfix notation using stack.

/*
def max 100
char stack[max] , top =-1
*/

/*
push to add to the stack
push(char c) -->
if top = max -1 overflow
else stack[++top] = c
*/

/*
pop to return to top--    -->
if top = -1 underflow , return -1
else return stack[top--]
*/

/*
now set precedence */

/*
infixToPostfix (char* exp)
i, k = 0
now create array to store char postfix[MAX]
now go from o to exp[i] --> for (i=o;exp[i];i++)

*/

/*
main -->
char Infix[MAX]
scanf %s infix
InfixToPostfix(infix)
*/

#include<stdio.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c){
    if(top == MAX -1){
        printf("OVERFLOW.\n");
    }else{
        stack[++top]= c;
    }
}

void pop(){
    if ( top == -1){
        printf("underflow.\n");
        return -1;
    }else{
        return stack[top--];
    }
}

int precedence(char c){
    if(c=='^'){
        return 3;
    }else if(c == '*' || c == '/'){
        return 2;
    }else if(c == '+' || c == '-'){
        return 1;
    }else {
        return -1; // for negative result.
    }
}

void InfixToPostfix(char* exp){

}

int main(){
    char Infix[MAX];

    printf("Enter Infix Expression: ");
    scanf("%s",infix);

    InfixToPostfix(infix);

    return 0;
}