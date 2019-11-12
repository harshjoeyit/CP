#include<iostream>
using namespace std;



// brute force approach
int main()
{
    int a[] = {7,9,8,5,6,0,2,1};
    int size = sizeof(a)/sizeof(int);
    int j,k,i;

    for( i = 0; i<size; )
    {   
        for( j = i+1; (a[i]>a[j])&& (j<size); j++ );                //finding j for which a[j] > a[i]
        if( j<size )
        {   
            for( k = i; k<j; k++ )                                  // replacing all the elements until the index j
                a[k] = a[j]; 
                i = j;                                              // starting again form j
        }
        else
            ++i;                                                    // if no element greater than a[i]  is found in the array  after a[i] , start from next index
    }
    for( int i = 0; i<size; i++ )
        cout<<a[i]<<" ";
}