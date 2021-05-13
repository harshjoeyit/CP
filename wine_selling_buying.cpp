/*
    https://www.spoj.com/problems/GERGOVIA/
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

/*
    Method 2. O(n) time, O(1) space
*/
void solve(n) {
    vector<pair<int, int>> sellers, buyers;
    for(int i=0, x; i<n; i++) {
        cin >> x;
        if(x > 0)   buyers.push_back({x, i});
        else        sellers.push_back({-x, i});
    }

    int i=0, j=0, cost = 0;
    while(i < buyers.size() && j < sellers.size()) {
        auto &b = buyers[i], &s = sellers[j];
        int trans = min(b.first, s.first);
        cost += trans * abs(b.second - s.second);
        
        b.first -= trans, s.first -= trans;
        if(b.first == 0)  i++;
        if(s.first == 0) j++;
    }
    cout << cost << "\n";
}

/*
    Method 1. O(n) time, O(1) space
*/
void solve(int n) {
    vector<int> a(n);
    for(auto &val: a) {
        cin >> val;
    }

    int cost = 0, buyer = 0, seller = 0;
    while(1) {
        while(buyer < n && a[buyer] <= 0)       buyer++;
        while(seller < n && a[seller] >= 0)     seller++;
        if(buyer == n || seller == n) {
            break;
        }
        int trans = min(a[buyer], -a[seller]);
        cost += trans * abs(buyer - seller);
        a[buyer] -= trans;
        a[seller] += trans;
    }
    cout << cost << "\n";
}