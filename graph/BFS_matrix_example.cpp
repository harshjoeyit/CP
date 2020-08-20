#include<bits/stdc++.h>
using namespace std;

#define M 100
#define N 100

vector<vector<int>> mat;
vector<vector<int>> vis;
vector<vector<int>> dis;
queue<pair<int, int>> q;

bool valid(int i, int j, int n, int m)
{
    return ( i < n && j < m && i >= 0 && j >= 0 && mat[i][j] == 1);
}

void Push(int i, int j, int x, int y)
{
    dis[i+x][j+y] = dis[i][j] + 1;
    vis[i+x][j+y] = 1;
    q.push(make_pair(i+x, j+y));
}

int main()
{
    mat.assign(N, vector<int>(M));
    vis.assign(N, vector<int>(M));
    dis.assign(N, vector<int>(M));

    cout << "n, m: ";
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cin >> mat[i][j];
    }

    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < m; j++)
    //         cout << mat[i][j] << " ";
    //     cout << endl;
    // }

    int si, sj;
    cout << "si , sj: ";
    cin >> si >> sj;
    int di , dj;
    cout << "di , dj: ";
    cin >> di >> dj;

    q.push(make_pair(si, sj));
    vis[si][sj] = 1;
    bool flag = 0;

    while(!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();
        int i = temp.first, j = temp.second;

        //cout << i << ", " << j << endl;

        if(i == di && j == dj)
        {
            flag = 1;
            break;
        }

        if(valid(i-1, j, n, m) && vis[i-1][j] != 1)
        {
            Push(i, j, -1, 0);
        }

        if(valid(i+1, j, n, m) && vis[i+1][j] != 1)
        {
            Push(i, j, 1, 0);
        }

        if(valid(i, j-1, n, m) && vis[i][j-1] != 1)
        {
            Push(i, j, 0, -1);
        }

        if(valid(i, j+1, n, m) && vis[i][j+1] != 1)
        {
            Push(i, j, 0, 1);
        }
    }
    if(flag)
        cout << dis[di][dj] << endl;
    else
        cout << "INF" << endl;
}