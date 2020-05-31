#include<bits/stdc++.h>
using namespace std;
#define int long long 

int ladders[50];
int dp[50];


int shortest_path(int pos) {
    if(pos == 30) {
        return 0;
    }
    if(pos > 30) {                                                      // board has max 30 on it
        return 30;
    }
    if(dp[pos] != -1) {
        return dp[pos];
    }

    int ans = 1e17;
    for(int i=1; i<=6; i++) {
        if(ladders[pos+i] > pos+i) {                                    // choosing only ladders, no snakes - may not work in complicated cases 
            ans = min(ans, 1+shortest_path(ladders[pos+i]));
        } else {                                                        // if no ladder at pos+i
            ans = min(ans,1+shortest_path(pos+i));
        }
    }

    return dp[pos] = ans;
}

void solve() {
    int n;
    cin >> n;

    memset(ladders, -1, sizeof(ladders));                               // ladders x ---> y
    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;      
        ladders[x] = y;
    }

    memset(dp, -1, sizeof(dp));
    cout << shortest_path(1) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}