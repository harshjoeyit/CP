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

    
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;

    while(T--)
    {
        int n, m;
		cin >> n >> m;

		string s[n];
		vector<pii> src;
        int gates[n][m];
        pii path[n][m];


		for(int i = 0; i < n; i++)
		{
			cin >> s[i];
			for(int j = 0; j < m; j++)
			{
				if(s[i][j] == '$')
					src.pb(mp(i, j));
                gates[i][j] = MOD;
			}
		}

        // for(auto x: src)
        //     cout << x.F << " "<< x.S << endl;
		
	    deque<pii> dq;
	    dq.push_back(mp(src[0].F, src[0].S));
        gates[src[0].F][src[0].S] = 0;
        int i, j;

        while(! dq.empty())
        {
            pii temp = dq.front();
            i = temp.first;
            j = temp.second;
            dq.pop_front();
            
            if(i == 0 || j == 0 || i == n-1 || j == m-1)            
                break;

            if(s[i-1][j] != '*')
            {
                if(s[i-1][j] == '#' && (gates[i-1][j] > gates[i][j] + 1))
                {
                    gates[i-1][j] = gates[i][j] + 1;
                    dq.push_back(mp(i-1, j));
                    path[i-1][j] = mp(i, j);
                }
                else if(s[i-1][j] == '.' && gates[i-1][j] > gates[i][j])
                {
                    dq.push_front(mp(i-1, j));
                    gates[i-1][j] = gates[i][j];
                    path[i-1][j] = mp(i, j);
                }
            }

            if(s[i+1][j] != '*')
            {
                if(s[i+1][j] == '#' && (gates[i+1][j] > gates[i][j] + 1))
                {
                    gates[i+1][j] = gates[i][j] + 1;
                    dq.push_back(mp(i+1, j));
                    path[i+1][j] = mp(i, j);
                }
                else if(s[i+1][j] == '.' && gates[i+1][j] > gates[i][j])
                {
                    dq.push_front(mp(i+1, j));
                    gates[i+1][j] = gates[i][j];
                    path[i+1][j] = mp(i, j);
                }
            }

            if(s[i][j-1] != '*')
            {
                if(s[i][j-1] == '#' && (gates[i][j-1] > gates[i][j] + 1))
                {
                    gates[i][j-1] = gates[i][j] + 1;
                    dq.push_back(mp(i, j-1));
                    path[i][j-1] = mp(i, j);
                }
                else if(s[i][j-1] == '.' &&gates[i][j-1] > gates[i][j])
                {
                    dq.push_front(mp(i, j-1));
                    gates[i][j-1] = gates[i][j];
                    path[i][j-1] = mp(i, j);
                }
            }

            if(s[i][j+1] != '*')
            {
                if(s[i][j+1] == '#' && (gates[i][j+1] > gates[i][j] + 1))
                {
                    gates[i][j+1] = gates[i][j] + 1;
                    dq.push_back(mp(i, j+1));
                    path[i][j+1] = mp(i, j);
                }
                else if(s[i][j+1] == '.' && gates[i][j+1] > gates[i][j])
                {
                    dq.push_front(mp(i, j+1));
                    gates[i][j+1] = gates[i][j];
                    path[i][j+1] = mp(i, j);
                }
            }

        }

        // for(int i = 0; i < n; i++)
        // {
        //     for(int j = 0; j < m; j++)
        //         cout << path[i][j].F << path[i][j].S<< " ";
        //     cout << endl;
        // }

        int gate_coutner = 0;
        while(!((i == src[0].F) && (j == src[0].S)))
        {
            if(s[i][j] == '#')
            {   
                s[i][j] = '.';
                ++gate_coutner;
            }
            int I = path[i][j].F;
            int J = path[i][j].S;
            i = I;
            j = J;
        }



//..................................................................

        while(! dq.empty())
            dq.pop_back();

	    dq.push_back(mp(src[1].F, src[1].S));
        gates[src[1].F][src[1].S] = 0;

        while(! dq.empty())
        {
            pii temp = dq.front();
            i = temp.first;
            j = temp.second;
            dq.pop_front();
            
            if(i == 0 || j == 0 || i == n-1 || j == m-1)            
                break;

            if(s[i-1][j] != '*')
            {
                if(s[i-1][j] == '#' && (gates[i-1][j] > gates[i][j] + 1))
                {
                    gates[i-1][j] = gates[i][j] + 1;
                    dq.push_back(mp(i-1, j));
                    path[i-1][j] = mp(i, j);
                }
                else if(s[i-1][j] == '.' && gates[i-1][j] > gates[i][j])
                {
                    dq.push_front(mp(i-1, j));
                    gates[i-1][j] = gates[i][j];
                    path[i-1][j] = mp(i, j);
                }
            }

            if(s[i+1][j] != '*')
            {
                if(s[i+1][j] == '#' && (gates[i+1][j] > gates[i][j] + 1))
                {
                    gates[i+1][j] = gates[i][j] + 1;
                    dq.push_back(mp(i+1, j));
                    path[i+1][j] = mp(i, j);
                }
                else if(s[i+1][j] == '.' && gates[i+1][j] > gates[i][j])
                {
                    dq.push_front(mp(i+1, j));
                    gates[i+1][j] = gates[i][j];
                    path[i+1][j] = mp(i, j);
                }
            }

            if(s[i][j-1] != '*')
            {
                if(s[i][j-1] == '#' && (gates[i][j-1] > gates[i][j] + 1))
                {
                    gates[i][j-1] = gates[i][j] + 1;
                    dq.push_back(mp(i, j-1));
                     path[i][j-1] = mp(i, j);
                }
                else if(s[i][j-1] == '.' &&gates[i][j-1] > gates[i][j])
                {
                    dq.push_front(mp(i, j-1));
                    gates[i][j-1] = gates[i][j];
                     path[i][j-1] = mp(i, j);
                }
            }

            if(s[i][j+1] != '*')
            {
                if(s[i][j+1] == '#' && (gates[i][j+1] > gates[i][j] + 1))
                {
                    gates[i][j+1] = gates[i][j] + 1;
                    dq.push_back(mp(i, j+1));
                    path[i][j+1] = mp(i, j);
                }
                else if(s[i][j+1] == '.' && gates[i][j+1] > gates[i][j])
                {
                    dq.push_front(mp(i, j+1));
                    gates[i][j+1] = gates[i][j];
                    path[i][j+1] = mp(i, j);
                }
            }

        }

        // for(int i = 0; i < n; i++)
        // {
        //     for(int j = 0; j < m; j++)
        //         cout << path[i][j].F << "-" << path[i][j].S << " ";
        //     cout << endl;
        // }

        while(!((i == src[1].F) && (j == src[1].S)))
        {
            if(s[i][j] == '#')
                {   
                    s[i][j] = '.';
                    ++gate_coutner;
                }

            int I = path[i][j].F;
            int J = path[i][j].S;
            i = I;
            j = J;
        }

         cout << gate_coutner << endl;
    }    
}