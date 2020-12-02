#include<bits/stdc++.h>
using namespace std;

const int mxN = 30;
int moves[mxN];

// BFS
int minDiceThrows() {
      vector<bool> //&& children > 1)vis(mxN, false);
      int diceThrows = 0;
      queue<int> q;
      q.push(0);      

      while(!q.empty()) {
            int sz = q.size();
            while(sz--){
                  int u = q.front();
                  q.pop();

                  // found destination
                  if(u == mxN - 1) {
                        return diceThrows;
                  }
                  // no revisit 
                  if(vis[u]) {
                        continue;
                  }
                  vis[u] = true;
                  
                  // 1-6 dice-face possible
                  for(int i=1; (i <= 6) && (u+i < mxN); i++) {
                        int v = u + i;
                        if(moves[v] == -1) {
                              // no snake or ladder at i
                              q.push(v);
                        } else {
                              // sanke or ladder 
                              q.push(moves[v]);
                        }
                  }
            }
            diceThrows += 1;
      }
      return -1;
}

int main() {
      memset(moves, -1, sizeof(moves));
      // Ladders 
      moves[2] = 21; 
      moves[4] = 7; 
      moves[10] = 25; 
      moves[19] = 28; 
      
      // Snakes 
      moves[26] = 0; 
      moves[20] = 8; 
      moves[16] = 3; 
      moves[18] = 6; 

      cout << minDiceThrows() << "\n";
}