
#include <bits/stdc++.h>
using namespace std;

// .....................Simple job scheduling .......................
// aim is to maximize number of jobs done 


int findLongestChain(vector<vector<int>>& pairs) {
    int n = pairs.size();
    
    // sort based on end time 
    auto comp = [](const vector<int> &a, const vector<int> &b) {
        if(a[1] == b[1]) {
            return a[0] < b[0];
        }
        return a[1] < b[1];
    };  
    
    sort(pairs.begin(), pairs.end(), comp);
    
    int prev = 0;       // previous job done
    int ans = 1;
    
    for(int i=1; i<n; i++) {
        if(pairs[i][0] > pairs[prev][1]) {
            prev = i;
            ans += 1;
        }
    }
    
    return ans;
}




// .....................................Leetcode Solution in O(nlog(n)).........................................
// Activity selection with profit 

vector<int> dp;
vector<vector<int>> jobs;

int go(vector<int>& startTime, vector<int>& endTime, vector<int>& profit, int i = 0) {
      int n  = (int)startTime.size();
      if(i >= n) {
            return 0;
      }

      if(dp[i] != -1) {
            return dp[i];
      }

      int nextJob = lower_bound(startTime.begin(), startTime.end(), endTime[i]) - startTime.begin();
      // skip this job or take this and go to next job
      // next job is the job that has startTime >= endTime of this job
      return dp[i] = max(go(startTime, endTime, profit, i+1), profit[i] + go(startTime, endTime, profit, nextJob));
}

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
      int n = (int)startTime.size();
      dp.assign(n, -1);
      jobs.assign(n, vector<int>(3, 0));
      
      for(int i=0; i<n; i++) {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
      }
      // sort in the increasing order of start time 
      sort(jobs.begin(), jobs.end());
      for(int i=0; i<n; i++) {
            startTime[i] = jobs[i][0];
            endTime[i] = jobs[i][1];
            profit[i] = jobs[i][2];
      }

      return go(startTime, endTime, profit);        
}

//. ........................................................................................................


// other approaches 

vector<vector<int>> jobs;
int n;

// recursive O(n*n)
// j - index of prev job,
// i - index of curr job
int go(int j, int i) {
    if(i == n) {
        return 0;
    }
    int ans = 0;

    // we can always skip current job
    ans = go(j, i + 1);

    if(j == -1 || jobs[j][1] <= jobs[i][0]) {
        // first job not selected yet 
        // or end time of previous <= start time of current job
        ans = max(ans, jobs[i][2] + go(i, i + 1));
    }
    return ans;
}


// iterative O(n*n)
int goIter() {
    vector<int> dp(n, 0);
    // we can at least do 1 job
    for (int i = 0; i < n; i++) {
        dp[i] = jobs[i][2];
    }
    
    int ans = dp[0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // j - previous job
            // i - current job
            // check end time of previous job and start time of this job
            if(jobs[j][1] <= jobs[i][0]) {
                dp[i] = max(dp[i], dp[j] + jobs[i][2]);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}


int main() {
    cin >> n;

    jobs.assign(n, {0,0,0});
    for(auto &j: jobs) {
        // start, end, value
        cin >> j[0] >> j[1] >> j[2];
    }

    // sort on the basis of end time 
    auto comp = [](const vector<int> &a, const vector<int> &b) {
        if(a[1] == b[1]) {
            return a[0] < b[0];
        }
        return a[1] < b[1];
    };
    sort(jobs.begin(), jobs.end(), comp);

    
    // recursive approach, can be memoized
    cout << go(-1, 0) << "\n";

    // iterative approach
    cout << goIter() << "\n";
}