#include<stdio.h>

void bubble_sort( int a[] , int n)
{
    int pass , i , temp ,swapped = 1;
    for( pass = n-1; pass >= 1 && swapped; pass-- )
    {
        swapped = 0;
        for( int i = 0; i<=pass - 1; i++ )
            if( a[i] >a[i+1])
            {
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
                swapped = 1;
            }
    }
}


int main()
{
    int n;
    scanf("%d", &n);
    int a[n] = {};
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    bubble_sort(a , sizeof(a)/sizeof(int) );
    
    for( int i = 0; i< sizeof(a)/sizeof(int); i++ )
        printf("%d ", a[i]);

    return 0;
}