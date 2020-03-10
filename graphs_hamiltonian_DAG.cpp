#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

vi G[100005];
vi indegree(100005);
vector<bool> vis(100005);
int n, m;

vi topo_sort()
{
    queue<int> q;
    vi topo;

    for(int i = 1; i <= n; i++)
        if(indegree[i] == 0)
            q.push(i);

    while( ! q.empty())
    {
        int u = q.front();
        q.pop();
        topo.emplace_back(u);

        for(auto &v: G[u])
        {
            --indegree[v];
            if(indegree[v] == 0)
                q.push(v); 
        }
    }
    return topo;
}


bool hamil_found = false;
void hamiltonian_path(int st, int en)
{
    static int vis_tot = 1;
    if(st == en && vis_tot == n)
    {
        hamil_found = true;
        return;
    }

    for(auto v: G[st])
        if( !vis[v])
        {
            vis[v] = true;
            ++vis_tot;
            hamiltonian_path(v, en);
            --vis_tot;
            vis[v] ;
        }
}


int main()
{
    int x, y;
    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        cin >> x >> y;
        G[x].push_back(y);
        ++indegree[y];
    }

    vi topo_sorted = topo_sort();   

    vis[*topo_sorted.begin()] = true;
    hamiltonian_path(*topo_sorted.begin(), *(topo_sorted.end()-1));
    cout << hamil_found << endl;
}