
/*
https://codeforces.com/problemset/problem/219/C
greedy

A colored string is given 
char A-Z denote colors 
repaint is so that no adjacent colors are same if we are given k colors 
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {
    string s;
    int n, k, cnt, a, b;
    cin >> n >> k >> s;
    cnt = 0;
    
    if(k == 2) {
        a = b = 0;
        
        // We have two cases so we print the one with minimum changes 
        // ABABABAB...
        // BABABABAB...

        for(int i=0; i<n; i++) {
            if(i%2 == 0) {
                if(s[i] == 'B') ++a;
                if(s[i] == 'A') ++b;
            } else {
                if(s[i] == 'A') ++a;
                if(s[i] == 'B') ++b;
            }
        }
        
        if(a < b) {
            cout << a << "\n";
            for(int i=0; i<n; i++) {
                cout << ((i%2==0)?'A':'B');
            }cout << "\n";

        } else {
            cout << b << "\n";
            for(int i=0; i<n; i++) {
                cout << ((i%2!=0)?'A':'B');
            }cout << "\n";
        }        
        return;

    } 
    // k >= 3
    // greedy strategy
    for(int i=0; i<n-1; i++) {
        // like 'AAA' - changes to 'ABA'
        if(s[i] == s[i+1] and s[i] == s[i+2]) {                

            for(int j=0; j<k; j++) {

                if(s[i+1] != (j+'A')) {
                    s[i+1] = (j+'A');
                    cnt++;
                    break;
                }
            }
        } else if(s[i] == s[i+1]) {
            // like BAA - chnges to BCA
            for(int j=0; j<k; j++) {
                
                if(i > 0 && s[i-1] != (j+'A') && s[i] != (j+'A')) {
                    s[i] = (j+'A');
                    cnt++;
                    break;

                // cannot check previous char for i = 0 
                } else if(i == 0 && s[i] != (j+'A')) {  
                    s[i] = (j+'A');
                    cnt++;
                    break;
                }
            }
        }
    }
    cout << cnt << "\n";
    cout << s << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}