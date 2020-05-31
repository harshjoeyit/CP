
/*
Some people with unique IDs are statnding in the queue
before breaking the queue each person notes down the person ID before and after him 
for the first person person before him is 0 and similarly for the last person person after him is 0

we need to form the queue back 
*/



#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {
      int n;
      cin >> n;
      int ans[n];
      unordered_map<int, int> mp;
      unordered_set<int> st1, st2;
      for(int i=0; i<n; i++) {
            int x, y;
            cin >> x >> y;
            mp[x] = y;                                // y is standing after x
            st1.insert(x);                            // standing before a person   
            st2.insert(y);                            // standing after a person 
            
            if(x == 0) {            
                  ans[1] = y;                         // the second number in the sequence 
            }
      }
      for(auto x: st1) {                              // we find a person that is standing before nobody - means he the first one in the queue
            if(st2.count(x) == 0) {
                  ans[0] = x;                         // the first number in the sequennce
                  break;
            }
      }
      // we have found the first two person stading - we can find the rest using mp
      for(int i=0; i<n; i++) {
            if(i >= 2) {
                  ans[i] = mp[ans[i-2]];
            }
            cout << ans[i] << " ";
      }cout << endl;
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      solve();
}