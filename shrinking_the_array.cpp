/*
    if a[i] == a[i+1], then a[i] & a[i+1] -> replaced by a[i] + 1
    eg. [1 1 3] -> [2 3]
    find the minimum length possible
    eg. 1 1 1 2 3 
    eg. 3 3 2 2 2 3 4 5
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int

const int INF = 1e9;
const int INF64 = 1e18;
const int EPS = 1e-9;

const int N = 555;
int n, a[N];

inline bool read() {
    if(!(cin >> n))
        return false;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    return true;
}

int dp[N][N];
int dp2[N];

// void print()
// {
//     for(int i = 0; i < n; i++)
//     {
//         for(int j = 0; j <= n; j++)
//             cout << dp[i][j] << " ";
//         cout << endl;
//     }
//     cout << endl;
//     for(int i = 0; i <= n; i++)
//         cout << dp2[i] << " ";
//     cout<< endl;
// }

int calcDP(int l, int r) {
    if(l + 1 == r)
        return dp[l][r] = a[l];
    if(dp[l][r] != 0)
        return dp[l][r];
    
    dp[l][r] = -1;
    for(int mid = l+1; mid < r; mid++ ) {
        int lf = calcDP(l, mid);
        int rg = calcDP(mid, r);
        if(lf > 0 && lf == rg)
            return dp[l][r] = lf + 1;
    }
    return dp[l][r];
}

inline void solve() {
    for(int i = 0; i < N; i++)
        dp2[i] = INF;
    
    dp2[0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j <= n; j++) {
            if(calcDP(i, j) > 0)
                dp2[j] = min(dp2[j], dp2[i] + 1);
        }
    }
    cout << dp2[n] << endl;
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    if(read()) {
        solve();

    }
    return 0;
}