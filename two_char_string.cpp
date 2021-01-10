
/*
      You are given a string s consisting only of characters 'a' and 'b'​​​​.
      You can delete any number of characters in s to make s balanced. s is balanced 
      if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.
      Return the minimum number of deletions needed to make s balanced.
*/

#include<bits/stdc++.h>
using namespace std;

// DP
int minimumDeletions(string s) {
    int  n = s.length(), b = 0;
    vector<int> dp(n+1, 0);
    // dp[i] = char removed to make 
    // i length of string balanced
    
    for(int i=0; i<n; i++) {
        if(s[i] == 'a') {
            // Case 1: keep current a, assuming prev chars must be a...a
            // and removing all 'b' before i
            
            // Case 2: remove current a assuming prev chars must be a....b..b
            // so we nned to remove current a + whatever it takes to make 
            // string before this index a balanced string
            dp[i+1] = min(b, 1 + dp[i]);
        
        } else {
            // we always consider that string is like a...a
            // so we do not delete b 
            dp[i+1] = dp[i];
            b++;
        }   
    }
    
    return dp[n];
}


// greedy 
int minimumDeletions(string s) {
    int a = 0, b = 0, l = 0, r = s.size() - 1, res = 0;
    for (auto ch : s) {
        a += ch == 'a'; 
        b += ch == 'b';
    }
    
    while(l < r) {
        if(a && s[l] == 'a') {
            l++;
            --a;
        
        } else if(b && s[r] == 'b') {
            --r;
            --b;
        
        } else {
            // when this executes 
            // s[l] = 'b'
            // s[r] = 'a'
            if(a < b) {
                // count of a less than b, remove a from back
                --a;
                --r;
            } else {
                // count of b less than a, remove b from from front
                --b;
                ++l;
            }
            // add count;
            res++;
        }
    }
    
    return res;
}


// simplest 
int minimumDeletions(string s) {
    int a = count(begin(s), end(s), 'a'), b = 0, res = a;
    for (auto ch : s) {
        b += ch == 'b';
        a -= ch == 'a';
        res = min(res, b + a);
    }
    return res;
}