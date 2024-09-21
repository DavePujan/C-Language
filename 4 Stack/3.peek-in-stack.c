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

int peek(struct stack* ptr,int i){
    int ptrIndex = ptr->top - i;
    if(ptrIndex < 0){
        printf("Invalid Position");
        return -1;
    }else{
        return ptr->arr[ptr->top - i + 1];
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


    for(int j=1; j< sp->top +1;j++){
    printf("The value at index %d is %d\n",j,peek(sp,j));
    }
    // printf("Popped %d from the stack\n", pop(sp));
      // Free the allocated memory
    free(sp->arr);
    free(sp);
    return 0;
}