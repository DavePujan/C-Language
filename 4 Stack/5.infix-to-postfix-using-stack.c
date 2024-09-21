#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node *next;
};

struct stack {
    int size;
    int top;
    char *arr;
};

int isFull(struct stack *ptr) {
    return ptr->top == ptr->size - 1;
}

int isEmpty(struct stack *ptr) {
    return ptr->top == -1;
}

void push(struct stack *ptr, char val) {
    if (isFull(ptr)) {
        printf("Stack overflow\n");
        return;
    } else {
        ptr->arr[++ptr->top] = val;
    }
}

char pop(struct stack *ptr) {
    if (isEmpty(ptr)) {
        printf("Stack underflow! Cannot pop from the stack\n");
        return '\0'; // Return null character for underflow
    } else {
        return ptr->arr[ptr->top--];
    }
}

char stackTop(struct stack *sp) {
    return sp->arr[sp->top];
}

int prec(char ch) {
    if (ch == '*' || ch == '/') {
        return 3;
    } else if (ch == '+' || ch == '-') {
        return 2;
    }
    return 0;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

char *infixToPostfix(char *infix) {
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postFix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        if (!isOperator(infix[i])) {
            postFix[j++] = infix[i];
        } else {
            while (!isEmpty(sp) && prec(infix[i]) <= prec(stackTop(sp))) {
                postFix[j++] = pop(sp);
            }
            push(sp, infix[i]);
        }
        i++;
    }

    while (!isEmpty(sp)) {
        postFix[j++] = pop(sp);
    }
    postFix[j] = '\0';

    free(sp->arr);
    free(sp);
    return postFix;
}

int main() {
    char *infix = "a-b+t/6";
    printf("Postfix is %s\n", infixToPostfix(infix));
    return 0;
}
