#include<bits/stdc++.h>
using namespace std;

int main()
{
    int val[] = {1,4,5,7};
    int wt[] = {1,3,4,5};
    int capacity = 7;
    int items = 4;

    int dp[items+1][capacity+1] = {};

    for(int i = 0; i <= items; i++)      // if capacity = 0
        dp[i][0] = 0;

    for(int i = 0; i <= capacity; i++)  // if items = 0
        dp[0][i] = 0;                   


    for(int i = 1; i <= items; i++)
    {
        for(int j = 1; j <= capacity; j++)
        {
            if(j < wt[i-1])          // array index 0 for item 1 // item cannot contribute in knapsack
                    dp[i][j] = dp[i-1][j];      // best can do without including the item

            else
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
                        // max of 
                        // current val + best we can do while including the item
                        // and
                        // the best we can do without including the item 
        } 
    }

    for(int i = 1; i <= items; i++)
    {
        for(int j = 1; j <= capacity; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    // the answer for the for the 
    // n items 
    // capacity of knapsack c
    // dp[n][c];

    cout << dp[items][capacity] << endl;
}