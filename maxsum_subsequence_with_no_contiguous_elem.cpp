#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n), dp(n);
    for(auto &x: v)
        cin >> x;

    dp[0] = max(v[0], 0);               // if the element is negetive then it need not be included 
    dp[1] = max(dp[0], v[1]);           // if elem is -ve then the sequence cannnot start here 

    for(int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i-2] + v[i], dp[i-1]);
    }
    for(auto &x: dp)
        cout << x << " ";
    cout << endl;
}