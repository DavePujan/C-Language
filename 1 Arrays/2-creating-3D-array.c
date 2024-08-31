#include <stdio.h>

int main() {
    int a[3][2][1],i,j,k;

    for(i=0;i<3;i++){
        for(j=0;j<2;j++){
            for(k=0;k<1;k++){
                scanf("%d",&a[i][j][k]);
            }
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<2;j++){
            for(k=0;k<1;k++){
                printf("%d ",a[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}