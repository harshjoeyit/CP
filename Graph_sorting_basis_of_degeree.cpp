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
        int n, m, x, y;
        cin >> n >> m;

        vi G[n+1];
        vector<bool> vis(n+1);
        vis.assign(n+1, false);
        multimap<int, int> mp;
        vi ans;

        for(int i = 0; i < m; i++)
        {
            cin >> x >> y;
            G[x].pb(y);
            G[y].pb(x);
        }

        for(int i=1;i<=n;i++)
        {
				mp.insert({G[i].size(),i });
		}

		for(auto it = mp.rbegin(); it != mp.rend(); it++)
        {
			if(vis[it->second]==false)
            {
				ans.push_back(it->second);
				vis[it->second] = true;
	    		
                for(auto move: G[it->second])
		    		vis[move] = true;
		    }
		}

        if(ans.size() <= n/2)
        {
            cout <<  ans.size() << endl;
            for(int &v: ans)
                cout << v << " ";
            cout << endl;
        }

        else
        {
            set<int> s;
            for(int &v: ans)
                s.insert(v);
        
            cout << n - ans.size() << endl;
            for(int i = 1; i <= n; i++)
            {
				if(s.find(i) == s.end())
					cout<<i<<" ";
			}
        }
    }
}
