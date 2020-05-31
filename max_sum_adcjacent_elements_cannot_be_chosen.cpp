#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;


int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> dp(n);

    // dp[i] - tells the maxsum if the array of the size i+1 is chosen, 
    // we can divide it into subproblems 

    dp[0] = max(a[0], 0);
    dp[1] = max(dp[0], a[1]);

    for(int i = 2; i < n; i++)
    {
        if(a[i] < 0)
            dp[i] = max(dp[i-1], dp[i-2]);
        else
            dp[i] = max(dp[i-2] + a[i], dp[i-1]);
    }

    for(auto x : dp)
        cout << x << " ";
    cout << endl;

}