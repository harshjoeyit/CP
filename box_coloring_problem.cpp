#include<bits/stdc++.h>
using namespace std;
 

// boxes of m colors with balls are present - choose m boxes all of different colors - with minimum diff between the max and  min no of balls 


typedef long long ll;
typedef pair<int, int> pii;
 
#define F first
#define S second
 
const int MAXN = 1e5 + 10;
 
int n, m, cnt[MAXN], cnt0;
pii a[MAXN];
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int te;	cin >> te;
	
	while (te--)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].F;
			a[i].S = i%m;
		}
		sort(a, a + n);
 
		int ans = 2e9;
		for (int i = 0; i < m; i++) 
			cnt[i] = 0;
		cnt0 = m;
 
		int r = 0;

		for (int l = 0; l < n; l++)						// going at each index, a[l].F is the min value among a chosen combination of m color boxed
		{	
			while (r < n && cnt0 > 0)					// until all distinct color boxes arn't found
			{ 
			    if(cnt[a[r].S] == 0)					// if the color has not been picked
			        cnt0--; 							// colors remaining--
			    
			    cnt[a[r].S]++; 							// counter of total colors in the range 
			    r++;									// traversing 
			}
 
			if (cnt0 == 0)								// all colors found
				ans = min(ans, a[r-1].F - a[l].F);		// update ans

			cnt[a[l].S]--;								// remove the box with the color at l
			cnt0 += cnt[a[l].S] == 0;					// new box is must be found if removing box at l reduces the count of color at l to 0

														// if cnt[i] for all colors m > 0, then simply l increases on for loop, while does not work as cnt0 = 0
														// r remains fixed 
														// combinations are found untill cnt[] of some color goes to 0
														// then again that color box must be found
		}

		cout << ans << "\n";
	}
	return 0;
}
