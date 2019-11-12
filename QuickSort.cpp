#include<bits/stdc++.h>
using namespace std;

// we could use a randomized partion function for chossing the pivot ( arandom index rather than always the last )
// we would then swap a[end] and a[randomized]
// and set our pivot to a[end] , continue
// this reduces our probaility of finding the worst case time complexity of O(n^2)

int Partition( int A[] , int start , int end )
{
    int Pivot = A[end];
    int Pindex = start;
    
    for( int i = start ; i < end; i++ )
        if( A[i] <= Pivot )
            swap( A[i] , A[Pindex++] );
    
    swap( A[Pindex] , A[end] );             // although the A[end] and the pivot have the same values , we cannot swap with Pivot ?????
    return Pindex;
} 


void QuickSort( int A[] , int start , int end )
{
    if( start < end )
    {
        int Pindex = Partition( A , start , end );
        QuickSort( A, start , Pindex - 1);
        QuickSort( A, Pindex + 1, end );
    }
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
    int a[] = { 7,2,1,6,8,5,3,4 };
    int n = sizeof(a)/sizeof(int);

    print(a,n);
    QuickSort(a , 0 , n-1);
    print(a,n);
}