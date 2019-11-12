#include<stdio.h>

void bubble_sort( int *p,int size)
{
    int i,j,temp;
    for(i=0; i<size-1; i++)
    {
        for(j=i; j<size; j++)
        {
            if(p[i]<p[j])
            {   
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
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