#include<bits/stdc++.h>
using namespace std;

/*
Another approach -
If we observe then we will found that to make gcd greater than 1, all such elements must contain
 comman factor greater than 1 which evenly divides all these values. So in order to get 
that factor we will iterate from 2 to Maximum element of array and then check for divisibility.
(O*max(a[i]))
- basically we check every divisor from 2 - max(a[i]) - the one that divides the max values in arr - gives the largest subsequence
*/

#define int long long
const int mxN = 1e5+1;
int prime[mxN], countDiv[mxN], n, a[mxN];

void sieve() {                              // prime[i] - smallest prime factor of i;
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
int max_subarray_size_gcd_1() {
    sieve();
    int ans = 0;

    // counting frequecy of all divisors - the one with the max freq divides max values in arr[] - gives max length subsequence
    for(int i=0; i<n; i++) {
        int val = a[i];
        while(val > 1) {
            int div = prime[val];

            ++countDiv[div];    // Increment count[] of Every unique divisor 
            
            ans = max(ans, countDiv[div]);
            
            while(val%div == 0)
                val = val/div;
        }
    }
    return ans;
}

void solve() {
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];

    cout << max_subarray_size_gcd_1() << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}