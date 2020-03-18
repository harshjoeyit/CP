#include<bits/stdc++.h>
using namespace std;

// for a given money and changes in denominaion - find the minimum no of coins to return for the change
// problem is same as integer knapsack


// top down approach
int table[128];

// .......................................................some error
// int makeChange(int n, int change[], int types)
// {
//     if(n < 0) return -1;
//     if(n == 0) return 0;
//     if(table[n] != -1) return table[n];

//     int ans = INT_MAX;
//     for(int i = 0; i < types; i++)
//         ans = min(ans, makeChange(n - change[i], change, types));

//     return (table[n] = ans + 1);
// }   


int main()
{
    int change[] = {1, 5, 7, 11};
    int money = 30;
    int types = sizeof(change)/sizeof(int);
    memset(table, -1, sizeof(table));

    // bottom up approach
    int dp[types+1][money+1];
    memset(dp, 0, sizeof(dp));

    for(int i = 0; i <= types; i++)      // if money is = 0
        dp[i][0] = 0;

    for(int i = 0; i <= money; i++)     // if no change is avlbl = 0
        dp[0][i] = 0;                   

    for(int i = 1; i <= types; i++)
    {
        for(int j = 1; j <= money; j++)
        {
            if(j < change[i-1])                 // item cannot contribute in knapsack
                    dp[i][j] = dp[i-1][j];          // so do best we can do without including this item

            else
                dp[i][j] = j / change[i-1] + dp[i-1][j % change[i-1]];
        }                   // curr      +    // best with the remaining j % change[i]
    }

    for(int i = 1; i <= types; i++)
    {
        for(int j = 1; j <= money; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    cout << dp[types][money] << endl;
    
    cout << makeChange(money, change, types) << endl;
    for(int i = 1; i <= money; i++)
        cout << table[i] << " ";
    cout << endl;

}
