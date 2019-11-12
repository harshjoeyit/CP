#include<stdio.h>

int c=1;
int C=10000;

int LCM(int a,int b)
{
    if(c%a==0 && c%b==0)
        return c;
    else
        ++c;
    LCM(a,b);
}


int HCF(int a,int b)
{
    if(a%C==0 && b%C==0)
        return C;
    else if(C==1)
        return 1;
    else
        --C;
    HCF(a,b);
}


int main()
{
    int n1,n2;
    printf("n1,n2\n");
    scanf("%d%d",&n1,&n2);
    printf("LCM=%d",LCM(n1,n2));
    printf("\nHCF=%d",HCF(n1,n2));

    int x=n1,y=n2;

    while(n1!=n2)
    {
        if(n1<n2)
            n1=n1+x;
        else
            n2=n2+y;
    }
    printf("\nLcm =%d",n1);

    return 0;
}
