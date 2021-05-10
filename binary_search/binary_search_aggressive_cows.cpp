#include<bits/stdc++.h>
using namespace std;
 
// returns the number of cows (cnt) that can be placed, given the minimum seperation (sep)
int placeCows(vector<int> &pos, int sep) {
    int prev = pos[0], cnt = 1; // first cow placed at 1st pos
    for(int i=1; i<pos.size(); i++) {
        if(pos[i] - prev >= sep) {
            cnt++;
            prev = pos[i];
        }
    }
    return cnt;
}

// returns max seperation possible b/w cows
void maxSepCows() {
    int n, c;
    cin >> n >> c;
    vector<int> pos(n, 0);
    for(auto &val: pos) {
        cin >> val;
    }
    sort(pos.begin(), pos.end());
    int low = 0, high = pos[n-1] - pos[0], ans = 0;

    while(low <= high) {
        int sep = low + (high - low)/2;
        int cnt = placeCows(pos, sep);
        if(cnt >= c) {
            ans = max(ans, sep);
            low = sep + 1;
        } else {
            high = sep - 1;
        }
    }
    cout << ans << "\n";
}

/*
	similar problem 
	there are houses on the x-axis (-1e9, 1e9)
	place m poilice stations such that the max distance of any house to police station is minimized 
*/
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