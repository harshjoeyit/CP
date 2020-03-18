#include<stdio.h>

void insertion_sort( int a[] , int n)
{
    int i , j , temp , k;
    for( i = 1; i < n; i++ )
    {
       temp = a[i];
       j = i;
       while( a[j-1] > temp && j >= 1 )
        {
            a[j] = a[j-1];
            j--;
        }
        a[j] = temp;        // at last j is at the position where the last greater element than temp is found 
    }
}


int main()
{   
    int n;
    scanf("%d", &n);
    int a[n] = {};
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int a[] = { 6,5,1,3,11,15,4,9,7 };
    insertion_sort(a , sizeof(a)/sizeof(int) );
    for( int i = 0; i< sizeof(a)/sizeof(int); i++ )
        printf("%d ", a[i]);
}