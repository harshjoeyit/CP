#include<stdio.h>
#include<math.h>
// divisibility by eleven means that sum of digits at the odd places - sum of digits at the even places should be equal to zero

int eleven(int n)
{
    if(n<11)
        return 0;

    int se=0,so=0,c=1;

    while(n>0)
    {
        if(c%2==0)
            so += n%10;
        else
            se += n%10;
        n=n/10;
        ++c;
        printf("\n");
    }

    if(abs(so-se)%11==0)
        return 1;
    else
        eleven(abs(so-se));
}

int main()
{
    int n;
    while(scanf("%d",&n))
    {
        if(eleven(n))
            printf("divisible");
        else
            printf("not divisible");
    }
    return 0;
}


