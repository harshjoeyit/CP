#include <bits/stdc++.h> 
using namespace std; 

int lcs(string &s1, string &s2) {
    int n1 = s1.length();
    int n2 = s2.length();
    
    int dp[n1+1][n2+1];
    
    for(int i= 0; i <=n1; i++)
		dp[i][0] = 0;
    for(int i= 0; i <=n2; i++)
		dp[0][i] = 0;
	
	for(int i=1; i<=n1; i++) {
	    for(int j=1; j<=n2; j++) {
	        if(s1[i-1] == s2[j-1]) 
	            dp[i][j] = dp[i-1][j-1] + 1;
	        else 
	            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	    }
	}
	
	return dp[n1][n2];
}

// checks if after removing k charcters S is a palindrome 
bool is_k_palindrome(string s, int k) {
    string s2 = s;
    reverse(s2.begin(), s2.end());
    int l = lcs(s, s2);
    
    // cout << l << endl;
    
    if(l+k >= s.length())
        return 1;
    else 
        return 0;
}

int main()
{
	string s, t;
	cin >> s >> t;
	cout << lcs(s, t) << "\n";
}

