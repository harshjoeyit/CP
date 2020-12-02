
#include<bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    
    int cnt[26] = {};
    queue<char> q;
    
    for(int i=0; i<n; i++) {
        char c;
        cin >> c;
        cnt[c - 'a'] += 1;
        q.push(c);
        
        while(!q.empty()) {
            int f = q.front() - 'a';
            if(cnt[f] == 1) {
                cout << q.front() << " ";
                break;
            } else {
                q.pop();
            }
        }
        if(q.empty()) {
            cout << "-1 ";
        }
    }
    cout << "\n";
}