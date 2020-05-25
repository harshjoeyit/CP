#include<bits/stdc++.h>
using namespace std;
#define int long long int

string a[11];
int n, m;
string ans;

int compare(string &a, string &b) {
    int cnt = 0;
    for(int i=0; i<m; i++) {
        if(a[i] == b[i]) {
            ans[i] = a[i];
        } else {
            ++cnt;
        }
    }
    return cnt;
}

bool match(string str) {
    int cnt;
    for(int i=0; i<n; i++) {
        cnt = compare(str, a[i]);
        if(cnt > 1) {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    if(n == 1) {
        cout << a[0] << "\n";
        return;
    }

    string temp(m, '*');
    ans = temp;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i != j) {
                int cnt = compare(a[i], a[j]);
                if(cnt > 2) {
                    cout << "-1\n";
                    return;
                }
            }
        }
    }

    vector<string> possible;
    vector<int> pos;
    for(int i=0; i<m; i++) {
        if(ans[i] == '*') {
            pos.push_back(i);
        }
    }

    if(pos.size() == 0) {
        cout << ans << "\n";
        return;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            temp = ans;
            temp[pos[0]] = a[i][pos[0]];
            temp[pos[1]] = a[j][pos[1]];
            possible.push_back(temp);
        }
    }

    for(auto str: possible) {
        auto res = match(str);
        if(res) {
            cout << str << "\n";
            return;
        }
    }

    cout << "-1";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}