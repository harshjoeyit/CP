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



// problem link 

// https://www.spoj.com/problems/KATHTHI/




bool valid(int i, int j, int r, int c, string Map[])
{
    if(i >= 0 && j >= 0 && i < r && j < c)
        return true;
    return false;
}

    
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while(t--)
    {
        int r, c;
        cin >> r >> c;

        string Map[r];
        int kills[r][c];

        for(int i = 0; i < r; i++)
        {
            cin >> Map[i];
            for(int j = 0; j < c; j++)
                kills[i][j] = MOD;
        }

        deque<pii> dq;
        kills[0][0] = 0;
        dq.push_back(mp(0, 0));

        while(! dq.empty())
        {
            int i = dq.front().F, j = dq.front().S;
            dq.pop_front();

            //cout << i << "," << j << endl;

            if(i == r-1 && j == c-1)
                break;

            if(valid(i-1, j, r, c, Map))
            {
                if(Map[i-1][j] != Map[i][j] && (kills[i-1][j] > kills[i][j] + 1))
                {
                    dq.push_back(mp(i-1, j));
                    kills[i-1][j] = kills[i][j] + 1;
                }
                else if(Map[i-1][j] == Map[i][j] && (kills[i-1][j] > kills[i][j]))
                {
                    dq.push_front(mp(i-1, j));
                    kills[i-1][j] = kills[i][j];
                }
            }

            if(valid(i+1, j, r, c, Map))
            {
                if(Map[i+1][j] != Map[i][j] && (kills[i+1][j] > kills[i][j] + 1))
                {
                    dq.push_back(mp(i+1, j));
                    kills[i+1][j] = kills[i][j] + 1;
                }
                else if(Map[i+1][j] == Map[i][j] && (kills[i+1][j] > kills[i][j]))
                {
                    dq.push_front(mp(i+1, j));
                    kills[i+1][j] = kills[i][j];
                }
            }

            if(valid(i, j-1, r, c, Map))
            {
                if(Map[i][j-1] != Map[i][j] && (kills[i][j-1] > kills[i][j] + 1))
                {
                    dq.push_back(mp(i, j-1));
                    kills[i][j-1] = kills[i][j] + 1;
                }
                else if(Map[i][j-1] == Map[i][j] && (kills[i][j-1] > kills[i][j]))
                {
                    dq.push_front(mp(i, j-1));
                    kills[i][j-1] = kills[i][j];
                }
            }

            if(valid(i, j+1, r, c, Map))
            {
                if(Map[i][j+1] != Map[i][j] && (kills[i][j+1] > kills[i][j] + 1))
                {
                    dq.push_back(mp(i, j+1));
                    kills[i][j+1] = kills[i][j] + 1;
                }
                else if(Map[i][j+1] == Map[i][j] && (kills[i][j+1] > kills[i][j]))
                {
                    dq.push_front(mp(i, j+1));
                    kills[i][j+1] = kills[i][j];
                }
            }
        }

        cout << kills[r-1][c-1] << endl;
    }

}