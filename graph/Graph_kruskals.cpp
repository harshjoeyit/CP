#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define pii pair<int, int>
 
const int mod = 1e15 + 7;
const int MAX = 1e5 + 5;

struct ed{
    int w, x, y;
};
int id[MAX], nodes, edges;
pair <int, pii> p[MAX];
vector<ed> mst;


void initialize()
{
    for(int i = 0; i < MAX; ++i)
        id[i] = i;
}
int root(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}
void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

int kruskal(pair<int, pii> p[])
{
    int x, y, cost, min_cost = 0;
    for(int i = 0; i < edges; ++i)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(root(x) != root(y))
        {
            min_cost += cost;
            union1(x, y);
            mst.push_back({cost, x, y});
        }    
    }
    return min_cost;
}


signed main()
{
    int x, y, wt, cost, min_cost;
    initialize();
    cin >> nodes >> edges;

    for(int i = 0; i < edges; ++i)
    {
        cin >> x >> y >> wt;
        p[i] = make_pair(wt, make_pair(x, y));
    }

    // Sort the edges in the ascending order
    sort(p, p + edges);
    min_cost = kruskal(p);
    cout << min_cost << endl;

    for(auto &e: mst)
        cout << e.x << " " << e.y << " " << e.w << endl;
}