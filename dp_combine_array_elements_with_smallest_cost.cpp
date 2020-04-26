#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int mxN = 405;
int dp[mxN][mxN];
const int INF = 1e18;

// find minimum cost to combine all elements given when x, y are combined cost = x+y
// the array elements can be considered as leaves of a binary tree
// we combine them to form nodes
// also every node represents an interval - cost for that interval should be minimized 

// dp[i][j] - min cost to combine interval [i, j]
// our ans = dp[1][n]

void solve() {
    int n;
    cin >> n;

    int a[n+1];
    for(int i=1; i<=n; i++)
        cin >> a[i];
    
    int pref[n+1];
    memset(pref, 0, sizeof(pref));
    for(int i=1; i<=n; i++)
        pref[i] = pref[i-1] + a[i];
    
    // intervals 
    for(int L=n; L>=1; L--) {
        for(int R=L; R<=n; R++) {

            if(L == R) {             // if interval consist of single node - cost = 0
                dp[L][R] = 0;
            
            } else {    
                dp[L][R] = INF;
                int sum = pref[R]-pref[L-1];

                // breaking intervals of L, R segments of left child and right child - to discpver all possibilites 
                for(int i=L; i<=R-1; i++) {
                    dp[L][R] = min(dp[L][R], dp[L][i] + dp[i+1][R] + sum);
                }
            }
        }
    }

    cout << dp[1][n] << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}