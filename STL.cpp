#include<bits/stdc++.h>
using namespace std;
#define int long long int

// custom comparison function 
bool customComp(const pair<int, int> &a, const pair<int, int> &b) {
      return a.second < b.second;
}

void solve() {

      // Some important constructors 

      vector<int> v = {5, 2, 3, 3, 3, 4, 2, 4, 5, 5, 4, 3, 2, 2};
      
      // set from vector
      unordered_set<int> ust(v.begin(), v.end());
      set<int> st(v.begin(), v.end());

      vector<pair<int, int>> v1 = {{1,2}, {3, 4}};
      
      // map from vector 
      unordered_map<int, int> mp(v1.begin(), v1.end());
      map<int, int> ump(v1.begin(), v1.end());
      

      // .......................................................................

      /*
      max_element and min_element can be used on
      vectors, list, unordered_sets, unordered_maps(key is compared), sets, maps
      */

      unordered_set<int> nums = {2, 1, 3, 4, 6, 1, 11, 10};
      cout << *max_element(nums.begin(), nums.end()) << endl;

      unordered_map<int, int> mp = {{1, 10}, {3, 2}, {2, 1}, {4, 2}, };
     
      // max_element
      auto it = max_element(mp.begin(), mp.end());
      cout << it->first << " " << it->second << endl; 
      // min_element
      it = min_element(mp.begin(), mp.end());
      cout << it->first << " " << it->second << endl;

      // using custom comparitor 
      // it --> {key, val}, val is max in map
      it = max_element(mp.begin(), mp.end(), customComp);
      cout << it->first << " " << it->second << endl; 

      // using custom comparison
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