#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {
      string s;
      getline(cin, s);
      stringstream ss(s);

      while(ss >> s) {
            cout << s << "-";
      }cout << endl;

      /*
      stringstream ss;
      string s1 = "this is a nice place tp sit";
      ss << s1;
      string word;
      while(ss >> word) {
            cout << word << endl;
      }
      
      string s2 = "here i am again!";
      ss.clear();
      ss << s2;
      while(ss >> word) {
            cout << word << endl;
      }
      */
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      solve();
}