
#include<bits/stdc++.h>
using namespace std;

int n;
const int mxN = 100;
int dp[mxN][mxN];
vector<pair<int, int>> rectangles;

int go(int curr, int prev) {
    if(curr == n) {
        // limit exceed
        return 0;
    }

    if(prev != -1) {
        int &ans = dp[curr][prev];
        if(ans != -1) {
            return ans;
        }
    }

    if(prev == -1) {
        // no rectangle in subset yet
        // skip or include
        return max(go(curr + 1, prev), 1 + go(curr + 1, curr));
    } 

    int &ans = dp[curr][prev];

    // check fitting
    int h1 = rectangles[prev].first, w1 = rectangles[prev].second;
    int h2 = rectangles[curr].first, w2 = rectangles[curr].second;
    
    if(h1 <= h2 && w1 <= w2) {
        // fits, skip this
        return ans = go(curr + 1, prev);
    } 

    // doesnt fit
    return ans = max(go(curr + 1, prev), 1 + go(curr + 1, curr));
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int h, w;
        cin >> h >> w;
        rectangles.push_back({h, w});
    }
    memset(dp, -1, sizeof(dp));
    sort(rectangles.begin(), rectangles.end());
    cout << go(0, -1) << endl;
}