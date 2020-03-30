#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solve() {
    int i = 0; 
    for(; i<6; i++) 
        if(i%2)
            cout << i << ": odd\n";
    if(i%2==0)                                  // if is out of the loop
        cout << i << ": even\n";
    else 
        cout << i << ": odd\n";


    cout << "\n\n";
    i = 0; 
    for(; i<6; i++) 
        if(i%2)
            cout << i << ": odd\n";
    else if(i%2==0)                                  // else is in the loop
        cout << i << ": even\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}