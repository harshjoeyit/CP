

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> boxes;

int main() {
      int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
            int l, b, h;
            cin >> l >> b >> h;
            vector<int> temp = {l, b, h};
            sort(temp.begin(), temp.end());
            // 1st - l
            // 2nd - b
            // 3rd - h
            // l >= b always
            boxes.push_back({temp[2], temp[1], temp[0]});
            boxes.push_back({temp[2], temp[0], temp[1]});
            boxes.push_back({temp[1], temp[0], temp[2]});
      }

      // now sort the boxes in order of decreasing base area
      auto comp = [](const vector<int> &a, const vector<int> &b) {
            return a[0] * a[1] > b[0] * b[1];
      };
      sort(boxes.begin(), boxes.end(), comp);

      int sz = boxes.size();
      vector<int> dp(sz, 0);
      vector<int> parent(sz, 0);

      for(int i=0; i<sz; i++) {
            parent[i] = i;
      }
      // stack can always have 1 box at least
      for (int i = 0; i < sz; i++) {
            // height of individual box
            dp[i] = boxes[i][2];    
      }

      // The problem now is similar to 
      // max sum increasing subsequence 
      int ans = dp[0], ansi = 0;

      for (int i = 1; i < sz; i++) {
            for (int j = 0; j < i; j++) {
                  // try to place ith box on top of jth box 
                  // update max reached height for ith box
                  // box can only be stacked on top if l, b are strictly less 
                  if(boxes[j][0] > boxes[i][0] && boxes[j][1] > boxes[i][1]) {
                        int h = boxes[i][2] + dp[j];
                        if(h > dp[i]) {
                              dp[i] = h;
                              parent[i] = j;
                        }
                  }
            }
            if(dp[i] > ans) {
                  ans = dp[i];
                  ansi = i;
            }
      }

      // heights for each box, when it is at the top
      for (int i = 0; i < sz; i++) {
            cout << dp[i] << " ";
      }
      cout << "\n";
      for (int i = 0; i < sz; i++) {
            cout << parent[i] << " ";
      }
      cout << "\n";

      cout << ans << endl;
}