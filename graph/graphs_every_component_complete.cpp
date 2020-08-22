
/*
check if every component is a complete graph
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int mxN = 150005;
vector<int> g[mxN];
int degree[mxN];
bool vis[mxN];
vector<int> component;

void dfs(int u) {
      vis[u] = 1;
      component.push_back(u);
      for(auto v: g[u]) {
            if(!vis[v]) {
                  dfs(v);
            }
      }
}

void solve() {
      int n, m;
      cin >> n >> m;
      for(int i=0; i<m; i++) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
            degree[x] += 1;
            degree[y] += 1;
      }
      bool flag = 1;
      for(int i=1; i<=n; i++) {
            if(flag == 0) {
                  break;
            }
            if(!vis[i]) {
                  component.clear();
                  dfs(i);
                  int s = component.size();
                  for(auto v: component) {
                        if(degree[v] != s-1) {
                              flag = 0;
                              break;
                        } 
                  }
            }
      }
      if(flag) {
            cout << "YES\n";
      } else {
            cout << "NO\n";
      }     
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      solve();
}

/*
more simpler solution 

#include <bits/stdc++.h>
using namespace std;
const int mxN = 150010;
vector<int> g[mxN];
bool vis[mxN];
 
void dfs(int a, int & v_cnt, int & e_cnt) {
	assert(!vis[a]);
	vis[a] = true;
	
      ++v_cnt;
	e_cnt += g[a].size();

	for(int b : g[a])
		if(!vis[b])
			dfs(b, v_cnt, e_cnt);
}
 
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	while(m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for(int i = 1; i <= n; ++i)
		if(!vis[i]) {
			
                  int v_cnt = 0, e_cnt = 0;
			dfs(i, v_cnt, e_cnt);
			
                  if(e_cnt != (long long) v_cnt * (v_cnt - 1)) {
				puts("NO");
				return 0;
			}
		}
            
	puts("YES");
}

*/