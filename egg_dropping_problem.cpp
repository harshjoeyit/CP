
// egg dropping problem 
// https://www.youtube.com/watch?v=3hcaVyX00_4

// find the minimum attempts in worst case using the best stratesgy 
// to find the floor, throwing from which the egg breaks 
// Also we have to use the given number of eggs only

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
    // dp[e][f] - number of eggs remaining, number of floors remaining to be tested
    int dp[eggs+1][floors+1];               
    int c = 0;

    // if we have 1 egg and j floors
    // then best strategy is to go up 1 floor each time 
    // starting from the 1 floor, so we need j attempts 
    for(int f=0; f<=floors; f++) {
        // 1 egg - j floors
        dp[1][f] = f;             
    }          

    // 0 floors require 0 eggs 
    for(int e=0; e<= eggs; e++) {
        // i eggs - 0 floors;
        dp[e][0] = 0;                       
    }


    for(int e=2; e<= eggs; e++) {
        for(int f=1; f<= floors; f++) {
            dp[e][f] = INT_MAX;
            
            // let egg be dropped from kth floor, then (+1 for breaking this egg), 

            // if egg breaks we have (e-1) eggs and (k-1) floor to be tested
            // if egg doesn't break we have (e) eggs and (f-k) floors to be tested
            for(int k=1; k<=f; k++) {                           
                c = 1 + max(dp[e-1][k-1], dp[e][f-k]);          
                // max - for the worst case
                dp[e][f] = min(dp[e][f], c);                    
                // min - for minimum among all the worst cases 
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