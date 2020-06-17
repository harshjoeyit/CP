#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {

      // max_element and min_element
      // can be used on 
      // vectors, list, unordered_sets, unordered_maps(key is compared), sets, maps

      unordered_set<int> nums = {2, 1, 3, 4, 6, 1, 11, 10};
      cout << *max_element(nums.begin(), nums.end()) << endl;

      unordered_map<int, int> mp = {{1, 10}, {3, 2}, {2, 1}, {4, 2}, };
      auto it = max_element(mp.begin(), mp.end());
      cout << it->first << " " << it->second << endl; 

      it = min_element(mp.begin(), mp.end());
      cout << it->first << " " << it->second << endl;

}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      solve();
}