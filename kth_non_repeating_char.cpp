#include<bits/stdc++.h>
using namespace std;

int kth_non_repeating_char(string &s, int k) {
      string s;
      cin >> s;
      int k;
      cin >> k;

      unordered_map<char, int> ump;

      for (int i = 0; i < s.length(); i++){
            if(ump.count(s[i])) {
                  ump[s[i]] = -1;
            } else {
                  ump[s[i]] = i;
            }
      }

      vector<pair<char, int>> nonreps;
      for(auto p: ump) {
            if(p.second != -1) {
                  nonreps.push_back(p);
            }
      }

      auto comp = [](pair<char, int> &a, pair<char, int> &b) {
            return a.second < b.second;
      };
      sort(nonreps.begin(), nonreps.end(), comp);
      if(k > nonreps.size()) {
            cout << -1 << "\n";
            return 0;
      }

      cout << nonreps[k - 1].first << endl;
}

int main()
{
    int k;
    string s;
    cin >> s;
    cin >> k;

    int i = kth_non_repeating_char(s, k);
    cout << s[i] << endl;
}