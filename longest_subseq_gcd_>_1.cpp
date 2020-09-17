
/*
Longest Subsequence with GCD 1
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mxN = 105;
int n, a[mxN];

// Brute Force
// we try to divide each number of the array 
// by [2, maxNum], and count each time 
// ans = maxCnt
void solve() {
    cin >> n;
    int mx = 0;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        mx = max(a[i], mx);
    }
    
    int mxcnt = 0;
    for(int i=2; i<=mx; i++) {
        int cnt = 0;
        for(int j=0; j<n; j++) {
            if(a[j]%i == 0)
                ++cnt;
        }
        mxcnt = max(cnt, mxcnt);
    }
    cout << mxcnt << "\n";
}

/*
We optimize with prime divisor

If GCD > 1, then all such elements must contain comman factor greater than 1 which evenly 
divides all these values. 

So in order to get that factor we will iterate from 2 to Maximum element of array and then 
check for divisibility.

the divisor(prime) that divides the max values in arr - gives the largest subsequence
*/


const int mxN = 1e5+1;
int prime[mxN], countDiv[mxN], n, a[mxN];

void sieve() {                              
    // prime[i] - smallest prime factor of i;
    for(int i=2; i*i <= mxN; i++) {
        if(!prime[i]) {
            for(int j=2*i; j<= mxN; j=j+i)
                prime[j] = i;   
        }
    }
    for(int i=1; i<=mxN; i++) 
        if(!prime[i])
            prime[i] = i;
}

// O( n*log(max(arr[i])) ) + MAX*log(log(MAX))     - (div_count_algo + sieve)
int maxLenSubsequence() {
    sieve();
    int ans = 0;

    // counting frequecy of all divisors
    for(int i=0; i<n; i++) {
        int val = a[i];

        // this loop finds all the prime divisors of val and increase freq of that prime div 
        while(val > 1) {
            int div = prime[val];

            // Increment count[] of Every unique divisor 
            ++countDiv[div];    

            ans = max(ans, countDiv[div]);
            
            while(val%div == 0) {
                // we want next unique divisor, so use div completely
                val = val / div;
            }
        }
    }
    
    return ans;
}

void solve() {
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];

    cout << maxLenSubsequence() << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}