
/*
find number of non-increasing sequences of length k with numbers in range [1, n]
dp solution
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = 1e9+7;

void solve() {
        int n,k;
	cin>>n>>k;
	int dp[n+1][k+1];

	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=n; i++)         // starting number of the sequence 
	{
	        for(int j=1;j<=k;j++)   // j length
	        {
	                if(j==1)
	                        dp[i][j]= i;                    // length = 1, n = 5 - 5ways (1, 2, 3, 4, 5)
	                else if(i==1)                           // only 1 way 
                                dp[i][j] = 1;     
	                else 
                                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
	        }
	}
	cout<<dp[n][k]<<endl;
}

signed main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        solve();
}