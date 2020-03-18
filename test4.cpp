#include<bits/stdc++.h>
using namespace std;

int LIS(vector<int> v) {
    multiset<int> S;
    for(int i = 0; i < v.size(); i++) {
        S.insert(v[i]);
        auto it = S.upper_bound(v[i]);

        if(it != S.end())
            S.erase(it);
    }
    return S.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << LIS(v) << endl;
}