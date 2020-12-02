#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> ans;
    unordered_map<string, int> cnt;
    string s, out;

    for(int i=0; i<n; i++) {
        cin >> s;
        out = s;
        if(cnt[s] > 0) {
            out += to_string(cnt[s]);
        }
        ans.push_back(out);
        cnt[s] += 1;
    }

    for(auto word: ans) {
        cout << word << " ";
    }
    cout << endl;
}