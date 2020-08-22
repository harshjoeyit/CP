#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int mxN = 1e4 + 10;
vector<pair<int, long double>> g[mxN];

long double dijkstra(int u, int dest) {
      vector<bool> vis(mxN, false);
      vector<long double> prob(mxN, 0);

      // probability is 1, since we start at this vertex 
      prob[u] = 1;
      // max priority queue
      priority_queue<pair<long double, int>> pq;
      pq.push({1, u});

      while (!pq.empty()) {
            auto currPair = pq.top();     pq.pop();
            int u = currPair.second;

            if (vis[u]) {
                  continue;
            }
            vis[u] = true;

            for (auto curr : g[u]) {
                  long double p = curr.second;
                  int v = curr.first;

                  // visit vertex v with maximum possible probability
                  if (prob[u] * p > prob[v]) {
                        prob[v] = prob[u] * p;
                        pq.push({prob[v], v});
                  }
            }
      }
      // return probability with which we reach dest, equals = 0 if cannot be visited
      return prob[dest];
}

double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end) {
      cout << fixed << setprecision(15);
      for (int i = 0; i < mxN; i++) {
            g[i].clear();
      }

      for (int i = 0; i < edges.size(); i++) {
            int x = edges[i][0];
            int y = edges[i][1];
            long double p = succProb[i];

            g[x].push_back({y, p});
            g[y].push_back({x, p});
      }

      return dijkstra(start, end);
}

void solve() {
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      int t;
      cin >> t;
      while (t--) {
            solve();
      }
}