#include<bits/stdc++.h>
using namespace std;

#define int long long int 

template <typename T>
void print(vector<T> v)
{
    for(auto x: v)
        cout << x << " ";
    cout << endl;
}

signed main()
{
	int n;
	cin >> n;
	int mx = -1, j = 0;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
		if(v[i] > mx)
		{
			mx = v[i];
			j = i;
		}
	}
	
	set<pair<int, int>> s;

	for(int i = 0;  i < n; i++)
	{
		if(i != j)
			s.insert(make_pair(mx&v[i], v[i]));
	}
	cout << mx << " ";
	for(auto &x: s)
	{
		cout << x.second << " ";
	}
	cout << endl;
}