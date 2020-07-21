#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals) {
      if(intervals.size() == 0) {
            return {};
      }

      int n = intervals.size();
      vector<pair<int, char>> points;
      for(auto i: intervals) {
            points.push_back({i[0], 'b'});
            points.push_back({i[1], 'e'});
      }
      sort(points.begin(), points.end());

      int cnt = 0;
      vector<vector<int>> ans;
      int start;

      for(auto &p: points) {
            if(cnt == 0) {
                  start = p.first;
            }
            cnt += (p.second == 'b')? 1: -1;
            if(cnt == 0) {
                  ans.push_back({start, p.first});
            }
      }
      return ans;
}

int main()
{
}