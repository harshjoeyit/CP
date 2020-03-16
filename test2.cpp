#include <bits/stdc++.h> 
using namespace std; 

#define int long long int

// void Insert(int i, int j, int k, vector<vector<int>> v, vector<unordered_set<int>> vset)
// {
// 	for(int i = 0; i < k; i++)
// 		vset[ind].insert(v[i][0]);
// }

signed main() 
{ 
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		vector<vector<int>> v; 

		v.assign(k, vector<int>(n));

		for(auto &x: v)
			for(auto &y: x)
				cin >> y;
		
		vector<unordered_set<int>> vset(n);
		int ind = 0; 

		for(int i = 0; i < k; i++)
			vset[0].insert(v[i][0]);

		for(int j = 1; j < n; j++)
		{
			bool e = false;
			for(int i = 0; i < k; i++)
			{
				if(vset[ind].count(v[i][j]) == 1)
					e = true;
			}
			if(e)
			{
				for(int i = 0; i < k; i++)
					vset[ind].insert(v[i][j]);
			}
			else
			{
				ind++;
				for(int i = 0; i < k; i++)
					vset[ind].insert(v[i][j]);
			}
		}
		
		// for(int i = 0; i <= ind; i++)
		// {
		// 	cout << "[";
		// 	for(auto x: vset[i])
		// 		cout << x << " ";
		// 	cout << "], ";
		// }
		// cout << endl;

		vector<int> ans(n+1);

		if(vset.size() > 1)
		{
			for(int i = 0; i < ind; i++)
			{
				auto it1 = vset[i].begin();
				auto it2 = vset[i+1].begin();
				auto en1 = vset[i].end();
				auto en2 = vset[i+1].end();	
				auto it3 = it2;

				for(; it1 != en1 && it2 != en2; it1++, it2++)
				{
					ans[*it1] = *it2;
					it3 = it2;
				}

				for(; it1 != en1; it1++)
					ans[*it1] = *it3;
			}
		}

		cout << vset[0].size() << endl;
		for(int i = 1; i <= n; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
} 
