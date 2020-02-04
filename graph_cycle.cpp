#include<bits/stdc++.h>
using namespace std;

vector<int> visited(1000);
vector<int> G[1000];
vector<int> previous(1000);
vector<int> Arr(1000);
vector<pair<int, int>> Edges;


int root(int a)
{
    while(a != Arr[a])
    {
        Arr[a] = Arr[Arr[a]];
        a = Arr[a];
    }
    return a;
}


void Union(int a, int b)
{
    int r_a = root(a);
    int r_b = root(b);

    if(r_a == r_b)
        return;

    if(r_a < r_b)
        Arr[r_a] = r_b;
    else
        Arr[r_b] = r_a;
}


bool Find(int a, int b)
{
    return (root(a) == root(b));
}


bool find_cycle_dsu()
{
    for(int i = 0; i < Edges.size(); i++)
    {
        int a = Edges[i].first;
        int b = Edges[i].second;

        if(Find(a, b))
            return true;
        else
            Union(a, b);
    }
    return false;
}


bool find_cycle(int u)
{   
    stack<int> s;
    s.push(u);
    visited[u] = 1;

    while(! s.empty())
    {
        u = s.top();
        s.pop();
        //cout << u << " ";
        for(auto v: G[u])
        {
            //  cout << "v: " << v << " -prev = "<< previous[v] << endl; 
            if(visited[v] == 1 && v != previous[u])         // if a visited node is found then it shuld not be the parent or previous node that came earlier in dfs
                return true;

            if(visited[v] != 1)
            {
                s.push(v);
                visited[v] = 1;
                previous[v] = u;
            }
        }

    }
    return false;
}



int main()
{
    
    int x, y, nodes, edges;
    cin >> nodes;       //Number of nodes
    cin >> edges;       //Number of edges

    for(int i = 0;i < edges;++i)
    {
            cin >> x >> y;
        G[x].push_back(y);        //Undirected Graph
        G[y].push_back(x);       
        Edges.push_back(make_pair(x, y)); 
    }

    for(int i = 1; i <= nodes; i++)
    {
        previous[i] = i;
        Arr[i] = i;
    }

    int i;
    bool flag = 0;
    visited.assign(1000, 0);
    for(i = 1; i <= nodes; i++)
    {
        if(! visited[i])
        {
            if(find_cycle(i))
            {
                flag = 1;
                break;
            }
            cout << endl;
        }
    }

    if(flag)
        cout << "cycle" << endl;
    else
        cout << "no cycle" << endl;


    if(find_cycle_dsu())
        cout << "cycle" << endl;
    else
        cout << "no cycle" << endl;

    return 0;
}