#include<bits/stdc++.h>
using namespace std;

#define int long long 

int modEx(int x = 3, int p = 1) {
   int ans = 1;
   while(p > 0) {
      if(p&1)
         ans *= x;
      p = p >> 1;
      x = x*x;
   }
   return ans;
}

void solve() {
    cout << modEx();
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}