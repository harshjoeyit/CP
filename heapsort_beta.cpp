#include<bits/stdc++.h>
using namespace std;


void Heapify( int A[] , int i , int n)
{
    int left = 2*i;
    int right = 2*i + 1;
    int max;

    if( ( left <= n ) && ( A[left] > A[i] ) )
        max = left;
    else
    max = i;

    if( ( right <= n) && (A[right] > A[max]) )
        max = right;
    
    if( max = right )
        swap( A[i] , A[max] );
    
    Heapify( A , max , n);
}


void BuildMaxHeap( int A[] , int n )
{
    for(int  i = n/2; i >= 1; i-- )
        Heapify( A , i , n);
}


void Heapsort( int A[] , int n )
{
    BuildMaxHeap(A , n);
    for( int i = n; i >= 1; i-- )
    {
        swap( A[1] , A[i] );
        n = n-1;
        Heapify( A , 1 , n);
    }
}

int main()
{
    int A[] = { 9,8,7,6,5,4,3,2,1 }; 
    int n = sizeof(A)/sizeof(A[0]);

    for( int i = 0; i<n; i++ )
        cout<<A[i]<<" "; 

    Heapsort( A , n );

    for( int i = 0; i<n; i++ )
        cout<<A[i]<<" ";
}