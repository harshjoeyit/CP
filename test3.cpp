
//  sachin

#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void solve() {
	int n;
	cin >> n;
	int a[n]; 
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
 
	int ans[n] ;
	stack <int> s;
	for(int i = n - 1 ; i >= 0 ; i--) {
		if(!s.empty())
		{
			if(a[i] < a[s.top()])
			{
				ans[i] = a[i] ^ ans[s.top()] ;
			}
			else
			{
				ans[i] = a[i];
				while(!s.empty())
					s.pop();
			}
		}
		else
			ans[i] = a[i];
		s.push(i);
	}
 
	int max_ans = 0;
 
	for(int i = 0 ; i < n ; i++)
	{
		if(max_ans < ans[i])
			max_ans = ans[i];
	}
 
	cout << max_ans <<endl;
 
 
}
signed main() {
 
	solve();
 
}