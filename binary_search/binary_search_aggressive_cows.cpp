#include<bits/stdc++.h>
using namespace std;
 
 
int main()
{
	int t;
	cin >> t;
 
	while(t--)
	{
		int n, c, l, h, min_sep, sep, prev, curr, cows;
		cin >> n >> c;
		vector<int> stalls(n);
 
		for(int i = 0; i < n; i++)
			cin >> stalls[i];
 
		sort(stalls.begin(), stalls.end());
 
		l = 0, h = 1000000000;
		while(l <= h)
		{
			sep = l + (h - l)/2;
			prev = stalls[0];
			cows = c - 1;
 
			for(int i = 1; (i < n) && (cows > 0); i++)
			{
				curr = stalls[i];
				if(curr - prev >= sep)
				{
					--cows;
					prev = curr;
				}
			}
 
			if(cows > 0)
				h = sep - 1;
				
			else
			{
				l = sep + 1;
				min_sep = sep;
			}
		}
		cout << min_sep << endl;
	}	
} 

// similar problem 
// there are houses on the x-axis (-1e9, 1e9)
// place m poilice stations such that the max distance of any house to police station is minimized 

void solve() {
      int n, m;
      cin >> n >> m;
      vector<int> houses(n);
      for(int i=0; i<n; i++) {
            cin >> houses[i];
      }

	// if police stations are more of equal to house 
	// we can place 1 police station at each house 
	// max dis is 0 in this case 
      if(m >= n) {
            cout << 0 << "\n";
            return;
      }

      sort(houses.begin(), houses.end());

	// taking a healthy high 
      int low = 0, high = 1e9, ans = 1e9;

      while (low <= high) {
            int sep = low + (high - low)/2;
            // 1st station is placed at this corrdinate 
		// we do this becase we want to cover as many houses 
		// as possible including this house as well
		int prevStn = houses[0] + sep;
		// remainin stations 
            int stn = m - 1, i;

            for(i=1; i<n; i++) {
			// check for the current house if it already in the range
			// of previous police station or not 
                  if(abs(houses[i] - prevStn) <= sep) {
                        continue;
                  }

			// if house not in range of previous police stn.
			// and if stations remain 
                  if(stn > 0) {
				// make a new station just as we did before 
                        prevStn = houses[i] + sep;
                        stn -= 1;
                  } else {
				// else we have no police stations left but houses are left 
                        break;
                  }
            }

            if(i == n) {
			// if all houses covered with this sep 
                  ans = min(ans, sep);
			// reduce sep 
                  high = sep - 1;
            } else {
			// increase sep 
			// not all the houses were covered 
                  low = sep + 1;
            }
      }

      cout << ans << endl;
}