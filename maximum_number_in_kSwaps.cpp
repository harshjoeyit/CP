#include<bits/stdc++.h>
using namespace std;

// brute force O((n^2)^k)
// n^2 recrusive calls untill k becomes 0 
void findMaximumNum(string str, int k, string& mx)  { 
    if(k == 0) 
        return; 
    
    int n = str.length(); 
    
    for(int i = 0; i < n - 1; i++) { 
        for (int j = i + 1; j < n; j++) { 
            if (str[i] < str[j]) { 
                swap(str[i], str[j]);
                mx = max(mx, str);
                // k-1 swaps remaining 
                findMaximumNum(str, k - 1, mx);
                // backtracking - make string as it was 
                swap(str[i], str[j]); 
            } 
        } 
    } 
} 


// O(n^k)
// For every recursive call n recursive calls is generated until 
// the value of k is 0. So total recursive calls are 
void findMaximumNum(string str, int k, string& ans, int i) { 
    // return if no swaps left 
    if (k == 0) 
        return; 
  
    int n = str.length(); 
  
    char maxdig = str[i]; 
    for (int j = i + 1; j < n; j++) { 
        maxdig = max(maxdig, str[j]);
    }
    if (maxdig != str[i]) {
         --k; 
    }
  
    // search this maximum among the rest 
    for (int j = i; j < n; j++) { 
        // If digit equals maxdig swap 
        // the digit with current 
        if (str[j] == maxdig) {  
            swap(str[i], str[j]);
            ans = max(ans, str);
            // recurse other swaps after cur
            findMaximumNum(str, k, ans, i + 1); 
            // Backtrack 
            swap(str[i], str[j]); 
        } 
    } 
} 

void solve() {
    int k;
    string s;
    cin >> s >> k;
    string ans = s;

    // brute force 
    // findMaximumNum(s, k, ans);
    
    // optimized brute force 
    findMaximumNum(s, k, ans, 0);
    
    cout << ans << "\n";
}

int main() {
    solve();
}