#include<bits/stdc++.h>
using namespace std;

// finding the max area of a rectangle in a histogram 
// brute force approach
// going to each bar and finding the max rectangle formed taking common the current bar ( or to say max commom height possible )
int main()
{
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