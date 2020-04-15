#include<bits/stdc++.h>
using namespace std;

// brute force - O(n^2)
void maxRecArea() {
    int a[] = {6,2,5,4,5,1,6};                          // hieghts of the histogram bars
    int size = sizeof(a)/sizeof(int);
    int max , MAX = -9999 ,area, x;

    for( int i = 0; i < size; i++ )                     // staring from 1st bar in histogram 
    {
        x = a[i];                                       // x keeps the value of minimum bar height in th current iteration
        max = -9999;                                    // max to find the max vallue of area in current iteration
        for( int j = i; j < size; j++ )                 // starting from current bar and goin to the end 
        {
            if( a[j] < x )                              // if lesser bar height is found then x is reassigned 
                x = a[j];
            area = x*( j-i+1);                          // IMP: area is calculated yb ( minimum bar height (x) * number of bars )(till the current iteration)
            if( area > max )                            // changing max
                max = area;
        }
        if( max > MAX)                                  // changing MAX
            MAX = max;
    }
    cout<<MAX;
}


#define height      first
#define index       second

int maxRectangleArea(int A[], int n) {
    int mxarea = -1, left , curr;
    stack<pair<int, int>> S;
        
    for(int i =0; i <= n; i++ ) {
        while( !(S.empty()) && ( i == n || S.top().height > A[i] )) {
            if( S.size() > 1) {                 // min 2 items 
                auto t = S.top();
                S.pop();
                left = S.top().index;           // 2nd item on the stack
                S.push(t);
            }                                             
            else
                left = -1;

            curr = (i - left - 1) * S.top().height;
            S.pop();

            if( curr > mxarea )
                mxarea = curr;
        }

        if(i < n)                                               
            S.push({A[i], i});
        
    } 
    return mxarea;
}




int main()
{
    int a[] = {1,2,3,4,5,3,3,2};                          // hieghts of the histogram bars
    int size = sizeof(a)/sizeof(int);

    cout<<"max area: "<<maxRectangleArea( a , size ) <<"\n";
}