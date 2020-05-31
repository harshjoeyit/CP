/*
https://www.codechef.com/APRIL20B/problems/STRNO

check if a number is valid 
it has x number of divisors and k of which are prime
solution 
N = p1^a1 * p2^a2 * ......pk^ak          -- for k primes
any number can be expressed as powers of prime
Total Divisors(x) = (a1+1)*(a2+1)*(a3+1)*......(ak+1)
so, x = y1*y2*y3.......*yk    -- yi >= 2

This means x must be expressed as multiple of atleast k values >= 2 
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long

int p, divs;

int count_dist(int n) {                     // finding max cnt of values in which n can be expressed 
    int cnt=0;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0){
                n=n/i;
                ++cnt;
            }
        }
    }
    if(n>1) ++cnt;
    return cnt;
}

void solve() {
	cin >> divs >> p;
    int cnt = count_dist(divs);
    if(cnt < p)
        cout << "0\n";
    else    
        cout << "1\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    	solve();
}