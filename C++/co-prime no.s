#include<stdio.h>

int isprime(int n)
{
    if(n==0 || n==1)
        return 0;
    else
    if(n==2 ||n==3)
        return 1;

    else
    if(n>3)
    {
        for(int i=2; i<=n/2; i++)
        {
            if(n%i==0)
                return 0;
        }
        return 1;
    }

}

int main()
{
    int n,i;
    scanf("%d",&n);

    for(i=1; i<= (n-1)/2 ;i++)
    {
        if(isprime(2*i-1) && isprime(2*i+1))
                printf("(%d,%d)\n",2*i-1,2*i+1);
    }

    return 0;
}
