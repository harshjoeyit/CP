
/*
Correction in problem statement 
- we can choose a crystal only once 
- any crystal may be chosen on any iteration 
- the gicen order is not in which crystals are processed
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {
      int n, p;
      cin >> n;
      vector<int> health(n);
      for(int i=0; i<n; i++) {
            cin >> health[i];
      }
      cin >> p;
      // sort according to min health
      sort(health.begin(), health.end());
      int points = 0;

      for(int i=0; i<n; i++) {
            if(p >= health[i]) {
                  p -= health[i];
                  points += 1;
            } else {
                  // if p < health[i]
                  // then we decrement points and add the largest health[i] possible - last one
                  if(i < n-1 && points > 0) {
                        p += health[n-1];
                        points -= 1;
                        n -= 1;
                        // reduce the array size
                        
                        // process current crystal 
                        p -= health[i];
                        points += 1;
                  }
            }
      }
      cout << points << endl;
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      solve();
}