

/*
string contains char from '0' to '9'
find the largest alternating seq of                   "any two diff chars" 

Note: Alternating seq should contain only 2 diff chars [0, 9]

example - 
22252522555
-  ---- -
ans = 6

1133441133
- -   - -
ans = 4

122211
--
ans = 2

12345
ans = 0
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int



vector<int> pos[10];

// this function recieves two arrays havinf indices of two diff chars 
int check(vector<int> &a, vector<int> &b) {
      int x = 0, y = 0, cnt1 = 0, cnt2 = 0;
      
      // alternating seq is of type 
      // 1212
      // or 2121
      // we start from char with lesser index 
      bool chooseFromFirst = true;
      if(a[0] > b[0]) {
            chooseFromFirst = false;
      }

      while(x < a.size() && y < b.size()) {
            // if its turn to choose the char1
            if(chooseFromFirst) {
                  // if we find index of char1 > char2 
                  if(a[x] > b[y]) {
                        // now we choose the char 2
                        chooseFromFirst = false;
                        // count of char 1 increases
                        cnt1 += 1;
                  } else {
                        // else we continue to move forward untill we find index > char2 index
                        x += 1;
                  }
            } else {
                  // this is similar to above process 
                  if(a[x] < b[y]) {
                        chooseFromFirst = true;
                        cnt2 += 1;
                  } else {
                        y += 1;
                  }
            }
      }

      return (min(cnt1, cnt2) + 1) * 2;
}

void solve() {
      string s;
      cin >> s;
      
      // storing indices of each char 
      for(int i=0; i<s.length(); i++) {
            int idx = s[i] - '0';
            pos[idx].push_back(i);
      }
      
      int ans = 0;

      // picking up two charachters 
      for(int i=0; i<9; i++) {
            for(int j=i+1; j<10; j++) {
                  // simple optimization for function call 
                  // no char of type1 + no of chars of type2 --> min of them * 2 > ans
                  if(2 * min(pos[i].size(), pos[j].size()) > ans) {
                        ans = max(ans, check(pos[i], pos[j]));
                  }
            }
      }

      cout << s.length() - ans << endl;
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      int t;
      cin >> t;
      while(t--)
      solve();
}