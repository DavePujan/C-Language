#include <stdio.h>

int main() {
    int mark[5],i,sum=0,avg;

    for(i=0;i<5;i++){
        scanf("%d",&mark[i]);
    }
    for(i=0;i<5;i++){
        sum=sum+mark[i];
    }
    avg=sum/5;
    printf("the sum is %d and avg is %d",sum,avg);
    return 0;
}