#include<bits/stdc++.h>
using namespace std;

#define int long long int 
#define vi vector<int> 

bool subset_sum_possible(vi a, int sum)
{
    int n = a.size();
    vector<vector<bool>> dp;
    dp.assign(n+1, vector<bool>(sum+1));

    // If sum is 0, then answer is true 
    for (int i = 0; i <= n; i++) 
      dp[i][0] = true; 
   
    // If sum is not 0 and set is empty, then answer is false 
    for (int j = 1; j <= sum; j++) 
        dp[0][j] = false; 

    // dp[i][j] = 1 if it is possible to find subset from number in a 1 to i  that produces a sum equal to j, otherwies dp[i][j] = 0  

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= sum; j++)
        {
            if(j < a[i-1])
                dp[i][j] = dp[i-1][j];
                
            else if(j >= a[i-1])
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i-1]]);

        }       // if any of the conditions mentioned - is true dp[i][j] is true;
    }

       // uncomment this code to print table 
     for (int i = 0; i <= n; i++) 
     { 
       for (int j = 0; j <= sum; j++) 
          cout << dp[i][j] << " ";
       printf("\n");
     }

    return dp[n][sum];
}

signed main()
{
    int n, sum;
    cin >> n >> sum;

    vi a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    if(subset_sum_possible(a, sum))
        cout << "subset possible" << endl;
    else 
        cout <<" no such subset exists" << endl;
}