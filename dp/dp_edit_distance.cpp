
/*
Edit distance is a way of quantifying how dissimilar two strings are, 
i.e., how many operations (add, delete or replace character) 
it would take to transform one string to the other. T
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int mxN = 1005;

//               source ---> target
int editDistance(string s1, string s2) {  
    int m = s1.size();  
    int n = s2.size();  
                          
    // for all i, j, dp[i][j] will hold the edit distance between the first, i characters of source string and first j characters of target string 
    int dp[m + 1][n + 1];               
    memset(dp, 0, sizeof(dp));  

    // when size of source string = 0, then i insertion operations convert it to target
    for (int i = 1; i <= n; i++) {      
        dp[0][i] = i;  
    }  
    // when size of target = 0, source can be converted by i delete operations 
    for (int i = 1; i <= m; i++) {      
        dp[i][0] = i;  
    }  

    for (int i = 1; i <= m; i++) {  
        for (int j = 1; j <= n; j++) {  
            if (s1[i - 1] == s2[j - 1]) {
                // no operation required as characters are the same  
                dp[i][j] = dp[i - 1][j - 1];      
            }  
            else {  
                dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
                //            min of substitution,  insertion, deletion
            }  
        }  
    }  
    return dp[m][n];  
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

/*
similar problems : 
Two strings you can delete chars in any of them, find
minimum steps to make the strings equal


- can be done simplys using LCS
https://leetcode.com/problems/delete-operation-for-two-strings/submissions/
*/