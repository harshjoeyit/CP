

/*
All problems shortest path 
can be solved using greedy approach using Dijkstra Algorithm 
but we have a problems when edges are negetive


Also it can be solved by Dynamic programming 
which works on negetive edges too 
Floyed Warshall 

To detect a negetive weight cycle we do - 

If distance of any verex from itself 
becomes negative, then there is a negative 
weight cycle. 
*/

#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> dis;

void floyedWarshall(vector<vector<int>> &dis) {
      for(int k=0; k<n; k++) {
          // k is intermedia vertex 
          // when the path  i ----> k ----> j 
          // is considered 
            for(int i=0; i<n; i++) {
                  for(int j=0; j<n; j++) {
                        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                  }
            }
      }

      for(int i=0; i<n; i++) {
          if(dis[i][i] < 0) {
              cout << "negetive weight cycle present!\n";
              break;
          }
      }
} 

int main() {
      cin >> n >> m;
      dis.assign(n, vector<int>(m, 10000000));

      for(int i=0; i<m; i++) {
            int x, y, w;
            cin >> x >> y >> w;
            dis[x][y] = w;
      }

      // distance to itself = 0
      for(int i=0; i<n; i++) {
            dis[i][i] = 0;
      }

      floyedWarshall(dis);

      for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                  cout << i << "->" << j << "=" << dis[i][j] << "\n";
            }
      }
}