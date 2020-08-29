#include<bits/stdc++.h>
using namespace std;
#define int long long int

int n, capc;
int dp[102][100005];

int go(int i, int capc, int val[], int wt[]) {
      if(i == n || capc < 0) {
            return 0;
      }
      int &ans = dp[i][capc];
      if(ans != -1) {
            return ans;
      }
      // we can always skip the current 
      ans = go(i+1, capc, val, wt);
      if(capc >= wt[i]) {
            // we may only include, if capacity allows 
            ans = max(ans, val[i] + go(i+1, capc - wt[i], val, wt));
      }

      return ans;
}

signed main() {
    cin >> n >> capc;
    int val[n];
    int wt[n];

    for(int i=0; i<n; i++)
        cin >> val[i];
    for(int i=0; i<n; i++)
        cin >> wt[i];

    memset(dp, -1, sizeof(dp));
    cout << go(0, capc, val, wt) << endl;
}