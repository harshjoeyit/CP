

// Intern party OPC-2 2020
// n - ax- by = k 
// given a, b, n, find x, y such that k is minimum



#include<bits/stdc++.h>
using namespace std;

#define int long long 
long double a, b, n;

void solve() {
    cin >> a >> b >> n;
    int i = 0, ans = 1 << 17, af1=0, af2=0;

    if((int)n % (int)a == 0) {
        af1 = n/a;
        af2 = 0;
    } else if((int)n % (int)b == 0) {
        af1 = 0;
        af2 = n/b;
    }  else if((int)a % (int)b == 0) {
        af1 = 0;
        af2 = n/b;
    } else if((int)b % (int)a == 0) {
        af1 = n/a;
        af2 = 0;
    } else {
        while(1) {
            int f1 = i;
            int rem = n - f1*a;
            int f2 = floor(rem/b);
            
            if(f1*a > n)
                break;
            int k = rem - (int)(f2*b);
            if(k < ans) {
                ans = rem - (int)(f2*b); 
                af1 = f1;
                af2 = f2;
                if(k == 0)
                    break;
            }
            ++i;
        }
    }
    cout << af1 << " "<< af2 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}