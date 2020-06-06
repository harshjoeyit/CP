#include<stdio.h>

int main()
{
    int m1,n1,m2,n2,i,j,k;
    printf("string product\n" );
    printf("matrix 1: \nm1, n1\n");
    scanf("%d%d",&m1,&n1);
    printf("matrix 2: \nm2, n2\n");
    scanf("%d%d",&m2,&n2);

    int a[10][10]={},b[10][10]={},c[10][10]={};

    printf("enter matrix 1: \n");

    for(i=0; i<m1; i++)
        for(j=0; j<n1; j++)
            scanf("%d",&a[i][j]);
    
    printf("enter matrix 2: \n");

    for(i=0; i<m2; i++)
        for(j=0; j<n2; j++)
            scanf("%d",&b[i][j]);

    printf("M1 * M2\n");

    for(i=0; i<m1; i++)
    {
        for(k=0; k<n2; k++)
        {
            int element = 0;
            for(j=0; j<n1; j++)
            {
                element += a[i][j] * b[j][k];
            }
            c[i][k] = element;
            printf("%d  ",c[i][k] );
        }
        printf("\n");
    }
}