/*
we have to multiply

| 0  5  2 |      | 1  2 |
|-1  1  0 |  *   | 0  4 |
| 7  4  3 |      | 3  5 |

*/


#include<stdio.h>
#define n 50
int main(){
    
    int a[n][n] = {{0, 5, 2}, {-1, 1, 0}, {7, 4, 3}};
     int b[n][n] = {{1, 2}, {0, 4}, {3, 5}};
     int c[n][n];
int i,j,k,sum;

    for(i=0;i<3;i++){
        for(j=0;j<2;j++)
            {
                sum=0;
                for(k=0;k<3;k++){
                    sum=sum + a[i][k]* b[k][j]
                }
                c[i][j]=sum;
            }
    }

    for(i=0;i<3;i++){
        for(j=0;j<2;j++){
            printf("%d \t",c[i][j]);
        }
        printf("\n");
    }

    return 0;
}