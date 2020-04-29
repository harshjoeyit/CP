int dp[255][52];

int calc(int n, int last, vector<int> c) {              
    if(n == 0) {
        return 1;
    }
    if(n < 0) {
        return 0;
    }

    if(dp[n][last] != -1)
        return dp[n][last];

    int ans = 0;
    for(auto val : c) {
        if(val >= last) 
            ans += calc(n - val, val, c);
    }
    return dp[n][last] = ans;
}

int getWays(int n, vector<int> c) {           // n - money, c - coin denomination (coin of each denomination are infinte)
    memset(dp, -1, sizeof(dp));
    return calc(n, 0, c);
}