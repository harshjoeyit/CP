#include<bits/stdc++.h>
using namespace std;

#define int long long 
const int mxN = 1e6+5;
bool isprime[mxN];
int pre[10][mxN];

void sieve() {
    for(int i=2; i<mxN; i++) {
        isprime[i] = 1;
    }
    for(int i=2; i<mxN; i++) {
        if(isprime[i]) {
            for(int j=2*i; j<mxN; j=j+i) {
                isprime[j] = 0;
            }
        }
    }
}

void pre_calc() {
    int k, dig;
    for(int j=2; j<mxN; j++) {
        if(isprime[j]) {
            k = j;
            while(k > 0) {
                dig = k%10;
                k = k/10;
                ++pre[dig][j];
            } 
        }
        for(int i=0; i<10; i++) {
            pre[i][j] += pre[i][j-1];
        }
    }
}

void solve() {
    int l, r;
    cin >> l >> r;
    int mxf = 0;
    int mxdig = 0;

    for(int i=0; i<10; i++) {
        int cnt = (pre[i][r] - pre[i][l-1]);
        if(cnt >= mxf) {
            mxf = cnt;
            mxdig = i;
        }
    }
    if(mxf > 0) {
        cout << mxdig << "\n";
    } else {
        cout <<"-1\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    sieve();
    pre_calc();

    int t;
    cin >> t;
    while(t--)
        solve();
}