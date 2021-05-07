#include<bits/stdc++.h>
using namespace std;

void printBitonic(vector<int> &a) {
    int n = a.size();
    vector<int> inc(n, 1);
    vector<int> dec(n, 1);
    vector<int> incPath(n, 0);
    auto decPath = incPath;

    for(int i=0; i<n; i++) {
        incPath[i] = i;
        decPath[i] = i;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if(a[i] > a[j] && inc[j] + 1 > inc[i]) {
                inc[i] = inc[j] + 1;
                incPath[i] = j;
            }
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if(a[i] > a[j] && dec[j] + 1 > dec[i]) {
                dec[i] = dec[j] + 1;
                decPath[i] = j;
            }
        }
    }

    int ans = 1, j = 0;
    for (int i = 0; i < n; i++) {
        int curr = inc[i] + dec[i] - 1;
        if(curr > ans) {
            ans = curr;
            j = i;
        }
    }

    cout << ans << endl;
    vector<int> res;

    int st = j;
    while (incPath[st] != st) {
        res.push_back(a[st]);
        st = incPath[st];
    }
    res.push_back(a[st]);
    
    reverse(res.begin(), res.end());
    res.pop_back();

    st = j;
    while(decPath[st] != st) {
        res.push_back(a[st]);
        st = decPath[st];
    }
    res.push_back(a[st]);

    for(auto val: res) {
        cout << val << " ";
    }
}


int main() {
    //   vector<int> a = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    //   vector<int> a = {1,1,2,2,3,3,3,4,4,5,5,4,4,3,3,2,2,1};
    //   vector<int> a = {1,1,1,1,2,2,2,2,2};
    //   vector<int> a = {3,2,2,1,1};  
    // vector<int> a = {1,1,1,1,1};
      printBitonic(a);
}