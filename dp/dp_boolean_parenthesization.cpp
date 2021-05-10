#include <bits/stdc++.h>
using namespace std;

const int mod = 1003;

// add pairs 
pair<int, int> &addPairs(pair<int, int> &a, pair<int, int> &b) {
    a.first = (a.first + b.first) % mod;
    a.second = (a.second + b.second) % mod;
    return a;
}

// for method 1
int operate(char a, char b, char op) {
    int ia = (a == 'T') ? 1: 0;
    int ib = (b == 'T') ? 1: 0;
    
    if(op == '&') {
        return ia & ib;
    } else if(op == '|') {
        return ia | ib;
    } else if(op == '^') {
        return ia ^ ib;
    }
    return 0;
}

// for method 1
pair<int, int> calc(pair<int, int> &pa, pair<int, int> &pb, char op) {
    int t1 = pa.first, f1 = pa.second;
    int t2 = pb.first, f2 = pb.second;

    // t1, t2 - number of ways left, right expr returns T
    // f1, f2 - number of ways left, right expr returns F
    int ta = 0, fa = 0;

    // Ways whole substring returns true
    if(op == '&') {
        //  T&T
        ta = (t1*t2) % mod;
    } 
    else if(op == '^') {
        //  T^F, F^T
        ta = ((t1*f2) % mod  + (t2*f1) % mod) % mod;
    }  
    else if(op == '|') {
        //  T|F, F|T, T|T
        ta = ((t1*f2) % mod  + (t2*f1) % mod + (t1*t2) % mod ) % mod;
    } 

    // ways whole substring returns false
    if(op == '&') {
        //  T&T
        fa = ((t1*f2) % mod + (t2*f1)%mod + (f1*f2)%mod) % mod;
    } 
    else if(op == '^') {
        //  T^F, F^T
        fa = ((f1*f2) % mod  + (t1*t2) % mod) % mod;
    }  
    else if(op == '|') {
        //  T|F, F|T, T|T
        fa = (f1*f2) % mod;
    } 

    return {ta, fa};
}

// method 1.
int countWays(int n, string s){
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {0, 0}));
    // dp[i][j] = {T ways, F ways}, a pair whose 
    // first value  = number of ways s[i...j] returns T
    // second value = number of ways s[i....j] return F

    // for single char like T, F
    for(int i=0; i<n; i+=2) {
        if(s[i] == 'T') {
            dp[i][i] = {1, 0};
        } else {
            dp[i][i] = {0, 1};
        }
    }
    // for pairs like T&F, F^T ...
    for(int i=0; i<=n-3; i+=2) {
        int op = operate(s[i], s[i+2], s[i+1]);
        int j = i+2;
        if(op) {
            dp[i][j] = {1, 0};
        } else {
            dp[i][j] = {0, 1};
        }
    }

    // for substrings length >= 5
    for(int l=5; l<=n; l+=2) {
        for(int i=0; i<=n-l; i+=2) {
            int j = i+l-1;
            // add for all [i...k] op [k+2.....j]
            for(int k=i; k+2<=j; k+=2) {
                auto p = calc(dp[i][k], dp[k+2][j], s[k+1]);
                dp[i][j] = addPairs(dp[i][j], p);
            }
        }
    }

    return dp[0][n-1].first;
}

int main() {
    cout << countWays(7, "T|T&F^T") << endl;
    cout << countWays(5, "T^F|F") << endl;
}