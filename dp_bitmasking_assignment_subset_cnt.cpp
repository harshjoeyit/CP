#include<bits/stdc++.h>
using namespace std;
/*
LIMITATIONS:
     a. Always check the size of the set to determine 
        whether to use an int or long long or not using 
        bitmask at all
     b. Always use parenthesis to indicate the precedence 
        of operations when doing bitwise operations!
        When it involves bitwise operators and not putting 
        parenthesis can yield undesirable results! 
        */

#define int long long
// also look counting subsets with sum = k by dp

int count_subsets(int a[], int n, int val) {
    int cnt = 0;
    for(int i=0; i<pow(2, n); i++) {
        int s=0;
        for(int k=0; k<n; k++)
            if(((1 << k) & i) > 0)
                s += a[k];

        if(s >= val)
            ++cnt;
    }
    return cnt;
}

const int mxN = 17;
int cost[mxN][mxN];         // matrix cost[i][j] -denotes, how much person i  is going to charge for task j.
int dp[1 << mxN];
const int inf = 1e18;

// O( n 2^n )

int assignment_problem(int n) {
    int pow2 = pow(2, n);
    for(int i=0; i<pow2; i++)
        dp[i] = inf;

    dp[0] = 0;
    for(int mask=0; mask<pow2; mask++) {
        int x = __builtin_popcountll(mask);             // count no of set bits
        
        for(int j=0; j<n; j++) {
            if(((1 << j) & mask) == 0)                         // for bits not set in mask (i.e for jobs that are not assigned yet)
                dp[mask | (1 << j)] = min( dp[mask | (1 << j)], dp[mask] + cost[x][j] );
        }
    }

    return dp[pow2-1];
}


signed main() {
   
    // counting number of subsets that have sum >= val
    int a[4] = {1, 1, 1, 2}; 
    int val = 4;
    cout << count_subsets(a, 4, 4) << "\n";



    // bitmask assignment problem
    int n=3;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> cost[i][j];
        }
    }
    cout << assignment_problem(n) << endl;
}   