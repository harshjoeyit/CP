#include<bits/stdc++.h>
using namespace std;

#define ll                    long long int
#define ld                    long double
#define mid(s,e)              (s+(e-s)/2)
#define MOD                   1000000007
#define F                     first
#define S                     second
#define mp                    make_pair
#define pb                    push_back
#define eb                    emplace_back
#define itoc(c)               ((char)(((int)'0')+c))
#define vi                    vector<int>
#define pll                   pair<ll,ll>
#define pii                   pair<int,int>


bool valid1(int i, int j, string a[], int r, int c, bool vis[][1002])
{
    if(i >= 0 && i < r && j >= 0 && j < c && vis[i][j] == 0 && a[i][j] != 'T')
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int r, c, di, dj;
    cin >> r >> c;

    string a[r];
    bool vis[1002][1002];
    int distance[1002][1002];

    for(int i = 0; i < r; i++)
    {
        cin >> a[i];
        for(int j = 0; j < c; j++)
        {
            if(a[i][j] == 'E')
            {
                di = i;
                dj = j;
            }
            vis[i][j] = 0;
            distance[i][j] = 0;
        }
    }

    // cout << si << sj;
    queue<pii> q;
    int i, j;

    q.push(mp(di, dj));
    q.push(mp(-1, -1));
    vis[di][dj] = 1;
    distance[di][dj] = 0;

    while(! q.empty())
    {
        i = q.front().F;
        j = q.front().S;
        q.pop();

        //cout << i << " " << j << endl;

        if(i == -1 && j == -1)
        {
            if(! q.empty())
                q.push(mp(-1,-1));
            continue;
        }

        if(a[i][j] == 'S')
            break;    

        if(valid1(i-1, j, a, r, c, vis))
        {
            vis[i-1][j] = 1;
            distance[i-1][j] = distance[i][j] + 1;
            q.push(mp(i-1, j));
        }
        if(valid1(i+1, j, a, r, c, vis))
        {
            vis[i+1][j] = 1;
            distance[i+1][j] = distance[i][j] + 1;
            q.push(mp(i+1, j));
        }
        if(valid1(i, j-1, a, r, c, vis))
        {
            vis[i][j-1] = 1;
            distance[i][j-1] = distance[i][j] + 1;
            q.push(mp(i, j-1));
        }
        if(valid1(i, j+1, a, r, c, vis))
        {
            vis[i][j+1] = 1;
            distance[i][j+1] = distance[i][j] + 1;
            q.push(mp(i, j+1));
        }
    }

    //cout << "\ndis : " << distance[i][j] << endl;
    int si = i, sj = j, counter = 0, ch;

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++)
        {
            //cout << distance[i][j] << " ";
            if( vis[i][j] && (distance[i][j] <= distance[si][sj]))
            {
                ch = (int)(a[i][j] - '0'); 
                if(ch >= 0 && ch <= 9)
                {
                    counter += ch;
                    // cout << a[i][j] << " ";
                }
            }
        }
        //cout << endl;
    }
    // cout << endl;
    cout << counter << endl;
}