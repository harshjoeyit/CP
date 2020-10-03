#include<bits/stdc++.h>
using namespace std;

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n;i++)
        cin >> a[i];
    vector<int> pre(n);
    pre[0] = a[0];
    for(int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }

    int len = INT_MIN;
    unordered_map<int, int> ump;

    for(int i = 0; i < n; i++) {
        if(pre[i] == 0) {
            len = max(len, i + 1);
            if(ump.find(0) == ump.end())
                ump[0] = i;
            continue;
        }
        if(ump.find(pre[i]) != ump.end()) {
            len = max(len, i - ump[pre[i]]);
        } else {
            ump[pre[i]] = i;
        }
    }
    cout << len << endl;

}