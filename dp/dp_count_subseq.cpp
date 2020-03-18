// C++ program to count number of distinct 
// subsequences of a given string. 
#include <bits/stdc++.h> 
using namespace std; 
const int MAX_CHAR = 256; 

// Returns count of distinct sunsequences of str. 
int countSub(string str) 
{ 
	// Create an array to store index 
	// of last 
	vector<int> last(MAX_CHAR, -1); 

	// Length of input string 
	int n = str.length(); 

	// dp[i] is going to store count of distinct 
	// subsequences of length i. 
	int dp[n+1]; 

	// Empty substring has only one subsequence 
	dp[0] = 1; 

	// Traverse through all lengths from 1 to n. 
	for (int i=1; i<=n; i++) 
	{ 
		// Number of subsequences with substring 
		// str[0..i-1] 
		dp[i] = 2*dp[i-1]; 

		// If current character has appeared 
		// before, then remove all subsequences 
		// ending with previous occurrence. 
		if (last[str[i-1]] != -1) 
			dp[i] = dp[i] - dp[last[str[i-1]]];         // since the subsequences repeat , so delete them  

		// Mark occurrence of current character 
		last[str[i-1]] = (i-1); 
	} 

    for(int i = 0; i <= n; i++)
        cout << dp[i] << " ";
    cout << endl;

	return dp[n]; 

} 

// Driver code 
int main() 
{ 
cout << countSub("gfh") << endl; 
return 0; 
} 
