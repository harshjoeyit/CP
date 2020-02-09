#include<bits/stdc++.h>
using namespace std;

string s[1000];
//int vis[1000][1000];
int n, m, k, di, dj, si, sj;
bool flag = false;
string path = "";
string ans = "";

bool invalid(int i, int j)
{
    if(i < 0 || i >= n || j < 0 || j >= m || s[i][j] != '.')
        return true;
    return false;
}

void dfs(int i, int j, int steps)
{
    if(invalid(i, j) || flag)
        return;

    //cout << i << ", " << j << endl;

    if(i == di && j == dj)
    {
        if(steps == k)
        {
            //cout << "steps: " << steps << endl;
            flag = true;
            ans = path;
        }
    }             

    if(steps < k)
    {
        path.push_back('D');
        dfs(i+1, j, steps + 1);    // D
        path.pop_back();
        path.push_back('L');
        dfs(i, j-1, steps + 1);    // L
        path.pop_back();
        path.push_back('R');
        dfs(i, j+1, steps + 1);    // R
        path.pop_back();
        path.push_back('U');
        dfs(i-1, j, steps + 1);    // U
        path.pop_back();
    }

}

int main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
        for(int j = 0; j < m; j++)
        {
            if(s[i][j] == 'X')
            {
                s[i][j] = '.';
                si = i;
                sj = j;
            }
        }
    }
    
    di = si;
    dj = sj;

    //cout << di << " " << dj << endl;

    dfs(si, sj, 0);
    if(flag)
    {
        cout << ans << endl;
        //cout << "found" << endl;
    }
    else
        cout << "IMPOSSIBLE" << endl;
}