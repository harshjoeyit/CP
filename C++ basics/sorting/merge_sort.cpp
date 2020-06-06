#include<bits/stdc++.h>
using namespace std;


void Merge( int *left , int l_size , int *right , int r_size , int *A )
{
    int i , l , r;
    i = l = r = 0;

    while( (l < l_size) && (r < r_size) )
    {
        if( left[l] < right[r] )
            A[i++] = left[l++];
        else
            A[i++] = right[r++];
    }

    while(l < l_size)
        A[i++] = left[l++];
    while(r < r_size)
        A[i++] = right[r++];

}



void MergeSort( int *A , int n )
{
    if(n < 2)
        return;
    
    int mid = n/2;
    int *left = (int *)malloc( mid*sizeof(int) );
    int *right = (int *)malloc( (n-mid)*sizeof(int) );

    for( int i = 0; i < mid; i++ )
        left[i] = A[i];
    for( int i = mid; i < n; i++ )
        right[i-mid] = A[i];
    
    MergeSort(left , mid);
    MergeSort(right , n-mid);
    Merge(left , mid , right , n-mid , A);
}



void print( int a[] , int n )
{
   printf("array: ");
   for( int i = 0; i < n; i++ )
        printf("%d ", a[i]);
    printf("\n");
}


// driver function 
int main()
{
    int n;
    scanf("%d", &n);
    int a[n] = {};
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    print(a,n);
    MergeSort(a , n);
    print(a,n);
}