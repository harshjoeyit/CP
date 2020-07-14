
/*
    finding quadruples such that 
    a + b + c = d;
    idx(x) - index of x
    idx(a) < idx(b) < idx(c) < idx(d) 
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long

void fourSum(vector<int> &a, int target) {
    map<int, vector<int>> mp;
    int n = a.size();
    // sort(a.begin(), a.end());
      
    // a + b + c = d or
    // a + b = d - c
    // we find pairs of (a + b)  - where idx(a) < idx(b)
    
    for(int i=0; i<n; i++)                      
        for(int j=0; j<i; j++) 
            // a = a[j], b = a[i]
            // vector stores index of b, since when we find c we need index of b
            mp[ a[i]+a[j] ].push_back(i);         
    
    int ans = 0;

    // finding (d-c) pairs
    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            // d = a[i], c = a[j]
            int val = a[i] - a[j], cnt;           
            if(mp.count(val) > 0) {
                // we find largest index of c such that idx(c) < idx(d)
                // all the lower indices will be in cnt, there are cnt pair with a+b = d-c for current val
                cnt = lower_bound(mp[val].begin(), mp[val].end(), j) - mp[val].begin();         
                ans += cnt;
            }                                                                                   
        }
    }
    
    cout << ans << "\n";
}


// similar problem - 
// find a + b + c + d = target
// return a, b, c, d - uniq pairs 
vector<vector<int>> fourSum(vector<int> &a, int target) {
      int n = a.size();
      if(n < 4) {
            return {};
      }
      
      map<int, vector<int>> mp;
      map<int, vector<pair<int, int>>> index;
      vector<vector<int>> ans;
      set<vector<int>> uniq;

      for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                  int s = a[i] + a[j];
                  mp[s].push_back(i);
                  index[s].push_back({j, i});
            }
      }

      for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                  int s = target - (a[i] + a[j]);
                  if(mp.count(s) > 0) {
                        int cnt = lower_bound(mp[s].begin(), mp[s].end(), j) - mp[s].begin();
                        
                        // quadruple found
                        for(int k=0; k<cnt; k++) {
                              vector<int> temp;
                              temp.push_back(a[index[s][k].first]);
                              temp.push_back(a[index[s][k].second]);
                              temp.push_back(a[j]);
                              temp.push_back(a[i]);
                              
                              sort(temp.begin(), temp.end());
                              if(uniq.count(temp) == 0)
                                    ans.push_back(temp);
                              uniq.insert(temp);
                        }
                  }
            }
      }

      return ans;
}


/*
faster approach for above question read 

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
      vector<vector<int>> res;

      if (nums.size() < 4)
            return res;

      sort(nums.begin(), nums.end());

      for (int i = 0; i < nums.size(); ++i)
      {

            if (i > 0 && nums[i] == nums[i - 1])
                  continue;

            for (int j = i + 1; j < nums.size(); ++j)
            {
                  if (j > i + 1 && nums[j] == nums[j - 1])
                        continue;

                  int sum = target - (nums[i] + nums[j]);

                  int left = j + 1;
                  int right = nums.size() - 1;

                  while (left < right)
                  {

                        int tsum = nums[left] + nums[right];

                        if (sum == tsum)
                        {

                              res.push_back({nums[i], nums[j], nums[left], nums[right]});

                              while (left < right && nums[left] == nums[left + 1])
                                    ++left;

                              while (left < right && nums[right] == nums[right - 1])
                                    --right;

                              ++left;
                              --right;
                        }

                        else if (sum > tsum)
                        {
                              ++left;
                        }
                        else
                        {
                              --right;
                        }
                  }
            }
      }

      return res;
}

*/




signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, target;
    cin >> n >> target;
    vector<int>v(n);
    for(int i=0; i<n; i++) {
          cin >> v[i];
    }
    fourSum(v, target);
}



