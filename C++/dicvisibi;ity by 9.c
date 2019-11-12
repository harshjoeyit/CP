#include<stdio.h>
#include<math.h>

int nine(int n)
{
    if(n<9)
        return 0;
    if(n==9)
        return 1;
    int s=0;
    while(n>0)
    {
        s += n%10;
        n = n/10;
    }
    nine(abs(s));
}

int main()
{
    int n;
    while(scanf("%d",&n))
    {
        if(nine(n))
            printf("divisible\n");
        else
            printf("not divisible\n");
    }
    return 0;
}


