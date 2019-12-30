#include<bits/stdc++.h>
using namespace std;

#define int long long int

signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i = 0; i < n; i++)
			cin >> v[i];
		
		unordered_map<int, pair<int, int>> m;

		int sum = 0;
		for(int i = 0; i < n; i++)
		{
			sum += v[i];
			if(!m.count(sum))
				m[sum] = {i, i};
			else
				m[sum].second = i;			// second
		}

		int maxx = 0;
		for(auto it = m.begin(); it != m.end(); it++)
		{
			auto p = *it;
			auto &sf = p.second.first;
			auto &ss = p.second.second;
			if(ss != sf)
			{
				if(ss - sf > maxx)
					maxx = ss - sf;
			}
		}

		m.clear();
		sum = 0;
		for(int i = n-1; i >= 0; i--)
		{
			sum += v[i];
			if(!m.count(sum))
				m[sum] = {i, i};
			else
				m[sum].first = i;			// first
		}

		for(auto it = m.begin(); it != m.end(); it++)
		{
			auto p = *it;
			auto &sf = p.second.first;
			auto &ss = p.second.second;
			if(ss != sf)
			{
				if(ss - sf > maxx)
					maxx = ss - sf;
			}
		}

		if(sum == 0)
			cout << n << endl;				// check for all elements
		else
			cout << maxx << endl;
	}
}

// 15, -2, 2, -8, 1, 7, 10, 23