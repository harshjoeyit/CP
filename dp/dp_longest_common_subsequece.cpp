
#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int mxN = 3005;
int dp[mxN][mxN];

/*
Application 
1. Bridges building problem  - https://www.geeksforgeeks.org/dynamic-programming-building-bridges/
*/

void print_LCS(string s, string t, int n, int m) {
    int i=n, j=m;
    string lcs = "";
    
    while((i>0) && (j>0)) {
        if(s[i-1] == t[j-1]) {
            lcs = s[i-1] + lcs;
            --i;
            --j;

        } else if(dp[i-1][j] > dp[i][j-1]) {
            --i;
        } else {
            --j;
        }
    }
    cout << lcs << endl;
}

void LCS(string s, string t) {
    // lcs
    int n = s.length();
    int m = t.length();

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // print lcs
    cout << dp[n][m] << endl;
    print_LCS(s, t, n, m);
}


// Recursive Solution - dp can be used for top down
int LCSRecursive(string &a, string &b, int i=0, int j=0) {
      int n = a.length(), m = b.length();
      if(i >= n || j >= m) {
            return 0;
      }

      if(a[i] == b[j]) {
            return 1 + LCSRecursive(a, b, i+1, j+1);
      }     

      // a[i] != b[i]
      return max(LCSRecursive(a, b, i+1, j), LCSRecursive(a, b, i, j+1));
}


// Longest Common Subsequence in 3 Strings 

int LCS(string &a, string &b, string &c, int i=0, int j=0, int k=0) {
      if(i == a.length() || j == b.length() || k == c.length()) {
            return 0;
      }
      if(a[i] == b[j] && b[j] == c[k]) {
            return 1 + LCS(a, b, c, i + 1, j + 1, k + 1);
      }
      
      return 
      max({LCS(a, b, c, i + 1, j, k), 
      LCS(a, b, c, i, j + 1, k), 
      LCS(a, b, c, i, j, k + 1)});
}


void solve() {
    string s, t;
    cin >> s >> t;

    LCS(s, t);
}


/*
An eisier problem 

Different From LCS 
Since here the first string present as subsequence in second string 
We just have to check that 

Simple Two pointer O(n)
*/

bool isSubSequence(string sub, string str) {
	int m = sub.length(), n = str.length();
	int j = 0;
	for (int i = 0; i < n && j < m; i++) {
		if (sub[j] == str[i])
		{
			// if char match move pointer forward
			j++;
		}
	}
	// check if all chars we covered
	return (j == m);
}



signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    solve();

    cout << isSubSequence("apple", "abpcplea") << "\n";
	cout << isSubSequence("orange", "sporauungtte") << "\n";
	cout << isSubSequence("pie", "plea") << "\n";
}