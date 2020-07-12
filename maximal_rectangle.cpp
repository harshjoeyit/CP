#include<bits/stdc++.h>
using namespace std;

// solution is based on JUDGE algo for max area histogram 
// https://www.youtube.com/watch?v=g8bSdXCG-lA


#define int long long 
#define MAX 1005
#define height      first
#define index       second
int a[MAX][MAX];

int maxRecArea(int A[MAX][MAX], int ind, int m) {
    int mxarea = -1, left , curr;
    stack<pair<int, int>> S;
        
    for(int j = 0; j <= m; j++ ) {
        while( !(S.empty()) && ( j == m || S.top().height > A[ind][j] )) {
            if( S.size() > 1) {                 // min 2 items 
                auto t = S.top();
                S.pop();
                left = S.top().index;           // 2nd item on the stack
                S.push(t);
            }                                             
            else
                left = -1;

            curr = (j - left - 1) * S.top().height;
            S.pop();

            if( curr > mxarea )
                mxarea = curr;
        }

        if(j < m)                                               
            S.push( {A[ind][j], j} );
        
    } 
    return mxarea;
}

int maxArea(int a[MAX][MAX], int n, int m) {
    for(int j=0; j<m; j++) {
        for(int i=1; i<n; i++) {
            if(a[i][j] > 0 && a[i-1][j] > 0) {
                a[i][j] += a[i-1][j];
            }
        }
    }
    
    int maxA = 0;
    for(int i=0; i<n; i++) {
        maxA = max(maxA, maxRecArea(a, i, m));
    }
    
    return maxA;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> a[i][j];

    cout << maxArea(a, n, m) << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}