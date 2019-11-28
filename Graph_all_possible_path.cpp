#include<bits/stdc++.h>
using namespace std;

vector<int> G[1000];
vector<bool> vis(1000, false);
int c = 0;

void print_path(vector<int> &v)
{
    for(auto &x: v)
        cout << x << " ";
    cout << endl;
}

void count_path(int s, int d, vector<int> &path, int k)
{
    vis[s] = true;
    path.push_back(s);
    if(s == d)
    {
        print_path(path);
        ++c;
    }

    else
    {
        for(int i = 0; i < G[s].size(); i++)
            if(!vis[G[s][i]])
                count_path(G[s][i], d, path, k+1);
    }
    path.pop_back();
    vis[s] = false;
}   

int main()
{    
    int x, y, nodes, edges;
    cin >> nodes;       //Number of nodes
    cin >> edges;       //Number of edges

    

    for(int i = 0; i < edges; ++i)
    {
            cin >> x >> y;
        G[x].push_back(y);        //Undirected Graph
        G[y].push_back(x);        
    }

    cout << "s, d: ";
    cin >> x >> y;

    vector<int> path;
    int k = 0;

    count_path(x, y, path, 0);

    cout << c << endl;

    return 0;
}