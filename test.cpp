#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int mxN = 3e5+10;
int parent[mxN];
int ans[mxN];

void make_sets() {
      for(int i=0; i<mxN; i++) {
            parent[i] = i;
      }
}
int find_set(int a) {
      if(a == parent[a]) {
            return a;
      }
      return parent[a] = find_set(parent[a]);
}
void union_sets(int a, int b) {
      a = find_set(a);
      b = find_set(b);
      if(a != b) {
            parent[b] = a;
            ans[b] = a;
      }
}

void solve() {
      int n, m;
      cin >> n >> m;
      make_sets();
      for(int fight=0; fight<m; fight++) {
            int l, r, winner;
            cin >> l >> r >> winner;
            for(int knight=l; knight<=r; knight++) {
                  union_sets(winner, knight);
                  knight = find_set(knight);
            }
      }
      for(int i=1; i<=n; i++) {
            cout << ans[i] << " ";
      }cout << endl;
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      solve();
}