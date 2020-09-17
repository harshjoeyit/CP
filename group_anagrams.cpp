#include <bits/stdc++.h>
using namespace std;

// brute force 
// pick one string at a time traverse all other strings 
// and if match is found then mark this string vis and keep on pushing all matches in the ans vector

// more efficient approach 
map<vector<int>, vector<string>> mp;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
      if(strs.size() == 0) {
            return {};
      }
      int n = strs.size();
      mp.clear();
      
      for(int i=0; i<strs.size(); i++) {
            vector<int> temp(26, 0);
            for(auto &c: strs[i]) {
                  temp[c - 'a'] += 1;
            }
            mp[temp].push_back(strs[i]);
      }
      vector<vector<string>> ans;
      for(auto p: mp) {
            ans.push_back(p.second);
      }
      return ans;
}


// best approach
vector<vector<string>> groupAnagrams(vector<string>& strs) {
      if(strs.size() == 0) {
            return {};
      }      
      vector<vector<string>> ans;
      unordered_map<string, int> group;
      for(auto &s: strs) {
            string cpy = s;
            sort(cpy.begin(), cpy.end());
            if(group.count(cpy) == 0) {
                  group[cpy] = ans.size();
                  ans.push_back({});
            } 
            ans[group[cpy]].push_back(s);
      }
      return ans;
}

int main() {
      vector<string> strs;
      int n;
      cin >> n;
      while(n--) {
            string s;
            cin >> s;
            strs.push_back(s);
      }
      auto ans = groupAnagram(strs);

      for(auto v: ans) {
            for(auto s: v) {
                  cout << s << " ";
            }
            cout << endl;
      }
}