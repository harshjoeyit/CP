
/*
https://www.codechef.com/COOK119B/problems/CHKPTS

moving points on a line
takeaway
example - n friends have house on number line given by pos[i]
            they want to gather at one of the friends' house and party
            IMP: condition is that the total distance travelled by all should be MINIMUM
            >> sort all the positions 
            >> choose the median pos for party pos[n/2]
            >> if n = even any would work either pos[n/2] or pos[n/2-1]
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {
      int n, c;
      cin >> n >> c;
      map<pair<int, int>, vector<pair<int, int>>> mp;

      int x, y, slope, mod;
      for(int i=0; i<n; i++) {
            cin >> x >> y;
            slope = x - y;        
            mod = (x % c + c) % c;
            // grouping by slope and jump distance c
            // points that are on the same line are grouped together(slope)
            // on the same line - one point can only reach at poition of another point if 
            // x1 % c == x2 % c, only
            // so group them by jump distance
            mp[make_pair(slope, mod)].emplace_back(x, y);
      }     

      int steps = 0;
      // checkpoints = mp.size()
      for(auto &p: mp) {
            auto &grp = p.second;
            // sort each group 
            // since we choose median of the group 
            // choosing median minimizes total steps taken by all other points 
            // to reach the chosen(median) point
            sort(grp.begin(), grp.end());
            int sz = grp.size();
            // median chosen
            auto selected = grp[sz/2];
            
            // find setps from each point in the group to this point
            for(auto &point: grp) {
                  steps += abs(selected.first - point.first) / c;
            } 
      }
      cout << mp.size() << " " << steps << endl;
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      int t;
      cin >> t;
      while(t--)
      solve();
}