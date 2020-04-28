#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 1e9+7;
const int mxN = 1e5+10;
int n, cnt = 0;
vector<int> g[mxN];

int modEx(int x, int p) {
   int ans = 1;
   while(p > 0) {
      if(p&1)
         ans *= x;
      p = p >> 1;
      x = x*x;
   }
   return ans;
}

int dfs(int u, int p=-1) {
   int sz = 0; 
   for(auto v: g[u]) {
      if(v != p) {
         int s = dfs(v, u);
         if(s >= 2 && g[u].size() > 1) 
            ++cnt;
         sz += s;
      }
   }
   return sz + 1;
}  

void solve() {
   cin >> n;
   for(int i=0; i<n-1; i++) {
      int x, y;
      cin >> x >> y;
      --x, --y;
      g[x].push_back(y);
      g[y].push_back(x);
   }

   dfs(0);
   cout << (modEx(2, cnt) + 2) << "\n";
}   

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}