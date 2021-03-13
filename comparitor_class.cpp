

#include<bits/stdc++.h>
using namespace std;

// write comparitor classe

struct job { 
    int id, deadline, profit;
    bool operator < (const job &rhs) const {
        return profit > rhs.profit;
    }
};

int main() {
    vector<job> v;
    v.push_back({1, 3, 40});
    v.push_back({2, 4, 20});
    v.push_back({3, 5, 80});

    sort(v.begin(), v.end());

    for(auto j: v) {
        cout << j.profit << " ";
    }

    priority_queue<job> pq;
    pq.push({1, 3, 40});
    pq.push({2, 4, 20});
    pq.push({3, 5, 80});

    while(!pq.empty()) {
        cout << pq.top().profit << " ";
        pq.pop();
    }
}