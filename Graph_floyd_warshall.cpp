#include<bits/stdc++.h>
using namespace std;
#define SIZE 100

vector <pair<int, int> > v[SIZE];   
int dist[SIZE][SIZE];

// for wiegted (may be -ve ) directed graph dis[i][j] means i --> j 
void floyd_warshall(int n)
{
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}


int main()
{
    int nodes, edges, x, y;
    int weight;
    cin >> nodes >> edges;

    for(int i = 0; i < edges; ++i)
    {
        cin >> x >> y >> weight;
        v[x].push_back(make_pair(weight, y));
        v[y].push_back(make_pair(weight, x));

        dist[x][y] = weight;
    }   // dis[i][j] means i --> j           -- directed graph  read from row to column i to j for min distance 

    for(int i = 1; i <= nodes; i++)
    {
        for(int j = 1; j <= nodes; j++)
        {
            if(i == j)
                dist[i][j] = 0;

            else if(dist[i][j] == 0)
                dist[i][j] = 9999;          // arbitrary max value 
        }
    }
    
    floyd_warshall(nodes);

    for(int i = 1; i <= nodes; i++)
    {
        for(int j = 1; j <= nodes; j++)
            cout << dist[i][j] << " ";
        cout << endl;
    }
}