#include<bits/stdc++.h>
using namespace std;


struct stackItem
{
    int height;
    int index;
};


int maxRectangleArea( int A[] , int n )
{
    int i , maxArea = -1 , top = -1, left , currentArea;
    struct stackItem *S = (struct stackItem *)malloc(sizeof(struct stackItem ) * n);

    for( i =0; i <= n; i++ )
    {
        while( top >= 0 &&  ( i == n || S[top].height > A[i] ))  // run - when array has ended i == n
        {                                                          //    - when topmost stack element has higher value(height) than current array element 
            if( top > 0)                                            // in both the cases top >=0 
                left = S[top - 1].index;
            else
                left = -1;

            currentArea = ( i - left - 1 )* S[top].height;
            --top;
            if( currentArea > maxArea )
                maxArea = currentArea;
        }

        if( i<n)                                                    // push operation ( i<n  )  until there are elements in the array
        {
            ++top;
            S[top].height = A[i];
            S[top].index = i;
        } 
    } 
    return maxArea;
}





int main()
{
    int a[] = {1,2,3,4,5,3,3,2};                          // hieghts of the histogram bars
    int size = sizeof(a)/sizeof(int);

    cout<<"max area: "<<maxRectangleArea( a , size );
}