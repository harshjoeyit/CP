
/*
Solve a 3*3 puzzle 

*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

int isprime[] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1};
int p[9];
// <puzzle, steps>
unordered_map<int, int> dist;
queue<int> q;

void compute(int x, int y, int puzzle, int d) {
      int firstDig = (puzzle / p[x]) % 10;
      int secDig = (puzzle / p[y]) % 10;
      if(!isprime[firstDig + secDig]) {
            return;
      } 
      // swap numbers
      puzzle += (secDig - firstDig) * p[x] + (firstDig - secDig) * p[y];
      if(dist.count(puzzle) == 0) {
            dist[puzzle] = d + 1;
            q.push(puzzle);
      }
}

void findAllJumbledPuzzles() {

      p[8] = 1;
      for (int i = 7; i >= 0; i--) {
            p[i] = p[i + 1] * 10;
      }

            int puzzle = 123456789;
      q.push(puzzle);
      dist[puzzle] = 0;

      while(!q.empty()) {
            puzzle = q.front();
            q.pop();
            int d = dist[puzzle];

            for (int i = 0; i < 3; i++) {
                  for (int j = 0; j < 3; j++) {
                        int currPos = 3 * i + j;
                        int right = 3 * (i + 1) + j;
                        int down = 3 * i + 1 + j;
                        if (i < 2) {
                              compute(currPos, right, puzzle, d);
                        }
                        if (j < 2) {
                              compute(currPos, down, puzzle, d);
                        }
                  }
            }
      }
}

signed main() {
      int t;
      cin >> t;
      findAllJumbledPuzzles();
      while (t--) {
            int puzzle = 0, x;
            for (int i = 0; i < 3; i++) {
                  for (int j = 0; j < 3; j++) {
                        cin >> x;
                        puzzle = puzzle * 10 + x;
                  }
            }
            if(dist.count(puzzle)) {
                  cout << dist[puzzle] << "\n";
            } else {
                  cout << "-1\n";
            }
      }
}