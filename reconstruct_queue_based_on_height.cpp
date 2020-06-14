
/*
IMP: 
https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3352/
https://www.youtube.com/watch?v=_DtZIPUt8jo
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
      int n = people.size();
      if(n <= 1) {
            return people;
      }
      auto comp = [](const vector<int> &a, const vector<int> &b) {
            if(a[0] == b[0]) {
                  return a[1] < b[1];
            } 
            return a[0] > b[0];
      };
      sort(people.begin(), people.end(), comp);
      // for(auto v: people) {
      //       cout << v[0] << " " << v[1] << endl;
      // }
      // return people;
      stack<vector<int> > s;
      stack<vector<int> > temp;

      for(auto v: people) {
            while(s.size() > v[1]) {
                  temp.push(s.top());
                  s.pop();
            }
            s.push(v);
            while(!temp.empty()) {
                  s.push(temp.top());
                  temp.pop();
            }
      }

      vector<vector<int> > ans;
      while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
      }
      reverse(ans.begin(), ans.end());
      return ans;
}

/*
      There is a nlogn approach using segment/fenwick tree
*/

int main() {
      int n;
      cin >> n;
      vector<vector<int> > v;
      v.assign(n, vector<int>(2));
      for(int i=0; i<n; i++) {
            cin >> v[i][0] >> v[i][1];
      }
      auto ans = reconstructQueue(v);

      for(auto v: ans) {
            cout << v[0] << " " << v[1] << endl;
      }
}