#include<bits/stdc++.h>
using namespace std;

/*
    finding quadruples such that 
    a + b + c = d;
    idx(x) - index of x
    idx(a) < idx(b) < idx(c) < idx(d) 
*/

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


/*    
      Find quadruuple sum = target
      find a + b + c + d = target
      return a, b, c, d - uniq pairs 
*/

// Method 1.O(n^3 log(n))
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



// Method 2. O(n^3)  
vector<vector<int> > fourSum(vector<int> &a, int k) {
    sort(a.begin(), a.end());
    int n = a.size();
    vector<vector<int>> ans;

    for(int i=0; i<=n-4; i++) {
        // skip similar values
        if(i != 0 && a[i] == a[i-1]) {
            continue;
        }
        for(int j=i+1; j<=n-3; j++) {
            // skip similar values
            if(j != i+1 && a[j] == a[j-1]) {
                continue;
            }
            int l = j+1, r = n-1;
            int remK = k - a[i] - a[j];
            
            while(l < r) {
                int s = a[l] + a[r];
                if(s == remK) {
                    ans.push_back({a[i], a[j], a[l], a[r]});
                    int saveP = a[l], saveQ = a[r];
                    // skip similar values
                    while(l < r && a[l] == saveP)    l++;
                    while(l < r && a[r] == saveQ)    r--;
                } 
                else if(s > remK){
                    r--; 
                } else {
                    l++;
                }
            }
        }
    }
    return ans;
}



// i, j, k, l should all be unique
bool noCommon(int i, int j, int k, int l) {
    if(i == k || i == l || j == k || j == l) {
        return false;
    }
    return true;
}

// Method 3. O(n^2.log(n))
// Only finds if exists a quadruple, cannot find ALL
void fourSum(vector<int> &a, int target) {
    int n = a.size();
    vector<vector<int>> pairSum;
    // a[i] + a[j], i, j

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            pairSum.push_back({a[i] + a[j], i, j});
        }
    }

    sort(pairSum.begin(), pairSum.end());
    int i=0, j=pairSum.size()-1;

    while(i < j) {
        auto p1 = pairSum[i], p2 = pairSum[j];
        int s = p1[0] + p2[0];
        int i = p1[1], j = p1[2], k = p2[1], l = p2[2];
        
        if(s == target && noCommon(i, j, k, l)) {
            cout << a[i] << " " << a[j] << " " << a[k] << " " << a[l] << endl;
            return;
        } else if(s < target) {
            i++;
        } else {
            j++;
        }
    }
}

// Method 4. O(n^2) Hashing
void fourSum(vector<int> &a, int target) {
    int n = a.size();
    unordered_map<int, pair<int, int>> pairSum;
    // a[i] + a[j], i, j

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            pairSum[a[i] + a[j]] = {i, j};
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            int s = target - (a[i] + a[j]);

            if(pairSum.count(s)) {
                auto pr = pairSum[s];
                int k = pr.first, l = pr.second;
                if(noCommon(i, j, k, l)) {
                    cout << a[i] << " " << a[j] << " " << a[pr.first] << " " << a[pr.second] << endl;
                }
            }
        }
    }
}


int main {
}