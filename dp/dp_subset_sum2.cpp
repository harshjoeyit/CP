#include<bits/stdc++.h>
using namespace std;

#define int long long int 
#define vi vector<int> 

bool subset_sum(vi a, int sum)
{
    int n = a.size();
    int k = accumulate(a.begin(), a.end(), 0);
    vector<bool> dp(k+1, false);                            // marks dp[i] = 1 if the sum i is possible 

    dp[0] = 1;              // 0 sum is always possible for a empty subset  

    for(int i = 0; i < n; i++)
    {
        for(int j = k - a[i]; j >= 0; j--)
        {
            if(dp[j])
                dp[j + a[i]] = 1;               // marking all the possible sums 
        }       
    }

    for(int i = 0; i <= k; i++)
        cout << i << "-" << dp[i] << "\t";
    cout << endl;
    

    return dp[sum];
}

signed main()
{
    int n, sum;
    cin >> n >> sum;

    vi a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    if(subset_sum(a, sum))
        cout << "subset possible" << endl;
    else 
        cout <<"no such subset exists" << endl;
}