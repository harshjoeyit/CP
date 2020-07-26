#include<bits/stdc++.h>
using namespace std;
#define int long long int

string getBin(int n) {
      string num = "";
      while(n > 0) {
            if(n & 1) {
                  num.push_back('1');
            } else {
                  num.push_back('0');
            }
            n = n >> 1;
      }
      reverse(num.begin(), num.end());
     
      return num;
}

int getVal(string num) {
      int p = 1;
      int val = 0;
      for(int i=num.length()-1; i>=0; i--) {
            if(num[i] == '1') {
                  val += p;
            }
            p *= 2;
      }
      return val;
}

int go(int a, int b) {
      string aBin = getBin(a);
      string bBin = getBin(b);
      int val1 = getVal(aBin + bBin);
      int val2 = getVal(bBin + aBin)
      cout << a << " " << b << " -> " << val1 - val2 << "\n";
      // cout << aBin << " " << bBin << endl;
      // cout << val1 << " " << val2 << endl;
      // cout << val1 - val2 << endl;
      return (val1 - val2);
}

void solve() {
      int n;
      cin >> n;
      vector<int> a(n);
      for(int i=0; i<n; i++) {
            cin >> a[i];
      }
      int ans = 0;
      for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                  if(i != j) {
                        ans = max(ans, go(a[i], a[j]));   
                  }   
            }
      }

      cout << ans << endl;
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      int t;
      cin >> t;
      while(t--)
      solve();
}