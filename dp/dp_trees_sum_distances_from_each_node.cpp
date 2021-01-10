
/*
Sum of distances of each node from each node 

https://leetcode.com/problems/sum-of-distances-in-tree/submissions/
https://www.youtube.com/watch?v=Agsuftu_cwg
*/

#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<int> cnt;
vector<int> dis;

// count the subtree nodes, fill dis
int dfs1(int u, int par) {  
    for(auto v: g[u]) {
        if(v != par) {
            dfs1(v, u);
            // sum of distances of subtree nodes for u
            dis[u] += dis[v] + cnt[v];
            // cnt of subtree nodes
            cnt[u] += cnt[v];
        }
    }
    cnt[u] += 1;
    return cnt[u];
}

// we know correct ans for 0, find for others 
void dfs2(int u, int par) {
    for(auto v: g[u]) {
        if(v != par) {
            // remove part due to v, 
            // add extra distance for every subtree node in u
            dis[v] = (dis[u] - cnt[v]) + (n - cnt[v]);
            dfs2(v, u);
        }
    }
}

vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    ::n = n;
    g.assign(n, vector<int>());
    dis.assign(n, 0);
    cnt.assign(n, 0);
    
    for(auto e: edges) {
        int u = e[0], v = e[1];
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    dfs1(0, -1);
    dfs2(0, -1);
    
    return dis;
}