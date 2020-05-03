#include<bits/stdc++.h>
using namespace std;
#define int long long

// substring with at least k uniq characters 
int k_uniq_substring(string s, int k) {
    int n = s.length();
    if(s.length() < k) {
        return 0;
    }

    int ans = 0;
    unordered_set<char> st;

    // check for each substring 
    for(int i=0; i<n; i++) {
        st.clear();
        
        for(int j=i; j<n; j++) {
            st.insert(s[j]);    
            
            if(st.size() == k) {
                ++ans;
            } else if(st.size() > k) {              // break if uniq chars > k
                break;
            }
        }
    }

    return ans;
}

void solve() {
    string s;
    int k;
    cin >> s >> k;
    cout << k_uniq_substring(s, k) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}
