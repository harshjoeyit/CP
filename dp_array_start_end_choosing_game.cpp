
/*
Two player play a game of choosing elements from either start or the end of the array
the values of the array are added to the scores of the players
both playes play optimally

let score of the playes be X, Y
what is the max value of (X - Y)
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int mxN = 3005;
int n, a[mxN], dp[2][mxN][mxN];         // [players turn][start pos][end pos]

int calc(int st, int en, int x) {
    if(st > en) 
        return 0;

    if(dp[x][st][en])   
        return dp[x][st][en];

    if(x) {
        return dp[x][st][en] = max(a[st] + calc(st+1, en, !x), 
                                calc(st, en-1, !x) + a[en]);
    } else {
        return dp[x][st][en] = min(-a[st] + calc(st+1, en, !x), 
                                calc(st, en-1, !x) - a[en]);
    }
}

void solve() {
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    
    cout << calc(0, n-1, 1) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}