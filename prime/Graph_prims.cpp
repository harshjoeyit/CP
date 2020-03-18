#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 5;
typedef pair<long long, int> PII;
bool marked[MAX];
vector <PII> G[MAX];


long long prim(int u)
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;                  //min heap
    int y;
    long long minimumCost = 0;
    PII p;
    Q.push(make_pair(0, u));

    while(!Q.empty())
    {
        p = Q.top();
        Q.pop();
        u = p.second;

        if(marked[u] == true)
            continue;

        minimumCost += p.first;
        marked[u] = true;

        for(auto p: G[u])
            if(marked[p.second] == false)
                Q.push(p);
    
    }
    return minimumCost;
}



int main()
{
    
    int nodes, edges, x, y;
    long long weight, minimumCost;
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        G[x].push_back(make_pair(weight, y));
        G[y].push_back(make_pair(weight, x));
    }
    
    minimumCost = prim(1);                              // Selecting 1 as the starting node
    cout << minimumCost << endl;
    return 0;

}