#include<bits/stdc++.h>
using namespace std;

int maxJumps(vector<int>& arr, int d) {
      if(arr.size() == 1) {
            return 1;
      }
      int n = arr.size();
      int maxJumpFrom[n];
      for(int i=0; i<n; i++) {
            maxJumpFrom[i] = 1;
      }
      
      multimap<int, int> mp;

      for(int i=0; i<n; i++) {
            mp.insert(pair<int, int>(arr[i], i));
      }

      int h, j, left, right, mj, ans = 1;
      for(auto p: mp) {
            h = p.first;
            j = p.second;
            left = max(0, j-d);
            right = min(n-1, j+d);
            mj = 0;

            for(int i=j; i>=left; i--) {
                  if(arr[i] > h) {
                        break;
                  } else if(arr[i] != h) {
                        mj = max(mj, maxJumpFrom[i]);
                  }
            }

            for(int i=j; i<=right; i++) {
                  if(arr[i] > h) {
                        break;
                  } else if(arr[i] != h) {
                        mj = max(mj, maxJumpFrom[i]);
                  }
            }
            
            maxJumpFrom[j] += mj;
            ans = max(ans, maxJumpFrom[j]);
      }
      return ans;
}

int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      int n, d;
      // cin >> n >> d;
      vector<int> v = {59,8,74,27,92,36,95,78,73,54,75,37,42,15,59,84,66,25,35,61,97,16,6,52,49,18,22,70,5,59,92,85};
      // for(auto &x: v) {
      //       cin >> x;
      // }
      cout << maxJumps(v, d);
}