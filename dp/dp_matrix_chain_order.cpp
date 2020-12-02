
#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> mat;
vector<vector<int>> dp;

int go(int st, int en) {
    if(st == en) {
        return 0;
    }
    if(st + 1 == en) {
        return mat[st].first * mat[st].second * mat[en].second;
    }

    int &ans = dp[st][en];
    if(ans != -1) {
        return ans;
    }
    ans = INT_MAX;
    for (int k = st+1; k < en; k++) {
        // [st...k] * [k+1...en]
        int curr = go(st, k) + mat[st].first * mat[k].second * mat[en].second + go(k + 1, en);
        ans = min(ans, curr);
    }
    return ans;
}

void matrixChainMul() {
    int n;
	cin >> n;
    dp.assign(n, vector<int>(n, -1));
    mat.assign(n, pair<int, int>(0, 0));
    for (int i = 0; i < n; i++) {
        // order of current matrix [n, m]
        cin >> mat[i].first >> mat[i].second;
    }

    cout << go(0, n - 1);
}

int main() {
    
}