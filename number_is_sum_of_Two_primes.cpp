#include<bits/stdc++.h>
using namespace std;
#define int long long 

const int mxN = 1e6;
int prime[mxN+1];
vector<int> allprimes;

void sieve() {
    for(int i=2; i<=mxN; i++)
        prime[i] = 1;
    prime[0] = 0;
    prime[1] = 0;

    for(int i=2; i<=mxN; i++) {
        if(prime[i]) {
            for(int j=2*i; j<=mxN; j=j+i) {
                prime[j] = 0;
            }
        }
    }

    for(int i=2; i<=mxN; i++) {
        if(prime[i]) {
            allprimes.push_back(i);
        }
    }
}

void solve() {
    int n;
    cin >> n;

    bool ans = 0;
    int p;
    for(auto p1: allprimes) {
        if(p1 > n)
            break;

        int p2 = n-p1;
        if(prime[p2]) {
            ans = 1;
            p = p1;
            break;
        } 
    }

    if(ans) {
        cout << p <<" " <<  (n - p) << endl;
    } else {
        cout << -1 << endl;
    }
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