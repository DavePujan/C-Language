#include<stdio.h>

int main(){

    int a=10;
    float b=1.111;

    int *ptr1 = &a;
     printf("%d \t",a);
    printf("%d \n",*ptr1);
    printf("Address of a=%p \n",&a); // & is for address
    printf("Address of a=%p \n",ptr1);
    printf("Address of p=%p \n \n",&ptr1);

    float *ptr2 = &b;
    printf("%f \t",b);
    printf("%f \n",*ptr2);
    printf("Address of b=%p \n",&b);
    printf("Address of b=%p \n \n",ptr2);
 return 0;
}



/*
so we need just
 int a=10;
  int *ptr1 = &a;
   printf("%d \t",a);
    printf("%d \n",*ptr1);
*/