#include<bits/stdc++.h>
using namespace std;

#define int long long int

signed main()
{
    int n, k;
    cin >> n;

    vector<vector<int> > dis;
    dis.assign(n, vector<int>(n));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> dis[i][j];
        
    cin >> k;

    // k new edges are added to the graph, they may the update for the existing edges 
    // calculate the sum of the distance b/w each pair of vertices, each time a edge is added 

    for(int p = 0; p < k; p++)
    {
        int a, b, wt, sum = 0;
        cin >> a >> b >> wt;
        --a; --b;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int x = dis[i][a] + dis[b][j] + c;          // if the new path includes the path a--b then
                int y = dis[i][b] + dis[a][j] + c;          // if the new path includes the path b--a then
                g[i][j] = min(dis[i][j], min(x, y));      // the path may remain unaffeccted by adding the new edge 
                sum += dis[i][j];
            }
        }
        cout << sum/2 << " ";
    }
    cout << endl;
}