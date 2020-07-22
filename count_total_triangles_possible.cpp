#include <bits/stdc++.h>
using namespace std;

// array elements can be considered sides of the triangle 
// find the the total triangle possible
int nTriang(vector<int> &a) {
      const int mod = 1e9+7;
      sort(a.begin(), a.end());
      int n = a.size();
      int ans = 0;
      for(int i=n-1; i>=2; i--) {
            // first side1 is a[i]
            int j = 0, k = i-1;
            while(j < k) {
                  // side2 is a[k]
                  if(a[j] + a[k] > a[i]) {
                        // from j to k-1 all are valid for side3 
                        ans += k - j;
                        ans %= mod;
                        k -= 1;
                        // change side2 
                  } else {
                        j += 1;
                        // the sum of two sides is still less than third side 
                        // increase the value of third side 
                  }
            }
      }
      return ans;
}


int main() {
      vector<int> a = {1, 2, 2, 1, 1};
      cout << nTriang(a);
}