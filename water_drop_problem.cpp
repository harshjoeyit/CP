

/*
https://www.geeksforgeeks.org/water-drop-problem/
*/

#include <bits/stdc++.h>
using namespace std;

int drops(int length, vector<int> &pos, vector<int> &speed) {
      int n = pos.size();
      // <pos, time>
      vector<pair<int, double>> a(n);

      for (int i = 0; i < n; i++) {
            a[i].first = pos[i];
            a[i].second = ((length - pos[i]) * 1.0) / speed[i];
      }

      // sort according to position 
      sort(a.begin(), a.end());

      int finalDrops = 0;
      stack<double> st;
      for (int i = n - 1; i >= 0; i--) {
            if(st.empty()) {
                  st.push(a[i].second);
            }

            if(a[i].second > st.top()) {
                  // found slower drop than drop on top, 
                  // this becomes new slower and 
                  // drops before this will merge into this
                  st.pop();
                  finalDrops += 1;
                  st.push(a[i].second);
            }
      }

      if(!st.empty()) {
            st.pop();
            finalDrops += 1;
      }

      return finalDrops;
}

int main() {
      int n, l;
      cin >> n >> l;
      vector<int> pos(n), speed(n);
      for (int i = 0; i < n; i++) {
            cin >> pos[i];
      }
      for (int i = 0; i < n; i++) {
            cin >> speed[i];
      }
      cout << drops(l, pos, speed);
}