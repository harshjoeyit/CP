
// check if binary number is divisible by 3

#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solve() {
    string s;
    cin >> s;
    
    reverse(s.begin(), s.end());
    int sum = 0;
    
    for(int i=0; i<s.length(); i++) {
        if(s[i] == '1') {
            if(i%2 == 0)                // every bit at even index places contribute 1+3*k      
                sum += 1;
            else 
                sum += 2;               // every bit at odd index place contributes 2+3*p
        }
    }
                                        // so ignoring 3*k + 3*p and adding the rest 
    if(sum % 3 == 0)
        cout << "1" << endl;
    else 
        cout << "0" << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}