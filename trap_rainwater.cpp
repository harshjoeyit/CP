#include <bits/stdc++.h>
using namespace std;

// See 
// Brute Froce
// Stack Approach
// Two Pointer Approach

// best application O(n) - better running time
int trap(vector<int> &a) {
      if (a.size() == 0 or a.size() == 1) {
            return 0;
      }
      int n = a.size();
      int l[n], r[n];
      l[0] = a[0];
      r[n - 1] = a[n - 1];

      for (int i = 1; i < n; i++) {
            l[i] = max(a[i], l[i - 1]);
      }
      for (int i = n - 2; i >= 0; i--) {
            r[i] = max(a[i], r[i + 1]);
      }
      int ans = 0;
      for (int i = 0; i < n; i++) {
            ans += min(l[i], r[i]) - a[i];
      }
      return ans;
}


// my approach - O(n)
int fixStart(int idx, vector<int> &height) {
      int n = height.size();
      while(idx < n - 1 && height[idx] < height[idx + 1]) {
            idx += 1;
      }
      return idx;
}

int trap(vector<int>& height) {
      if(height.size() <= 2) {
            return 0;
      }        
      int ans = 0, n = height.size();
      int st, en=0;      
      while((st = fixStart(en, height)) < n-2) {
            // cout << "st: " << st << " ";
            en = st+1;
            while(en < n-1 && height[en] <= height[st]) {
                  en += 1;
            }
            // cout << " en: " << en << endl;
            int mx = min(height[st], height[en]);
            int contrib = 0;

            if(en == n-1 && mx < height[st]) {
                  int maxH = height[en];
                  for(int k=en-1; k>st; k--) {
                        maxH = max(maxH, height[k]);
                        contrib += maxH - height[k];
                  }
                  ans += contrib;
                  // cout << "contr: "<< contrib << endl;
                  continue;
            }

            for(int i=st + 1; i<en; i++) {
                  contrib += max(0, mx - height[i]);
            }
            // cout << "cont: " << contrib << endl; 
            ans += contrib;
      }
      return ans;
}

int main() {
}

/*
similar problem - find largest container for storing water 
*/