#include<stdio.h>

void bubble_sort( int *p , int size)
{
    // in place  of a[i] write p[i] and rest is same.
}

int main()
{
    int a[]= {1,4,3,6,0,2,6,7} ,i;

    for(i=0; i<8; i++)
    {
        printf("%d,",a[i]);
    }

    bubble_sort(a,8);
    printf("\nsorted: \n");

    for(i=0; i<8; i++)
    {
        printf("%d,",a[i]);
    }
}