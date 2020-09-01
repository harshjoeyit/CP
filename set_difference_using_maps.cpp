
/*

suppose there are two vectors a, b
(nums may repeat in any of them but count of each num is even, count = total freq of num in both vector included)
if we use operation similar to set difference, then we get 

a - b = elements that are only in v1 and not in v2 (all similar elements cancel out)
b - a = elements that are only in v2 and not in v1 (all similar elements cancle out)

we use maps to find these
*/

#include <bits/stdc++.h>

using namespace std;
#define int long long int

pair<vector<int>, vector<int>> setDifference(unordered_map<int, int> &mpa, unordered_map<int, int> &mpb) {
      vector<int> xsa, xsb;
      for(auto &p: mpa) {
            int key = p.first;
            int val = p.second;

            if(mpb.count(key)) {
                  if(val > mpb[key]) {
                        for(int i=0; i<(val - mpb[key])/2; i++) {
                              xsa.push_back(key);
                        }
                  } else if(val < mpb[key]){
                        for(int i=0; i<(mpb[key] - val)/2; i++) {
                              xsb.push_back(key);
                        }
                  } 
                  mpb.erase(key);
                  // skip if equal in both
            } else {
                  for(int i=0; i<val/2; i++) {
                        xsa.push_back(key);
                  }
            }
      }

      for(auto &p: mpb) {
            for(int i=0; i<p.second/2; i++) {
                  xsb.push_back(p.first);
            }
      }

      return make_pair(xsa, xsb);
}

void solve() {
      vector<int> a, b;
      unordered_map<int, int> mpa, mpb;
      // input
      for(auto x: a) {
            mpa[x] += 1;
      }
      for(auto x: b) {
            mpa[x] += 1;
      }
      // auto vecs = setDifference(mpa, mpb)
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      int t;
      cin >> t;
      while (t--)
            solve();
}