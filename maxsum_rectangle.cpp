#include<bits/stdc++.h>
using namespace std;
#define int long long 

const int mxN = 102;
int n, m;
int a[mxN][mxN];
int temp[mxN];

int kadane() {
    int ans = temp[0];
    int s=0;
    for(int i=0; i<n; i++) {
        s += temp[i];
        ans = max(ans ,s);
        s = max(s, 0LL);
    }
    return ans;
}


void solve() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }

    int ans = INT_MIN;
    for(int left=0; left<m; left++) {                   // fix left col
        
        memset(temp, 0, sizeof(temp));                  // reset temp for everytime left is fixed 
        for(int right=left; right<m; right++) {         // move right col just like we find subarrays  

            for(int r=0; r<n; r++) {                    // increment temp[r] by the right column values 
                temp[r] += a[r][right];
            }                          

            ans = max(ans, kadane());
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}