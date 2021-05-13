#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(int n,int p, vector<int> a, vector<int> b, vector<int> d) {    
    vector<int> indeg(n+1, 0);
    unordered_map<int, pair<int ,int>> pipes;
    for(int i=0; i<p; i++) {
        indeg[b[i]]++;
        pipes[a[i]] = {b[i], d[i]};
    }
    vector<vector<int>> ans;

    for(int i=0; i<p; i++) {
        if(indeg[a[i]] == 0) {
            // a tank can be installed here, find the tap 
            int house = a[i], minDia = INT_MAX;
            while(pipes.count(house)) {
                auto pipe = pipes[house];
                house = pipe.first;
                minDia = min(minDia, pipe.second);
            }
            // tank => a[i], tap => house
            ans.push_back({a[i], house, minDia});
        }
    }
    return ans;
}

int main() {
    int n = 9, p = 6;
    vector<int> a = {7,5,4,2,9,3};
    vector<int> b = {4,9,6,8,7,1};
    vector<int> d = {98,72,10,22,17,66};

    auto ans = solve(n, p, a, b, d);
    for(auto v: ans) {
        for(auto val: v) {
            cout << val << " ";
        }
        cout << endl;
    }
}