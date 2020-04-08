#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int mxN = 55;
int a[mxN], dp[1<<17][mxN];
int n;
vector<int> primes;

bool isprime(int n) {
    for(int i=2; i<n; i++) 
        if(n%i == 0)
            return false;

    return true;
}


int max_subseq_gcd_1(int mask, int ps) {
  if(ps == n) 
    return 0;
  if(dp[mask][ps]!=-1) 
    return dp[mask][ps];
  
  int ans = max_subseq_gcd_1(mask, ps+1);
  if((mask & a[ps])==0) 
    ans = max(ans, max_subseq_gcd_1(mask+a[ps],ps+1)+1);
  
  return dp[mask][ps] = ans;
}

void solve() {
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    
    for(int i=2; i<= 55; i++)
        if(isprime(i))
            primes.push_back(i);

    for(int i=0; i<n; i++) {
        int mask = 0;
        for(int j=0; j<primes.size(); j++) {
            if(a[i]%primes[j] == 0)
                mask = mask | (1<<j);       // setting those bits 1 where primes[bit] divides a[i]
        }
        a[i] = mask;                        // mask - all those bits are set for whose primes[i] divide a[i]
    }
    memset(dp, -1, sizeof(dp));
    cout << max_subseq_gcd_1(0, 0) << "\n";
}


signed main() {
    solve();
}