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
    
    ll n, m, a, b, c;
	cin >> n >> m;

	vector<ll> v(n+1);

	for(ll i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		v[a] = v[a] - c;
		v[b] = v[b] + c;
	}

	vector<pair<pll, ll>> ans;

	ll j = 1;
	for(ll i=1; i<=n; i++)
	{				// i is for lender
		while(v[i]>0)
		{
			while(v[j]>=0&&j<=n)
				j++;		// j is for borrower
			ll Min = min(v[i],-v[j]);
			v[i] -= Min;
			v[j] += Min;
			ans.push_back(mp(mp(j,i),Min));
		}
	}

	cout << ans.size() << endl;
	for(auto &t: ans)
		cout << t.F.F << " " <<t.F.S << " " << t.S << endl;

}