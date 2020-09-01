
/*
Smallest Element To the Farthest Right
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> smallestToRight(vector<int> &a) {
      int n = a.size();
      vector<int> ans(n, 0);
      map<int, int> mp;
      // if element has no element to right that is
      // smaller, then we put -1 
      mp[-1] = -1;

      for (int i = n - 1; i >= 0; i--) {
            auto it = mp.lower_bound(a[i]);     it--;
            // get the value(index) of this key
            ans[i] = it->second; 
            // we always store the farthest index, 
            // if the value occurs multiple times 
            if(mp.count(a[i]) == 0) {
                  mp[a[i]] = i;
            }
      }
      return ans;
}

int main() {
      int n;
      cin >> n;
      vector<int> a(n);
      for (int i = 0; i < n; i++) {
            cin >> a[i];
      }
      auto v = smallestToRight(a);
      
      for (int i = 0; i < n; i++) {
            cout << v[i] << " ";
      }
      cout << endl;
}