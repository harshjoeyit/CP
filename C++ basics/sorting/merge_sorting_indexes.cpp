#include<bits/stdc++.h>
using namespace std;

void Merge( int *left, int *left2,  int l_size , int *right, int *right2, int r_size , int *A , int *B ) {
    int i , l , r;
    i = l = r = 0;

    while( (l < l_size) && (r < r_size) )
    {
        if( left[l] < right[r] )
        {
            B[i] = left2[l];
            A[i++] = left[l++];
        }
        else
        {
            B[i] = right2[r];
            A[i++] = right[r++];
        }
    }

    while(l < l_size)
    {
        B[i] = left2[l];
        A[i++] = left[l++];
    }
    while(r < r_size)
    {
        B[i] = right2[r];
        A[i++] = right[r++];
    }

}



void MergeSort( int *A , int n , int *B)
{
    if(n < 2)
        return;
    
    int mid = n/2;
    int *left = (int *)malloc( mid*sizeof(int) );
    int *right = (int *)malloc( (n-mid)*sizeof(int) );

    int *left2 = (int *)malloc( mid*sizeof(int) );
    int *right2 = (int *)malloc( (n-mid)*sizeof(int) );

    for( int i = 0; i < mid; i++ )
    {
        left[i] = A[i];
        left2[i] = B[i];
    }
    for( int i = mid; i < n; i++ )
    {
        right[i-mid] = A[i];
        right2[i-mid] = B[i];
    }
    
    MergeSort(left , mid , left2 );
    MergeSort(right , n-mid , right2 );
    Merge(left , left2 , mid , right , right2 , n-mid , A , B );
}



void print( int a[] , int n )
{
   cout<<"array: \n";
   for( int i = 0; i < n; i++ )
      cout<<a[i]<<" ";
   cout<<endl;
}


// driver function 
int main()
{
    int a[] = {9,2,5,1,6,4};
    int n = sizeof(a)/sizeof(int);
    int b[n];

    for(int i = 0; i < n; i++)
        b[i] = i;

    MergeSort(a, n, b);
    print(a,n);
    print(b,n);
}