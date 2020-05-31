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
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      solve();
}