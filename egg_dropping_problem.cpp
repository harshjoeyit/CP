
// egg dropping problem 
// https://www.youtube.com/watch?v=3hcaVyX00_4


#include<bits/stdc++.h>
using namespace std;

#define int long long 
const int mxN = 60;
int eggs, floors;

// recursive - brute force
int calculateRecursive(int eggs, int floors){
        if(eggs == 1){
            return floors;
        }
        if(floors == 0){
            return 0;
        }
        int min = 1000;
        for(int i=1; i <= floors; i++){
            int val = 1 + max(calculateRecursive(eggs-1, i-1),calculateRecursive(eggs, floors-i));
            if(val < min){
                min = val;
            }
        }
        return min;
    }

// using dp
void solve() {
    cin >> eggs >> floors;
    int dp[eggs+1][floors+1];               // dp[e][f] - number of eggs remaining, number of floors remaining to be tested
    int c = 0;

    for(int j=0; j<=floors; j++)
        dp[1][j] = j;                       // 1 egg - j floors

    for(int i=0; i<= eggs; i++)
        dp[i][0] = 0;                       // i eggs - 0 floors;


    for(int e=2; e<= eggs; e++) {
        for(int f=1; f<= floors; f++) {
            dp[e][f] = INT_MAX;
            
            // let egg be dropped from kth floor, then (+1 for current move) and
            // if egg breaks we have (e-1) eggs and (k-1) floor to be tested
            // if egg doesn't break we have (e) eggs and (f-k) floors to be tested
            for(int k=1; k<=f; k++) {                           
                c = 1 + max(dp[e-1][k-1], dp[e][f-k]);          // max - for the worst case
                dp[e][f] = min(dp[e][f], c);                    // min - for minimum among all the worst cases 
            }
        }
    }
    cout << dp[eggs][floors] << endl;
}

signed main() {
    int t;
    cin >> t;
    while(t--)
        solve();
}