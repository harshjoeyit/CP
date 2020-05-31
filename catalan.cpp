#include<bits/stdc++.h>
using namespace std;

vector<int> dp(500);
int catalan(int n)
{
    if(dp[n] != 0)
        return dp[n];
    
    dp[n] = 0;
    for(int i = 1; i <= n; i++)
        dp[n] += catalan(i-1) * catalan(n-i);
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    dp[0] = 1;
    cout << catalan(n) << endl;

    for(int i = 0; i <= n; i++)
        cout << dp[i] << " ";
    cout << endl;
}