#include<bits/stdc++.h>
using namespace std;

int main()
{
    
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> dp(n, 1);

    int maxlen = 1;
    for(int i = 1; i < n; i++)
    {   
        int max = 0;
        for(int j = 0; j < i; j++)
            if((v[j] < v[i]) && (dp[j] > max))
                max = dp[j];
        
        dp[i] = max + 1;
        if(dp[i] > maxlen)
            maxlen = dp[i];
    }   

    for(auto &x: dp)
        cout << x << " ";
    cout << endl;

    cout << maxlen;
}