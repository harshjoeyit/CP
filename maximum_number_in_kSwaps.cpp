#include<bits/stdc++.h>
using namespace std;

#define int long long 

void findMaximumNum(string str, int k, string& max)  { 
    if(k == 0) 
        return; 
  
    int n = str.length(); 
    for(int i = 0; i < n - 1; i++) { 
        
        for (int j = i + 1; j < n; j++) { 
            
            if (str[i] < str[j]) { 
                swap(str[i], str[j]); 
  
                if (str.compare(max) > 0) 
                    max = str; 
  
                findMaximumNum(str, k - 1, max); 
  
                // make string as it was after the call 
                swap(str[i], str[j]); 
            } 
        } 
    } 
} 

void solve() {
    int k;
    cin >> k;
    string s;
    cin >> s;
    string ans = s;
    
    findMaximumNum(s, k, ans);
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}