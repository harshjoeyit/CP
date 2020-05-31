#include<bits/stdc++.h>
using namespace std;

#define NIL -1
const int V = 1000;
vector<int> G[V+1];
int Count = 0;

void print_stack(stack<pair<int, int>> &stck, int u, int v)
{
    pair<int, int> p = make_pair(u,v), q;

    while(!stck.empty() && (q = stck.top()) != p)
    {
        cout << "( " << q.first << ", " << q.second << ")" << ", ";
        stck.pop(); 
    }
    cout << "( " << q.first << ", " << q.second << ")" << ", ";
    stck.pop(); 
    cout << endl;
     ++Count;
}


void biconnected_comp(int u, bool visited[], int disc[], int low[], int parent[], stack<pair<int, int>> &stck)
{
    static int time = 0;

    // counting children in DFS Tree
    int children = 0;

    visited[u] = true;

    // discovery time 
    disc[u] = low[u] = ++time;

    // go to all the vertices adjacent to this
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];

        if(!visited[v])
        {
            children ++;
            stck.push(make_pair(u,v));

            parent[v] = u;
            biconnected_comp(v, visited, disc, low, parent, stck);

            low[u] = min(low[u], low[v]);              
            
            // children greater than 1 not necessary for biconnected 
            //component eg 1----2 or 3---4       , these are biconnected components
            if(parent[u] == NIL)//&& children > 1)
                print_stack(stck, u, v);

            if(parent[u] != NIL && low[v] >= disc[u])
                print_stack(stck, u, v);
            
        }
        else if(v != parent[u])
        {
            low[u] = min(low[u], disc[v]);
            
            // during backtracking the edge should not be pushed again if its dicovery time is greater than actual parent 
            if(disc[v] < disc[u])
                stck.push(make_pair(u,v));
        }
    }   
}


int main()
{
    int n, m, x, y;
    bool *visited = new bool[V+1];
    int *disc = new int[V+1];
    int *low = new int[V+1];
    int *parent = new int[V+1];

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        cin >> x >> y;
        G[x].push_back(y);  
        G[y].push_back(x);
    }

    for(int i = 1; i <= V; i++)
    {
        parent[i] = NIL;
        visited[i] = false;
    }

    stack<pair<int, int>> stck;

    for(int i = 1; i <= n; i++)
        if(!visited[i])
            biconnected_comp(i, visited, disc, low, parent, stck);


    int j = 0;
    while(!stck.empty())
    {
        cout << "( " << stck.top().first << ", " << stck.top().second << ")" << ", ";
        stck.pop();
        j = 1;
        
    }
    if(j) 
        ++Count;
    cout << endl << " count "  << Count<< endl;

}

