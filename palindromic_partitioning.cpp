/*
    Print All Palindromic Partitions
    https://www.geeksforgeeks.org/given-a-string-print-all-possible-palindromic-partition/

    Similar Problems
    Find min palindromic partitions
    https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1
*/

#include<bits/stdc++.h>
using namespace std;


void print(string s, vector<pair<int, int>> buffer) {
    for(auto p: buffer) {
        int i = p.first, l = p.second - p.first + 1;
        cout << s.substr(i, l) << " ";
    }
    cout << endl;
}

/*
    Method 1: O(n^4), Brute Force
*/

bool isPal(string s, int i, int j) {
    for(; i<j; i++, j--) {
        if(s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

void go(string &s, int i, vector<pair<int, int>> &buffer) {
    int n = s.length();
    if(i == n) {
        print(s, buffer);
        return;
    }

    for(int j=i; j<n; j++) {
        if(isPal(s, i, j)) {
            buffer.push_back({i, j});
            go(s, j+1, buffer);
            buffer.pop_back();
        }
    }
}

void palindromePartitioning1() {
    string s = "nitin";
    vector<pair<int, int>> buffer;  // store {i, j} if s[i...j] is palindrome
    go(s, 0, buffer);
}


/*
    Method 2: O(n^2), Using DP
*/
vector<vector<int>> pal;

// plaindromic substring 
void precalcPalindromes(string &s) {
    int n = s.length();
    pal.assign(n, vector<int>(n, 0));
    for(int l=1; l<=n; l++) {
        for(int i=0; i<=n-l; i++) {
            int j = i+l-1;
            if(l <= 2) {
                pal[i][j] = (s[i] == s[j]);
            } 
            else if(s[i] == s[j]) {
                pal[i][j] = pal[i+1][j-1];
            }
        }
    }
} 

// efficient isPal
bool isPal(int i, int j) {
    return pal[i][j];
}

void go(string &s, int i, vector<pair<int, int>> &buffer) {
    int n = s.length();
    if(i == n) {
        print(s, buffer);
        return;
    }

    for(int j=i; j<n; j++) {
        if(isPal(i, j)) {
            buffer.push_back({i, j});
            go(s, j+1, buffer);
            buffer.pop_back();
        }
    }
}

void palindromePartitioning2() {
    string s = "nitin";
    precalcPalindromes(s);
    vector<pair<int, int>> buffer;  // store {i, j} if s[i...j] is palindrome
    go(s, 0, buffer); 
}


/*
    Find min palindromic partitions
    Method: O(n^2)
*/

vector<int> dp;

int go(string &s, int i) {
      int n = s.length();
      if (i >= n) {
            return 0;
      }

      int &ans = dp[i];
      if(dp[i] != -1) {
            return dp[i];
      }
      ans = INT_MAX;
      
      for (int j = i; j < s.length(); j++) {
            if(pal[i][j]) {
                  ans = min(ans, 1 + go(s, j + 1));
            }
      }
      return ans;
}

void minPartitions() {
    string s;
    cin >> s;
    precalcPalindromes(s);
    dp.assign(s.length(), -1);
    cout << go(s, 0) - 1 << endl;
}