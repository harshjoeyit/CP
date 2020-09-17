#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e6 + 10;
vector<int> isprime;

void sieve() {
      isprime.assign(mxN, 1);
      isprime[0] = isprime[1] = 0;

      for (int i = 2; i * i < mxN; i++) {
            if(isprime[i]) {
                  for (int j = 2 * i; j < mxN; j += i) {
                        isprime[j] = 0;
                  }
            }
      }
}

int countPrime(string &s) {
      if(s[0] == '0') {
            return 0;
      }
      int ans = 0, num = 0;
      for(auto &c: s) {
            num = num * 10 + (c - '0');
            if(isprime[num]) {
                  cout << num << " ";
                  ans += 1;
            }
      }
      return ans;
}

int main() {
      string s;
      cin >> s;
      sieve();

      int n = s.length();
      int i = 0, ans = 0;
      while(i < n) {
            int j = min(i + 5, n - 1);
            auto temp = s.substr(i, j - i + 1);
            ans += countPrime(temp);
            i += 1;
      }

      cout << endl;
      cout << ans << endl;
}