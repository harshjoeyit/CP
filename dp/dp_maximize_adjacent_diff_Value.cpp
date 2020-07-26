
/*
given an array b
find max value of summation |a[i] - a[i-1]| over all indices 

given 1 <= a[i] <= b[i]
*/

int cost(vector<int> a) {
    int n = a.size();
    
    int dp[n][2];       

    // we have 4 possibilites
    // a[i-1] = 1,      a[i] = 1
    // a[i-1] = b[i-1], a[i] = 1
    // a[i-1] = 1,      a[i] = b[i]
    // a[i-1] = b[i-1], a[i] = b[i]

    // dp[i][0] - when a[i-1] is 1

    // dp[i][1] - when a[i-1] is b[i]

    dp[0][0] = dp[0][1] = 0;

    for(int i=0; i<n-1; i++) {
        dp[i+1][0] = max( dp[i][0], 
                    dp[i][1] + abs(a[i] - 1));
        dp[i+1][1] = max( dp[i][1] + abs(a[i+1] - a[i]), 
                        dp[i][0] + abs(a[i+1] - 1)); 
    }

    return max(dp[n-1][1], dp[n-1][0]);
}