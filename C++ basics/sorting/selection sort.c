#include<stdio.h>

/*
    Not a stable sorting algorithm 
    Ex - 5, 6, 5, 3, 4
*/

void select_sort( int a[] , int n ) {
    int i, j , temp , min;
    for( i = 0; i < n-1; i++ )
    {
        min = i;
        for( j = i + 1; j < n; j++ )
            if( a[min] > a[j] )
                min = j;
            // swap after finding the index of the min number 
            temp = a[min];
            a[min] = a[i];
            a[i] = temp;
    }
} 


int main()
{
    int n;
    scanf("%d", &n);
    int a[n] = {};
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    select_sort(a , sizeof(a)/sizeof(int) );
    for( int i = 0; i< sizeof(a)/sizeof(int); i++ )
        printf("%d ", a[i]);

    return 0;
}