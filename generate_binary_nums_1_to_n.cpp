#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    queue<string> q;
    q.push("1");
    
    while(n--) {
        auto f = q.front();
        q.pop();
        cout << f << " ";
        q.push(f + "0");
        q.push(f + "1");
    } 
    cout << "\n";
}