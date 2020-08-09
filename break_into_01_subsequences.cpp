
/*
given a binary string
like 0100000101... 

break this string into minimum number of subsequences that 
- each one  of type 01010101..., or 1010101...
- and each char occurs eaxactly once in each subsequence 
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {
      int n;
      cin >> n;
      string s;
      cin >> s;

      vector<int> endWithZero, endWithOne, ans(n);
      int seqNum;

      for(int i=0; i<n; i++) {
            seqNum = endWithOne.size() + endWithZero.size();
            if(s[i] == '0') {
                  if(endWithOne.empty()) {
                        endWithZero.push_back(seqNum);
                  } else {
                        seqNum = endWithOne.back();
                        endWithOne.pop_back();
                        endWithZero.push_back(seqNum);
                  }     
            } else {
                  if(endWithZero.empty()) {
                        endWithOne.push_back(seqNum);
                  } else {
                        seqNum = endWithZero.back();
                        endWithZero.pop_back();
                        endWithOne.push_back(seqNum);
                  }
            }

            ans[i] = seqNum;
      }

      cout << endWithOne.size() + endWithZero.size() << endl;
      for(int i=0; i<n; i++) {
            cout << ans[i] + 1<< " ";
      }cout << endl;
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      int t;
      cin >> t;
      while(t--)
      solve();
}