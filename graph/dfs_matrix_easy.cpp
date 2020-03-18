#include<bits/stdc++.h>
using namespace std;

string s[1000];
int vis[1000][1000];
int n, m, di, dj;
bool flag = false;

bool invalid(int i, int j)
{
    if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || s[i][j] != '.')
        return true;
    return false;
}

void dfs(int i, int j)
{
    if(invalid(i, j) || flag)
        return;
 
    cout << i << ", " << j << endl;

    if(i == di && j == dj)
    {
        flag = true;
        return;
    }

    vis[i][j] = 1;

    dfs(i+1, j);    // D
    dfs(i, j-1);    // L
    dfs(i, j+1);    // R
    dfs(i-1, j);    // U
}

int main()
{
    int si, sj;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
        for(int j = 0; j < m; j++)
        {
            if(s[i][j] == 's')
            {
                s[i][j] = '.';
                si = i;
                sj = j;
            }
            if(s[i][j] == 'd')
            {
                s[i][j] = '.';
                di = i;
                dj = j;
            }
        }
    }

    cout << si << sj << di << dj << endl;
    dfs(si, sj);
}