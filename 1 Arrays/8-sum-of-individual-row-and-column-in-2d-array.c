#include <stdio.h>

int main() {
    int a[2][3],i,j;

    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            scanf("%d",&a[i][j]);
        }printf("\n");
    }

    for(i=0;i<2;i++){
        int sr=0,sc=0;
        for(j=0;j<3;j++){
            sr=sr+a[i][j];
            sc=sc+a[j][i];
        }
        printf("\n");
        printf("sr=%d,sc=%d for row=%d",sr,sc,i+1);
    }
    
    return 0;
}