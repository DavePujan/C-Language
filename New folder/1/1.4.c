// 1.4 Write a program to implement Tower of Hanoi problem.

/*
we need four parameters --> n , source--> A, auxiliary--> B, destination--> C 

move A to C if only one disk
best case : one disk --> if n=1 print A, C return

now again call for n-1 for A C B
towerOfHanoi(n-1,A,C,B) 

move nth disk from A to C
print n,A,C

now again call for n-1 for B A C

*/

#include<stdio.h>

void towerOfHanoi(int n,char A,char B,char C){
    if(n==1){
        printf("Move disk 1 from %c to %c.\n", A ,C);
        return;
    }

    towerOfHanoi(n-1,A,C,B);
    printf("Move disk %d from %c to %c.\n",n,A,C);

    towerOfHanoi(n-1,B,A,C);
}

int main(){
    int n;
    printf("Enter Number of Disks: ");
    scanf("%d", &n);

    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}