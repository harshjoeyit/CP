#include<stdio.h>
#include<math.h>

int fac(int n)
{
    if(n==0|| n==1)
        return 1;
    if(n<0)
        return 0;
    return (n*fac(n-1));
}


float cosxx(float x, int n)
{
    float y;
    if(n==-1)
        return 0;
    if(n%2==0)
        y=1;
    else
        y=-1;
    return ( 1.0*y * pow(x,2*n)/fac(2*n) + cosxx(x,n-1));
}


int main()
{
    float x;
    int n;
    scanf("%f%d",&x,&n);
    printf("%0.6f",cosxx(x,n));
}
