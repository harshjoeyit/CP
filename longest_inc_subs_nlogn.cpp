#include<bits/stdc++.h>
using namespace std;


int LIS2(vector<int> a) {
    vector<int> v;
    for (int i = 0; i < a.size(); i++) {
        auto it = lower_bound(v.begin(), v.end(), a[i]);
        if (it != v.end()) 
            *it = a[i];
        else 
            v.push_back(a[i]);
    }
    return v.size();
}

// longest non decreasing seq
// O(nlogn)
int LNDS(vector<int> a) {
    multiset<int> s;
    for(int i = 0; i < a.size(); i++) {
        s.insert(a[i]);
        auto it = s.upper_bound(a[i]);
        if(it != s.end())
            s.erase(it); 
    }
    return s.size();
}

//  O(nlogn)
int LIS(vector<int> a) {
    multiset<int> s;
    for(int i = 0; i < a.size(); i++) {
        s.insert(a[i]);
        auto it = s.lower_bound(a[i]);
        it++;
        if(it != s.end())
            s.erase(it); 
    }
    return s.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << LIS(a) << endl;
    cout << LNDS(a) << endl;
    cout << LIS2(a) << endl;
    //ex: 
    // 5
    // 1 1 2 1 3
}