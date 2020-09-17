#include<bits/stdc++.h>
using namespace std;

// variations 
// bridges 
// maximum sum subsequence 
// maximmum chain length - elements are pairs (a, b), (c, d) chain is formed when b < c , given a < b and d > c alwauys 

// similar problem 
// find largest bitonic sequence, (first increasing and then decreasing or only inc or only dec)
// Solution 
// find lis array from left 
// find list array from right 
// find max(left[i] + right[i] - 1)

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

    // for(auto &x: dp)
    //     cout << x << " ";
    // cout << endl;

    cout << maxlen << endl;
}