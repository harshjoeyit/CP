#include<bits/stdc++.h>
using namespace std;

#define int long long 
const int mxN = 1010;
int a[mxN];
int n;

bool isPerfectSquare(int x)  { 
    int s = sqrt(x); 
    return (s*s == x); 
} 
  
bool isFibonacci(int n) { 
    return isPerfectSquare(5*n*n + 4) || 
           isPerfectSquare(5*n*n - 4); 
} 

void solve() {
    cin >> n;
    memset(a, 0, sizeof(a));
    for(int i=0; i<n; i++)
        cin >> a[i];
    
    for(int i=0; i<n; i++)
        if(isFibonacci(a[i]))
            cout << a[i] << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}