
/*
You are provided two strings A and B. 
You have to transform string A into string B 
in minimum number of steps. Only one operation is 
allowed, chose any of the characters in string A and 
place it in the front of A. If its not possible to transform 
string A into string B then print -1 otherwise print the minimum 
number of steps required.

https://practice.geeksforgeeks.org/problems/transform-string/0
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long 

string a, b;

void solve() {
    
    cin >> a >> b;
    
    int n = a.length(), m = b.length();
    
    if(n != m) {
        cout << -1 << endl;
        return;
    }
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    
    for (int i=0; i<n; i++)   // count characters in A 
       cnt[b[i]-'a']++; 
    for (int i=0; i<n; i++)   // subtract count for 
       cnt[a[i]-'a']--;         // every character in B 
    for (int i=0; i<26; i++)   // Check if all counts become 0 
      if (cnt[i]) {
          cout << -1 << endl;
          return;
      }
    
    int ans = 0;
    int j = n-1;
    for(int i=n-1; i>=0; i--) {
        if(a[i] == b[j]) {
            ++ans;
            --j;
        }
    }    
        
    cout << n-ans << endl;
}



signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}



