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
	int t;
	cin >> t;
	while(t--)
	{
		int n, p;
		bool flag = true;
		cin >> n >> p;
		vector<int> v(n);

		for(int i = 0; i < n; i++)
			cin >> v[i];

		int i = 0;
		for(; i < n; i++)
		{
			if(p % v[i] != 0)
			{
				flag = false;;
				break;
			}
		}
		
		if(flag)
		{
			sort(v.begin(), v.end());
			int i = 1;
			for(; i < n; i++)
			{
				if((v[i] % v[i-1]) != 0)
				{
					flag = false;
					break;
				}
			}
			
			if(flag)
				cout << "NO" << endl;
			else
			{
				int f1, f2;
				f2 = p/v[i] -1;
				f1 = p - f2*v[i];
				f1 = ceil(((long double)f1)/v[i-1]);

				cout << "YES ";
				for(int j = 0; j < n; j++)
				{
					if(j == i-1)
						cout << f1 << " ";
					else if(j == i)
						cout << f2 << " ";
					else
						cout << 0 << " ";
				}
				cout << endl;
			}
		} 
		else
		{			
			int f = ceil(((long double)p)/v[i]);
			cout << "YES ";
			for(int j = 0; j < n; j++)
			{
				if(i == j)
					cout << f << " ";
				else
					cout << 0 << " ";
			}
			cout << endl;
		}
		
	}
}