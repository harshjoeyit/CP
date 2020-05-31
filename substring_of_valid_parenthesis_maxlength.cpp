#include<bits/stdc++.h>
using namespace std;

// (()())()) - find maxlength substring that is valid

#define int long long 
string s;

void solve() {
    cin >> s;
    int n = s.length(), ans = 0;
    stack<int> st;
    st.push(-1);

    for(int i=0; i<n; i++) {
        if(s[i] == '(') {
            st.push(i);
        
        } else if(s[i] == ')') {
            st.pop();
            if(st.empty())
                st.push(i);
            else
                ans = max(ans, i - st.top());
        }
    }
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