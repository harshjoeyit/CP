
/*
- Destroying a crystal with health h[i], if power >= h[i], adds  1 point to score 
 -We may choose to add crystal health to power in exchange of 1 point (only if points > 0)

Given power of a laser, and healths of crystals 
find max score 
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
            if(p < health[i]) {
                  // if p < health[i]
                  // we recharge with largest health[i] possible - i.e. last one
                  if(i < n-1 && points > 0) {
                        p += health[n-1];
                        points -= 1;
                        n -= 1;
                        // reduce the array size, since 
                        // last crystal used up in recharging power 
                        
                        // process current crystal 
                        p -= health[i];
                        points += 1;
                  }
            }
            // destroy this crystal 
            p -= health[i];
            points += 1;
      }
      cout << points << endl;
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      solve();
}