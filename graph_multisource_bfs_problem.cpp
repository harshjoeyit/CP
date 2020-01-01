#include<bits/stdc++.h>
using namespace std;

// given position of trees on x axis - find the posistion of pepole such that 
// sum each persons min dist from a tree is minimized and find the persons position on the axes  

// logic used - multisource bfs from each tree
// add the dist of each coordinate/position from the starting tree

#define int long long int
mt19937 rnd(time(NULL));

signed main()
{
    int n, m;
    cin >> n >> m;

    vector<int> v(n), res;          // v - positions of the trees 
    map<int, int> d;
    int ans = 0;
    queue<int> q;

    for(auto &x: v)
    {
        cin >> x;
        d[x] = 0;
        q.push(x);
    }

    while(!q.empty() && (res.size() < m))
    {
        int u = q.front();
        q.pop();

        if(d[u] != 0)
        {
            ans += d[u];
            res.push_back(u);
        }
        if(!d.count(u-1))
        {
            d[u-1] = d[u] + 1;
            q.push(u-1);
        }
        if(!d.count(u+1))
        {
            d[u+1] = d[u] + 1;
            q.push(u+1);
        }
    }

    cout << ans << endl;
    shuffle(res.begin(), res.end(), rnd);
    for(auto &x : res)
        cout << x <<" ";
    cout << endl;
}