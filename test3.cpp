#include<bits/stdc++.h>
using namespace std;

#define int long long int

void solve() {
    int x, n, m, x1, x2;
    cin >> x >> n >> m;
    
    while((n > 0) || (m > 0)) {
        
        x1 = x;
        x2 = x;

        if(n > 0) {
            x1 = x1/2 + 10;;
        }
        if(m > 0) {
            x2 = x2 - 10;
        }

        if(x1 == x || x2 == x) {
            if(x == x2) {
                x = x1;
                --n;
            } 
            if(x == x1) {
                x = x2;
                --m;
            }
        } else {
            if(x1 > x2) {
                x = x2;
                --m;
            } else {
                x = x1;
                --n;
            }
        }

        if(x <= 0) {
            break;
        }
        cout << x1 << " " << x2 << endl;
        cout << x << " \n";
    }

    if(x <= 0)
        cout << "YES\n";
    else 
        cout << "NO\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}