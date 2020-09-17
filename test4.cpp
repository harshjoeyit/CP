

#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> g[25];
int vis[25];
map<string, int> ump;
map<int, string> names;
map<int, string> res;

int toInt(string s) {
      // string to int
}

void storePath(vector<int> &curr, int bombs) {
      string path = "";
      for(auto u: curr) {
            path += names[u] + " ";
      }
      path += to_string(bombs);
      // store in map
      res.insert({bombs, path});
}

void dfs(int u, vector<int> &curr, int sum) {
      vis[u] = 1;
      curr.push_back(u);

      if(u == 2) {
            // 2 is vault
            storePath(curr, sum);
      }

      for (auto p : g[u]) {
            int v = p.first;
            int bombs = p.second;
            if(vis[v]) {
                  continue;
            }
            dfs(v, curr, sum + bombs);
      }

      curr.pop_back();
      vis[u] = 0;
}

vector<string> solve(string start, vector<string> &edges) {
      int k = 1;
      stringstream ss;
      ss << start;
      string word;

      while(ss >> word) {
            names[k] = word;
            ump[word] = k++;
      }

      for(auto e: edges) {
            string u = "";
            string v = "";
            int bombs;

            ss.clear();
            ss << e;
            while (ss >> word) {
                  if(u == "") {
                        u = word;
                        if(ump.count(word) == 0) {
                              names[k] = word;
                              ump[word] = k++;
                        }
                  }
                  else if (v == "") {
                        v = word;
                        if(ump.count(word) == 0) {
                              names[k] = word;
                              ump[word] = k++;
                        }
                  }
                  else {
                        bombs = toInt(word);
                  }

                  // make edge, x ---> y
                  int x = ump[u];
                  int y = ump[v];
                  g[x].push_back({y, bombs});
            }
      }

      vector<int> curr;
      int sum = 0;
      dfs(1, curr, sum);

      vector<string> ans;

      for(auto path: res) {
            ans.push_back(path.second);
      }

      return ans;
}

int main() {
      string start = "enter vault";
      vector<string> edges = {"enter corA 60", "corA vault 85", "enter vault 120"};
      vector<string> ans = solve(start, edges);
}