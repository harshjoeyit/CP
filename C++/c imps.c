#include<stdio.h>

int swapit(int a,int b)
{
    int c;
    c=a;
    a=b;
    b=c;
    printf("\nswapped:\na=%d\nb=%d",a,b);
    return(b,a);  // a=20,b=10   //faulty code
}

int incr(int i)
{
    static int countt=0;
    countt += i;
    return countt;
}

void foo(int n,int sum)
{
    int k=0,j=0;
    if(n==0)
        return;
    k=n%10;
    j=n/10;

    sum=sum+k;

    foo(j,sum);

    printf("%d",k);
}

int main()
{
    int a=10,b=20;
    printf("original: \na=%d\nb=%d",a,b);
    int x=swapit(a,b);  //x=a from swapit
    int y=swapit(b,a);  // y=b from swapit

    printf("\na=%d\nb=%d\nx=%d\ny=%d",a,b,x,y);



    int i,j;
    for(i=0; i<=4; i++)
    {
        j=incr(i);
    }
    printf("\nj=%d",j);


    int pt=2048;
    int sum=0;
    foo(pt,sum);
    printf("%d",sum);

}
