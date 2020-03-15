/*
Vova had a pretty weird sleeping schedule. There are h hours in a day. Vova will sleep exactly n times. The i-th time he will sleep exactly after ai hours from the time he woke up. You can assume that Vova woke up exactly at the beginning of this story (the initial time is 0). Each time Vova sleeps exactly one day (in other words, h hours).

Vova thinks that the i-th sleeping time is good if he starts to sleep between hours l and r inclusive.

Vova can control himself and before the i-th time can choose between two options: go to sleep after ai hours or after ai−1 hours.

Your task is to say the maximum number of good sleeping times Vova can obtain if he acts optimally.
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int

const int N = 2005;
int n, h, l, r;
vector<int> v(N);

int dp[2005][2005];

int good_sleeping_times(int curr_time, int i){
	if(i < n){	
		int t, gt, m1 = 0, m2 = 0;
		t = (curr_time + v[i]-1) % h;
		if(l <= t && t <= r)
			++m1;
		if(dp[t][i+1] != -1)
			m1 += dp[t][i+1];
		else
			m1 += dp[t][i+1] = good_sleeping_times(t, i+1);

		t = (curr_time + v[i]) % h;
		if(l <= t && t <= r)
			++m2;
		if(dp[t][i+1] != -1)
			m2 += dp[t][i+1];
		else
			m2 += dp[t][i+1] = good_sleeping_times(t, i+1);

		return max(m1, m2);
	}
	
	return 0;
}

signed main(){
	cin >> n >> h >> l >> r;

	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	for(int i = 0; i < 2005; i++)
		for(int j = 0; j < 2005; j++)
			dp[i][j] = -1;

	cout << good_sleeping_times(0, 0) << endl;
}