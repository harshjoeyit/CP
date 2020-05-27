#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int mxN = 3e5+10;
int parent[mxN];                          // for storing the right most knight 
int winner_parent[mxN];                   // for storing the winner parent of a range 
int ans[mxN];                             // ans 

void make_sets() {
      for(int i=0; i<mxN; i++) {
            parent[i] = i;
            winner_parent[i] = i;
      }
}
int find_set(int a) {                     // finding winner parent of the knight a
      if(a == winner_parent[a]) {
            return a;
      }
      return winner_parent[a] = find_set(winner_parent[a]);
}
void union_sets(int a, int w) {           // w is winner of knight a 
      a = find_set(a);
      w = find_set(w);
      if(a != w) {
            winner_parent[a] = w;
      }
}

void solve() {
      int n, m;
      cin >> n >> m;
      make_sets();

      for(int fight=0; fight<m; fight++) {
            int l, r, winner;
            cin >> l >> r >> winner;

            vector<int> pos;        // the knight that actually fight after elimination on some 
            for(int knight = l; knight <= r; knight = parent[knight] + 1) {        
                  pos.push_back(knight);                    
                  ans[find_set(knight)] = winner;           // kight beaten by find_set(knight) whos is now beaten by winner
                  union_sets(knight, winner);               
            }
            for(auto x: pos) {                              // change parent of all the knights who faught to r (rightmost knight)
                  parent[x] = r;
            }
      }
      for(int i=1; i<=n; i++) {
            if(ans[i] == i) {       //get beaten by nobody
                  ans[i] = 0;
            }
            cout << ans[i] << " ";
      }cout << endl;
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      solve();
}