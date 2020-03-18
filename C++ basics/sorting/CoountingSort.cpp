#include<bits/stdc++.h>
using namespace std;

// counting sort
void CountingSort( int a[] , int size , int range )
{
    int count[range+1] = {};
    int output[size];

    for( int i = 0; i<size; i++ )
        ++count[a[i]];                  // counting

    for( int i = 0; i< range-1; i++ )     
        count[i+1] += count[i];

    for( int i = 0; i<size; i++ )
    {                   
        int value = a[i];                   // value is the current block value
        int index = count[value]--;         // index is blockvalue in count , decrementing the index value stored in the count array for the sake of repeated elements
        output[index-1]  = value;           // storing the value in the index -1 block in output 
    }

    for( int i = 0; i<size; i++ )
        a[i] = output[i];
}

int main()
{
    int a[] = {3,1,0,0,6,1,9,3,8,1};
    int size = sizeof(a)/sizeof(int);
    int range = 10;                             // decided on the basis of range of the data 
    
    for( int i = 0; i<size; i++ )
        cout<<a[i]<<" ";
    cout<<endl;

    CountingSort(a,size,range);

    for( int i = 0; i<size; i++ )
        cout<<a[i]<<" ";
    
}