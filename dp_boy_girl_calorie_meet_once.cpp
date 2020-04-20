#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int mxN = 1005;
int Boy1[mxN][mxN];
int Boy2[mxN][mxN];
int Girl1[mxN][mxN];
int Girl2[mxN][mxN];

void solve() {
    int n, m, ans, op1, op2;
    cin >> n >> m;
    int workout[mxN][mxN];
    ans = 0;

    // input matrix 
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin >> workout[i][j];
    
    // boy journey from start to meeting cell
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            Boy1[i][j] = max(Boy1[i-1][j],Boy1[i][j-1]) + workout[i][j]; 
        }
    }

    // boy journey from end cell to meeting cell 
    for(int i=n; i>=1; i--) {
        for(int j=m; j>=1; j--) {
             Boy2[i][j] = max(Boy2[i+1][j],Boy2[i][j+1]) + workout[i][j];
        }
    }

    // girl journey from start to meeting cell
    for(int i=n; i>=1; i--) {
        for(int j=1; j<=m; j++) {
            Girl1[i][j] = max(Girl1[i+1][j],Girl1[i][j-1]) + workout[i][j];
        }
    }

    // boy journey from end cell to meeting cell 
    for(int i=1; i<=n; i++) {
        for(int j=m; j>=1; j--) {
            Girl2[i][j] = max(Girl2[i-1][j],Girl2[i][j+1]) + workout[i][j];
        }
    }

    //Now iterate over all meeting positions (i,j)
    int meeti, meetj;
    for(int i=2; i<=n-1; i++) {
        for(int j=2; j<=m-1; j++) {

            //For the option 1
            op1 = Boy1[i][j-1] + Boy2[i][j+1] + Girl1[i+1][j] + Girl2[i-1][j];

            //For the option 2
            op2 = Boy1[i-1][j] + Boy2[i+1][j] + Girl1[i][j-1] + Girl2[i][j+1];

            //Take the maximum of two options at each position
            int x = max(op1, op2);
            if(x > ans) {
                ans = x;
                meeti = i;
                meetj = j;
            }
        }
    }

    cout << "meet at : "<< meeti << " " << meetj << endl;
    cout << ans << endl;
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}