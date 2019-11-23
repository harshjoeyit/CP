#include<bits/stdc++.h>
using namespace std;

vector<int> visited(1000);
vector<int> G[1000];
vector<int> previous(1000);




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

        for(int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
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
    }

    for(int i = 1; i <= nodes; i++)
        previous[i] = i;
    // display(adj);

    //BFSTraversal(G, nodes);
    //cout << endl;

    // DFSTraversal(G, nodes);

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

    return 0;
}