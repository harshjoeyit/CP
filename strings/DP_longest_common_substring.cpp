#include <bits/stdc++.h> 
using namespace std; 

int main()
{
	string s = "ahuja";
	string t = "hxjazel";

	int dp[s.length()+1][t.length()+1];

	// d[i][j] = longest common subsequence in length i and j

	for(int i= 0; i <=t.length(); i++)
		dp[0][i] = 0;
	for(int i= 0; i <=s.length(); i++)
		dp[i][0] = 0;

	for(int i = 1; i <= s.length(); i++)
	{
		for(int j = 1; j <= t.length(); j++)
		{
			if(s[i-1] == t[j-1])					// -1 for correct index
				dp[i][j] = dp[i-1][j-1] + 1;		// 1 + dp with one char less in each string
			else
				dp[i][j] = max(dp[i-1][j] , dp[i][j-1]); 
		}
	}

	for(int i = 0; i <= s.length(); i++)
	{
		for(int j = 0; j <= t.length(); j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}

	// ans = dp[s.length()][t.length()];
}

