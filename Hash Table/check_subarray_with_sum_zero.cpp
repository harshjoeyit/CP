#include<bits/stdc++.h>
using namespace std;

signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> prefix(n);
    prefix[0] = v[0];
    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + v[i];
    }
    bool flag = 0;
    unordered_set<int> s;
    for(int i = 0; i < n; i++) {
        if(s.find(prefix[i]) != s.end() or prefix[i] == 0) {
            flag = 1;
            break;
        }
            
        s.insert(prefix[i]);
    }
    if(flag)
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;
}