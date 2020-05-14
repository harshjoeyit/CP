
/*
using DP to find longest palindromic substring 
answers range query of [L, R] - if palindrome or not in O(1) 
*/

#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e3+10;
bool dp[mxN][mxN];
string s;
string ans_s;

void pre_process() {
    int n = s.length();
    int ans_i = 0, ans_l = 0;

    for(int i=0; i<n; i++) 
        for(int j=0; j<n; j++) 
            dp[i][j] = false;
      
    for(int j=1; j<=n; j++){                    // j = for length of the string
        for(int i=0; i<=n-j; i++) {             // i - iterate to every index where length j string is possible
            if(j <= 2) {                        // for string of length = 1, 2
                if(s[i] == s[i+j-1])            // [i - i+length-1] indices of start and end of string 
                    dp[i][i+j-1] = true;

            } else if(s[i] == s[i+j-1]){
                dp[i][i+j-1] = dp[i+1][i+j-2];  // for [l, r] to be palindrome [l+1, r-1] must be a palindrome    
            }
            if(dp[i][i+j-1] == 1) {
                if(j > ans_l) {
                    ans_l = j;
                    ans_i = i;
                }
            }
        }
    }   
    ans_s = s.substr(ans_i, ans_l);
}

void solve() {
    cin>> s;
    pre_process();
    cout << ans_s << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) 
        solve();
}
