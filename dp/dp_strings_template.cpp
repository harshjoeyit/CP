
/*
Template for common DP problems based on strings
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {
      
// 1. Two strings are given 

	/*Pre-processing. Define basic cases*/
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=m; j++) {
			if(s1[i-1] == s2[j-1]) {
				// code
			} else {
				// code
			}
		}
	} 


// 2. one string is given 

	/*Pre-processing. Define basic cases*/
	for(int len=1; len < n; len++) {
		for(int i=0; i+len < n; i++) {
			int j = i+l-1;
			if(s[i] == s[j]) {
				// code
			} else {
				// code
			}
		}
	}

}


// Based on template 

	// Convert string1 to string2 using INSERT, REPLACE and DELETE only
	int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        for(int i = 1; i <= n; i++){
            dp[i][0] = 1 + dp[i - 1][0];
        }
        for(int i = 1; i <= m; i++){
            dp[0][i] = 1 + dp[0][i - 1];
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
              
                if(word2[i - 1] == word1[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1;
                }
               
            } 
        }
        return dp[n][m];
    }


    // Min moves to make strings equal by either deleting char in string1 or string2
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        // if one string is empty the all char of other string have to be deleted 
        for(int i = 1; i <= m; i++){
            dp[i][0] = 1 + dp[i - 1][0];
        }
        for(int i = 1; i <= n; i++){
            dp[0][i] = 1 + dp[0][i - 1];
        }
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(word1[i - 1] == word2[j - 1]){
                    // char same no need to delete it
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
        return dp[m][n];
    }

    // similar problem 
    // Minimum ASCII Delete Sum for two Strings


    // longest palindromic substring
    int longestPalindromeSubseq(string s) {
        int n = s.length(); 
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
        }
        int count = 1;
        for(int len = 1; len < n; len++){
            for(int i = 0; i + len < n; i++){
                int j = i + len;
                if(s[i] == s[j]){
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                }
                else{
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      solve();
}