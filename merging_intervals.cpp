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

// Another approach 
void merge() {
      int n;
	cin >> n;
      vector<pair<int, int>> ranges, ans;

	for (int i = 0; i < n; i++) {
            int st, en;
            cin >> st >> en;
            ranges.push_back({st, en});
      }

      sort(ranges.begin(), ranges.end());

      int st = ranges[0].first, en = ranges[0].second;

      for (int i = 1; i < n; i++) {
            if(ranges[i].first <= en) {
                  if(ranges[i].second > en) {
                        en = ranges[i].second;
                  }
            } else {
                  ans.push_back({st, en});
                  st = ranges[i].first, en = ranges[i].second;
            }
      }
      ans.push_back({st, en});
}

int main() {
}