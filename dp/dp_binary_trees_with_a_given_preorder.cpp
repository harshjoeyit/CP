
/*
Given a preorder sequence -
count the number of binary trees possible 
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
      int n;
      cin >> n;
      vector<int> dp(n+1);
      // for 0, 1 node 
      dp[0] = dp[1] = 1;

      // we count nodes on the basis of number of nodes  
      // in left and right subtrees 
      for(int nodes=2; nodes<=n; nodes++) {
            // one of them is the root
            // we distribute nodes-1 in the left 
            // and right subtrees
            for(int left=0; left<=nodes-1; left++) {
                  int right = nodes-1-left;
                  dp[nodes] += dp[left] * dp[right];
            }
      }

      for(int i=0; i<=n; i++) {
            cout << dp[i] << " ";
      }cout << endl;
}