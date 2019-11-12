#include<stdio.h>

void base(int num,int b)
{
    int rem=num%b;
    if(num==0)
        return;
    base(num/b,b);
    if(rem<10)
        printf("%d",rem);
    else
        printf("%c",55+rem);
}


int main()
{
    int n,i;

    while(scanf("%d",&n))
    {
             printf("\n");
            base(n,8);
            printf("\n");
            base(n,2);
            printf("\n");
            base(n,16);
    }

    return 0;
}
