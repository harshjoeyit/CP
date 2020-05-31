#include<bits/stdc++.h>
using namespace std;

// program prints span[i] of a[i]
// span is the total number of immediately preceding elements that are less than or equal to the current element 
// a[j] <= a[i]
int main()
{
    int a[] = { 8,5,6,3,5,0,7,1,2,8,9,4,10,1};   // for for 8 its only 8  . for 6 its 6 & 5  , for 3 its only 3 and so on for 1 its only one
    int size = sizeof(a)/sizeof(int);
    
    for( int i = 0 ; i < size; i++ )
    {
        int count = 0 , k = i , j;
        for( j = i ; j >= 0; j-- )
        {
            if( (a[j] <= a[i])  && (j == k) )
            {
                ++count;
                --k;
            }
        }   
        cout<<"span["<<i<<"] of "<<a[i]<<" = "<<count<<endl;
    }
}