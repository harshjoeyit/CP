#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int mxN = 1005;
int price[mxN]; // price[i] = price for rod of length i
int dp[mxN];
int length;

int go(int curr_len) {
      if (curr_len == length) {
            return 0;
      }
      if (curr_len > length) {
            return -1e17;
      }
      if (dp[curr_len] != -1) {
            return dp[curr_len];
      }
      int ans = 0;
      for (int i = 1; i <= length; i++) {
            ans = max(ans, price[i] + go(curr_len + i));
      }
      return dp[curr_len] = ans;
}

void solve() {
      cin >> length;
      for (int i = 1; i <= length; i++)
      {
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


// another problem on rod cutting
// https://leetcode.com/contest/weekly-contest-201/problems/minimum-cost-to-cut-a-stick/

// length of rod is given, and position of the cuts is given 
// every cut cost price equal to length of the rod on which cut is made
// find minimum cost of the operation 

int dp[109][109];
vector<int> cuts;

int go(int st, int en, int L, int R) {
      if (st < 0 || en >= cuts.size() || st > en) {
            // no cut to make
            return 0;
      }
      if (st == en) {
            // there is only one cut to make
            return R - L;
      }

      int &ans = dp[st][en];
      if (ans != -1) {
            return ans;
      }

      ans = INT_MAX;
      for (int i = st; i <= en; i++) {
            ans = min(ans, (R - L) + go(st, i - 1, L, cuts[i]) + go(i + 1, en, cuts[i], R));
      }

      return ans;
}

int minCost(int n, vector<int> &Cuts) {
      cuts = vector<int>(Cuts);
      sort(cuts.begin(), cuts.end());
      memset(dp, -1, sizeof(dp));

      return go(0, cuts.size() - 1, 0, n);
}