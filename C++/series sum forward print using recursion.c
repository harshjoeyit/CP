#include<stdio.h>

// 1++2+3+4+ ...............= sum

int sumseries(long int n)
{
    if(n==0)
        return 0;
    printf("%ld+",n%10);
    return (n%10 + sumseries(n/10));
 //   printf("%ld+",n%10);

}

int main()
{
    long int n;

    while(scanf("%ld",&n))
    {
        printf(" = %ld\n",sumseries(n));
    }

    return 0;
}
