
/*
https://leetcode.com/contest/weekly-contest-193/problems/minimum-number-of-days-to-make-m-bouquets/

similar problems
https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/'
https://leetcode.com/problems/koko-eating-bananas/submissions/
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long 

bool check(vector<int>& bloom, int m, int k, int mid) {
      int c = 0, total = 0;
      int n = bloom.size();
      for(int i=0; i<n; i++) {
            if(bloom[i] <= mid) {
                  ++c;
                  if(c == k) {
                        ++total;
                        c = 0;
                  }
            } else {
                  c = 0;
            }
      }
      return (total >= m);
}
int minDays(vector<int>& bloom, int m, int k) { 
      int n = bloom.size();
      if(m*k > n) {
          return -1;
      }
      int high = 1, low = 1;
      for(auto val: bloom) {
            high = max(high, val);
      }
      int ans = INT_MAX, mid;
      while(low <= high) {
            mid = low + (high - low)/2;
            if(check(bloom, m, k, mid)) {
                  ans = mid;
                  high = mid-1;
            } else {
                  low = mid+1;
            }
      } 
      return ans;
}

signed main() {
      // stdin
}