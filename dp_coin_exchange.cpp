int dp[255][52];

long calc(int n, int last, vector<long> c) {              
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

long getWays(int n, vector<long> c) {           // n - money, c - coin denomination (coin of each denomination are infinte)
    memset(dp, -1, sizeof(dp));
    return calc(n, 0, c);
}