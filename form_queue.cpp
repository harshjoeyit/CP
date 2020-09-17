
/*
Some people with unique IDs are statnding in the queue
before breaking the queue each person notes down the person ID before and after him 
for the first person person before him is 0 and similarly for the last person person after him is 0

we need to form the queue back 
*/



#include<bits/stdc++.h>
using namespace std;
#define int long long int

// the key is finding the first two persons
void solve() {
      int n;
      cin >> n;
      int ans[n];
      unordered_map<int, int> mp;
      // store id of person before and after
      unordered_set<int> before, after;
      for(int i=0; i<n; i++) {
            int x, y;
            cin >> x >> y;
            // mapping the after person
            mp[x] = y;
            
            before.insert(x);                              
            after.insert(y);                           
            
            if(x == 0) {            
                  // person standing at pos = 2
                  ans[1] = y;                         
            }
      }

      // now we find the first person of the queue
      // first person is the one who
      // can be found in before set but not after set sinec
      // he is not standing after anybody
      for(auto x: before) { 
            if(after.count(x) == 0) {
                  ans[0] = x;
                  break;
            }
      }

      // we have found the first two person stading - 
      // we can find the rest using mp
      for(int i=0; i<n; i++) {
            if(i >= 2) {
                  ans[i] = mp[ans[i-2]];
            }
            cout << ans[i] << " ";
      }
      cout << endl;
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      solve();
}