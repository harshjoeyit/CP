
/*
	Distrubute candies to children, given they can get [0 - a[i]] candies, such that
	no candies remain after distribution 
*/

#include <bits/stdc++.h>
 
using namespace std;
int mod=1e9+7; 
 
int main()
{
    int n,k;				// k - candies,  n- children 
    cin >> n >> k;		
    int a[n+1];				// a[i] = maximum candies one can get

    for(int i=1;i<=n;i++)    
        cin >> a[i];

    int dp[n+1][k+1];		// dp[i][j] - denotes no of ways to distribute j candies in 1....i children


    dp[0][0]=1;				// 0 candy - 0 children

    for(int i=1;i<=k;i++)  // 0 children - k candies	- candies remain spare so 0 ways
        dp[0][i]=0;
    
    for(int i=1;i<=n;i++)
    {
        int sums[k+1];		
        sums[0]=dp[i-1][0];
        for(int j=1;j<=k;j++)		// prefix sum - Sum of dp[i-1][0...j] - ways i-1 candies can be distrubuted among j children
        {
            sums[j]=(sums[j-1]+dp[i-1][j])%mod;  
        }

        for(int j=0;j<=k;j++)
        {
            int tr = sums[j];  				//Sum of dp[i-1][0...j]
            int unreachable = j-a[i]-1;  		// We need to subtract the sum of the first "unreachable" elements (dp[i-1][0...unreachable])
            if(unreachable >= 0)
            {
                tr=(tr-sums[unreachable]+mod)%mod;  ///Add mod to make sure that "tr-sums[unreachable]" is not negative.
            }
            dp[i][j]=tr;
        }
    }
  	cout << dp[n][k] << endl;
    return 0;
}