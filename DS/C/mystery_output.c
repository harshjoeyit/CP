#include<stdio.h>

int a = 0;

int incre(int count )
{
    printf("incrementing a by %d\n",count);
    a += count;
    return 1;
}

int main()
{
    printf(" a=%d,%d,a=%d,%d,a=%d ",a,incre(5),a,incre(10),a);
    return 0;
}
