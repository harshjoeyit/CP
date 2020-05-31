
/*
given a sequence of numbers in find the largest sequence(length) with gcd = 1
this can also be solved using bitsets 
*/

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
    
  if(dp[mask][ps] != -1) {
    return dp[mask][ps];
  }
  
  // for number at pos we have two options - select it of skip it

  // skipping it - mask remians the same 
  int ans = max_subseq_gcd_1(mask, ps+1);

  // selecting only if mask and a[pos] has no common prime divisors divisors 
  if((mask & a[ps]) == 0) {
    // now the mask has to include the all the divisors of the a[pos], 
    // we could also have used | operator but + is same since no common set bit
    // increase count of elements in the sequence by 1
    ans = max(ans, 1 + max_subseq_gcd_1(mask+a[ps],ps+1));
  }

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
        a[i] = mask;                        // mask - all those bits are set for whose primes[j] divide a[i]
    }
    memset(dp, -1, sizeof(dp));
    cout << max_subseq_gcd_1(0, 0) << "\n";   // we start with mask ..00000 and pos = 0
}


signed main() {
    solve();
}