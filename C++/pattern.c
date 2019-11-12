#include<stdio.h>

int main()
{
    int n;
    printf("n=");
    scanf("%d",&n);
    int i,j;
    for(i=1; i<=n; i++)
    {
        for(int j=n; j>=1; j--)
        {
            if(j<=i)
                printf("%d",j);
            else
                printf(" ");
        }
        printf("\n");
    }

    for(i=n-1; i>=1; i--)
    {
        for(j=n; j>=1; j--)
        {
            if(j<=i)
                printf("%d",j);
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
