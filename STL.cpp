#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {

      // ......................................................................

      // Some important constructors 

      vector<int> v = {5, 2, 3, 3, 3, 4, 2, 4, 5, 5, 4, 3, 2, 2};
      
      // important constructors for sets
      unordered_set<int> ust(v.begin(), v.end());
      set<int> st(v.begin(), v.end());

      vector<pair<int, int>> v1 = {{1,2}, {3, 4}};
      
      // important constuctors for maps
      unordered_map<int, int> mp(v1.begin(), v1.end());
      map<int, int> ump(v1.begin(), v1.end());
      

      // .......................................................................

      // max_element and min_element can be used on
      // vectors, list, unordered_sets, unordered_maps(key is compared), sets, maps

      unordered_set<int> nums = {2, 1, 3, 4, 6, 1, 11, 10};
      cout << *max_element(nums.begin(), nums.end()) << endl;

      unordered_map<int, int> mp = {{1, 10}, {3, 2}, {2, 1}, {4, 2}, };
      auto it = max_element(mp.begin(), mp.end());
      cout << it->first << " " << it->second << endl; 

      it = min_element(mp.begin(), mp.end());
      cout << it->first << " " << it->second << endl;



      // using custom comparison with max, min, min_element, max_element function
      vector<string> v = {"abds", "ds", "sdsds", "sdrsdf"};

      auto comp = [](const string &a, const string &b) {
            return a.length() < b.length();
      };

      cout << *max_element(v.begin(), v.end(), comp) << "\n";
      cout << *min_element(v.begin(), v.end(), comp) << "\n";

      cout << max({"asdas", "sd"}, comp) << "\n";
      cout << min({"asdas", "sd"}, comp) << "\n";
   
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      solve();
}