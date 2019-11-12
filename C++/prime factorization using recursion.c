#include<stdio.h>

void pfactor(int n,int m)
{
    if(n==1)
        return;
    int i;
    for(i=m; i<=n; i++)
    {
        if(n%i==0)
        {
            pfactor(n/i,i);
            break;
        }
    }
     printf("%d,",i);
}

int main()
{
    int n;
    while(scanf("%d",&n))
    {
        pfactor(n,2);
        printf("\n");
    }
    return 0;
}
