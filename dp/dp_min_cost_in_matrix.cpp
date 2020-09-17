/*
There is a turtle at cell (0,0), it wants to go to cell(m,n)  but it can only go up (positive  direction) or right (positive  direction). 
Also, it can only move one unit per step.
Every cell  has a cost c(i,j) that the turtle needs to pay to use that cell.
What would be the minimum cost to reach the final cell (m,n)?
*/


#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int dp[10][10] = {0};

int main()
{
    int cost[3][3] = {{2,4,6}, {7,1,4}, {4,5,3}};

    dp[0][0] = cost[0][0];                              // base conditions

    for(int i = 1; i < 3; i++)                          // base conditions - travel staright
        dp[i][0] = dp[i-1][0] + cost[i][0];    

    for(int j = 1; j < 3; j++)                          // base conditions - travel staright
        dp[0][j] = dp[0][j-1] + cost[0][j];

    for(int i = 1; i < 3; i++)
        for(int j = 1; j < 3; j++)
            dp[i][j] = min( dp[i-1][j], dp[i][j-1] ) + cost[i][j];
        

            // m, n   
    cout << dp[2][2] << endl;

}