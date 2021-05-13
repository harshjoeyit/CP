/*
NOTE: This (GREEDY) Algorithm MINIMIZES THE CASH FLOW and there can be mutiple solution 
with SAME MINIMIZED CASH FLOW, this gives one such solution and it DOES NOT GUARANTEE MINIMUM TRANSACTIONS 

Ex - A, B, C, D, E are friends

A D 4
A E 1
B D 5
B E 2
C D 3
C E 8
A B 5
B A 5

Total Cash Flow = 4+1+5+2+3+8+5+5 = 33

This GREEDY algo will give this solution

C D 11
B E 7
A E 4
A D 1

Cash flow = 23

When algorithm for MINIMIZE TRANSACTION IS USED 

A D 5
B D 7
C E 11

Cash Flow = 23

NOTE: Cash Flow is same in both case but number of transactions are not.
*/

#include<bits/stdc++.h>
using namespace std;

#define pi pair<int, int>


// METHOD 1. O(nlogn) Using Max Heaps
vector<vector<int>> simplifyDebt(vector<vector<int>> &transac) {
    priority_queue<pi> givers, takers;      // { 'amount', 'person' }
    unordered_map<int, int> netAmount;      // netAmount['person'] = 'amount'
    
    for(auto t: transac) {
        int x = t[0], y = t[1], amt = t[2];
        netAmount[x] -= amt;
        netAmount[y] += amt;
    }

    for(auto pr: netAmount) {
        int i = pr.first, amt = pr.second;
        if(amt > 0) {
            takers.push({amt, i});
        } else {
            // make amt positive
            givers.push({-amt, i});
        }
    }

    vector<vector<int>> simplifiedTransac;

    // we always settle up the biggest giver and biggest taker
    while(!givers.empty() && !takers.empty()) {
        auto g = givers.top();  givers.pop();
        auto t = takers.top();  takers.pop();

        int transAmt = min(g.first, t.first);
        simplifiedTransac.push_back({g.second, t.second, transAmt});

        // one of the giver or taker fill be done(exhausted) after the transaction
        if(g.first > transAmt) {
            givers.push({g.first - transAmt, g.second});
        } 
        else if(t.first > transAmt) {
            takers.push({t.first - transAmt, t.second});
        }
    }

    return simplifiedTransac;
}

// Method 2. O(n*n) Using Same Approach but looping over whole array to find maximim giver/taker each time

int main() {
    int people, totalTrans;
    vector<vector<int>> transac;

    cin >> people >> totalTrans;

    for(int i=0; i<totalTrans; i++) {
        int x, y, amt;
        cin >> x >> y >> amt;
        // x --- amt ---> y
        transac.push_back({x, y, amt});
    }
    auto ans = simplifyDebt(transac);

    for(auto t: ans) {
        cout << t[0] << "--- " << t[2] << " ---> " << t[1] << endl;  
    }
} 