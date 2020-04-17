#include<bits/stdc++.h>
using namespace std;

#define int long long int


bool invalid(int i, int j, int N, int M, vector<int> A[]) {
    if(i < 0 || i >= N || j < 0 || j >= M || A[i][j] == 0)
        return 1;      //NOTE: 1 - invalid
    return 0;           // NOTE: 0 - valid
}

void dfs(int i, int j, int N, int M, vector<int> A[]) {
    
    if(invalid(i, j, N, M, A))
        return;
        
    // valid    
    A[i][j] = 0;
    // all possible 8n cubes that are adjacent 
    dfs(i+1, j, N, M, A);           
    dfs(i-1, j, N, M, A);
    dfs(i, j+1, N, M, A);
    dfs(i, j-1, N, M, A);
    dfs(i+1, j+1, N, M, A);
    dfs(i-1, j+1, N, M, A);
    dfs(i+1, j-1, N, M, A);
    dfs(i-1, j-1, N, M, A);
}

/*
1 1 0
0 0 1
1 0 1

eg: 2 islands here 

*/

int findIslands(vector<int> A[], int N, int M) {
    int cnt = 0;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(A[i][j] == 1) {
                ++cnt;
                dfs(i, j, N, M, A);
            }
        }
    }
    return cnt;
}

void solve() {

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