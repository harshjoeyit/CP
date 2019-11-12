#include<stdio.h>

int main()
{
    // try a 2D Array approach
    int n,i,j;
    printf("number: ");
    scanf("%d",&n);

    for(i=0; i<=n; i++)
    {
        for(j=1; j<=2*n+1; j++)
        {
            if(j==6-i || j==6+i)
                printf("1");
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
