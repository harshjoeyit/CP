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
		
		int l = 0, h = n-1, mid;
		bool flag = false;

		while(l <= h)
		{
			mid = l + (h-l)/2;

			if(v[mid] == mid)
			{
				flag = true;
				break;
			}
			else if(v[mid] > mid)
				h = mid - 1;
			else
				l = mid + 1;
		}
		if(flag)
			cout << "pt-> " << mid << endl;
		else
			cout << "-1" << endl;
	}
}