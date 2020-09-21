
#include<bits/stdc++.h>
using namespace std;

struct state {
    int si, sj, ei, ej;
    state(int a, int b, int c, int d) : si(a), sj(b), ei(c), ej(d) { };

    bool operator < (const state &rhs) const {
        return (si != rhs.si || sj != rhs.sj || ei != rhs.ei || ej != rhs.ej);
    }
};

int n, m;
vector<string> mat;
int halflen;

map<state, int> dp;

int palindromicPaths(int si, int sj, int ei, int ej) {
    if(si >= n || sj >= m || ei < 0 || ej < 0) {
        return 0;
    }

    state curr(si, sj, ei, ej);

    if(dp.count(curr)) {
        return dp[curr];
    }

    if(si + sj + 1 > halflen ||  mat[si][sj] != mat[ei][ej]) {
        return dp[curr] = 0;
    }

    if(abs(si - ei) + abs(sj - ej) <= 1) {
        return dp[curr] = 1;
    }

    int ans = 0;
    ans += palindromicPaths(si + 1, sj, ei - 1, ej);
    ans += palindromicPaths(si + 1, sj, ei, ej - 1);
    ans += palindromicPaths(si, sj + 1, ei - 1, ej);
    ans += palindromicPaths(si, sj + 1, ei, ej - 1);

    return dp[curr] = ans;
}

int main () {
    cin >> n >> m;
    mat.assign(n, "");
    dp.clear();
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }
    halflen = (n + m) / 2;
    cout << palindromicPaths(0, 0, n - 1, m - 1) << endl;
}