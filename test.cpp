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

		int i = 0, x;
		for(; i < n; i++)
		{
			cin >> x;
			if(p % x != 0)
			{
				flag = false;;
				break;
			}
		}
		
		if(flag)
		{
			cout << "NO" << endl;
			continue;
		} 
		else
		{
			long double ld = (long double)p;
			int f = ceil(ld/x);
			//cout << ld << " " << f << " "<< x << endl;
			cout << "YES ";
			for(int j = 0; j < n; j++)
				if(j == i)
					cout << f << " ";
				else
					cout << 0 << " ";
			cout << endl;
		}
		
	}
}