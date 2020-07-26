#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int mxN = 1005;
int price[mxN];               // price[i] = price for rod of length i 
int dp[mxN];
int length;

int go(int curr_len) {
      if(curr_len == length) {
            return 0;
      }
      if(curr_len > length) {
            return -1e17;
      }
      if(dp[curr_len] != -1) {
            return dp[curr_len];
      }
      int ans = 0;
      for(int i=1; i<=length; i++) {
            ans = max(ans, price[i] + go(curr_len+i));
      }
      return dp[curr_len] = ans;
}

void solve() {
      cin >> length;
      for(int i=1; i<=length; i++) {
            cin >> price[i];
      }
      memset(dp, -1, sizeof(dp));
      cout << go(0) << endl;          
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      solve();
}