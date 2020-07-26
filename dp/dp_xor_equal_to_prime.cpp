
/*
find number of multisets of the array A where the Xor of multiset is a prime number 
1 <= n <= 1e5;
3500 <= A[i] <= 4500


DP solution because - 
1 <= Xor <= 8191
unique values <= 1000

so for every prime p we add up the number up subsets of A that make Xor equal to that prime p

dp[i][j] - The count of subset using numbers within [3500, i] which XOR result of the subset equals to j (3500 <= i <= 4500)


*/


#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int mxN = 8200, mod = 1e9+7;
int dp[1005][mxN], cnt[1005], isprime[mxN];
vector<int> primes;

// fiding primes 
void sieve() {                 
    for(int i=0; i<mxN; i++) 
        isprime[i] = 1;
    isprime[0] = isprime[1] = 0;

    for(int i=2; i*i < mxN; i++) {
        if(isprime[i]) {
            for(int j=2*i; j< mxN; j=j+i)
                isprime[j] = 0;   
        }
    }
    for(int i=1; i<mxN; i++) {
        if(isprime[i]) {
            primes.push_back(i);
        }
	}
}

void solve() {
    memset(cnt, 0, sizeof(cnt));
    memset(dp, 0, sizeof(dp));
    
    int n;
    cin >> n;
    int x;
    // finding unique values 
    for(int i=0; i<n; i++) {
        cin >> x;
        ++cnt[x-3500];
    }

    dp[0][3500] = (cnt[0] + 1)/2;                   // subsets to make xor = 3500 using [3500],  take 3500 odd times, like (3500), (3500, 3500, 3500) ......
    dp[0][0] = (cnt[0] + 2)/2;                      // substes to make xor = 0 using [3500], take 3500 even times 

    for(int i=1; i<1005; i++) {
        for(int j=0; j<8200; j++) {
            
            // dp[i][j] =   1. (subsets till i-1) * even times (i+3500)
            //              2. (subsets till i-1 with xor = j*(i+3500)) * odd times (i+3500) 
            //                  as  j^(i+3500)^(i+3500) = j

            dp[i][j] = ( dp[i-1][j]*((cnt[i]+2)/2) + dp[i-1][j^(i+3500)]*((cnt[i]+1)/2) ) % mod ;
        }
    }

    int ans = 0;
    // counting for all primes the multisets whose xor equals p
    for(auto p: primes) {
        // cout << p << " ";
        ans += dp[1004][p];
        ans = ans % mod;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    sieve();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}