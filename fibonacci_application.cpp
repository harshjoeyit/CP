
/*
problem using fibonacci series 
https://www.codechef.com/COTH2020/problems/UNIQSTR

if a conversion is defined as 'ff' -> 'k'
find how many distinct strings are possible for a string like 
s = ffffffff.......
ans[s.length()] = fib[s.length()]

proof - 
ans[0] = 1; - ""
ans[1] = 1; - "f"
ans[2] = 2; - "ff", "c"
ans[3] = 3; - "fff", "fc", "cf"
....

generally if s.length() = n
then we can choose chars at 0, 1 i.e convert "ff" -> c - remining string is of length n-2 (ans for which is already calculated) 
and also we can choose not to convert "f" - remianing string is of length n-1 (ans for which is already calculated)
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 1e9+7;
const int mxN = 1e5+5;
vector<int> fib(mxN);

void precalc() {
      fib[0] = fib[1] = 1;
      for(int i=2; i<mxN; i++) {
            fib[i] = fib[i-1] + fib[i-2];
            fib[i] %= mod;
      }
}

void solve() {
      string s;
      cin >> s;

      for(auto &c: s) {
            if(c == 'c' || c == 'k') {
                  cout << 0 << endl;
                  return;
            }
      }

      vector<int> v(s.length());
      for(int i=1; i<s.length(); i++) {
            if(s[i-1] == s[i]) {
                  v[i] = v[i-1] + 1;
            }
      }

      int ans = 1;
      for(int i=v.size()-1; i>=0; i--) {
            if(s[i] == 'f' || s[i] == 'g') {
                  ans = ans * (fib[v[i]+1]);
                  ans %= mod;
            }
            // skippping the chars as ans calculated for them
            i = i - v[i];
      }
      cout << ans << "\n";
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      precalc();
      solve();
}