#include <stdio.h>
#include <stdlib.h>
struct stack{
    int size;
    int top;
    int * arr;
};
int isEmpty(struct stack * ptr){
    if(ptr->top== -1){
        return 1;
    }else{
        return 0;
    }
}

int isFull(struct stack* ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }else{
        return 0;
    }
}

void push(struct stack * ptr,int val){
    if(isFull(ptr)){
        printf("stack overflow");
        return;
    }else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}
void pop(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("stack underflow!,cannot pop from the stack\n");
        return -1;
    }else{
        int val= ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int main() {
 struct stack *sp= (struct stack *)malloc (sizeof(struct stack));
    sp->size = 80;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size*sizeof(int));
   
    printf("Before pushing, Full %d \n", isFull(sp));
    printf("Before pushing, Empty %d\n", isEmpty(sp));

    // Push a value onto the stack
    push(sp,1);   
    push(sp,2);
    push(sp,3);
    push(sp,4);


    // // Print the pushed value
    // printf("Pushed value: %d\n", sp->arr[sp->top]);


    printf("After pushing, Full %d\n", isFull(sp));
    printf("After pushing, Empty %d\n", isEmpty(sp));

    // printf("Popped %d from the stack\n", pop(sp));
      // Free the allocated memory
    free(sp->arr);
    free(sp);
    return 0;
}