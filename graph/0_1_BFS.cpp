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
    
	int n, m, x, y, w;
	cin >> n >> m;

	vector<pii> G[n+1];
	vi dis(n+1);
	dis.assign(n+1, INT_MAX);

	for(int i = 0; i < m; i++)
	{
		cin >> x >> y >> w;
		G[x].pb(mp(w, y));
		G[y].pb(mp(w, x));
	}

	deque<int> dq;
	dq.push_back(1);
	dis[1] = 0;

	while(! dq.empty())
	{
		int u = dq.front();
		dq.pop_front();

		for(pii p : G[u])
		{
			int v = p.S;
			int w = p.F;

			if(dis[u] + w < dis[v])
			{
				dis[v] = dis[u] + w;

				if(w == 0)
					dq.push_front(v);
				else
					dq.push_back(v);
			}
		}
	}

	for(int i = 1; i <= n; i++)
		cout << dis[i] << " ";
	cout << endl;
}