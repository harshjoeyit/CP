
/*
optimal binary search tree

similar to combine array with minimum cost 

some keys and their frequencies are given - find the minimal cost of searching 
cost depends how far is the node from the root
dis = 0 , cost = 1
dis = 1, cost = 2 
...
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int mxN = 105;
int keys[mxN];
int freq[mxN];
int dp[mxN][mxN];                   // dp[x][y] denotes minimal cost for a BST including only keys index [x..y]    ,  ans = dp[1][n]
int prefix[mxN];                 

void solve() {
      int n;
      cin >> n;
      for(int i=1; i<=n; i++) {
            cin >> keys[i];
      }
      for(int i=1; i<=n; i++) {
            cin >> freq[i];
      }
      for(int i=1; i<=n; i++) {
            prefix[i] += prefix[i-1] + freq[i];
      }

      memset(dp, 0, sizeof(dp));
      
      for(int i=1; i<=n; i++) {                                         // BST with one node 
            dp[i][i] = freq[i];
      }     

      for(int j=1; j<=n; j++) {                                   // j - denotes length of current segment 
            for(int i=1; i<=n-j+1; i++) {
                  // segment = i...i+j-1
                  if(j == 1) {
                        dp[i][i+j-1] = freq[i];
                  } else {
                        int L = i, R = i+j-1;
                        int curr, mn = INT_MAX, sum;
                        sum = prefix[R] - prefix[L-1];
                        
                        for(int k=L; k<=R; k++) {                 // in the range [L, R] - we make every index as root
                              curr = dp[L][k-1] + dp[k+1][R];
                              mn = min(mn, curr);
                        }
                        dp[L][R] = sum + mn;
                  }
            }
      }
      for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                  cout << dp[i][j] << " ";
            }cout << endl;
       }
      cout << dp[1][n] << endl;
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      solve();
}