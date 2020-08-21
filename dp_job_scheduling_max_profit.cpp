
#include <bits/stdc++.h>
using namespace std;

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

int main() {
}