
/*
      nums[i] = max size forward jump person can take if he is at a[i]
*/

#include<bits/stdc++.h>
using namespace std;

// dp solution works in O(n * max element)

// greedy 
int jump(vector<int> &nums) {
     int pos = 0, dest = 0, jump = 0;

     for(int i=0; i<nums.size()-1; i++) {
           // untill we reach the pos, find the farthest destination possible,
           // well jump to it
           dest = max(dest, i + nums[i]);
           if(pos == i) {
                 pos = dest;
                 jump++;
            }
     }
     return jump;
}


// Similar problem 
// convert the intervals to jumps and solve like above 


/*
Given intervals [l, r] such that 
l <= r and 0 <= l, r <= n
Find min intervals such that region [0, n] is covered 
*/

// O(nlog(n))
int minIntervals(int n, vector<pair<int, int>> interval) {

      auto comp = [](const pair<int, int> &a, const pair<int, int> &b) {
            if(a.first == b.first) {
                // if start point same. the one with larger endpoint comes first
                return a.second > b.second;
            }  
            // otherwise one with lesser start point comes first
            return a.first < b.first;
      };
      
      sort(interval.begin(), interval.end(), comp);
      
      int prevEnd = 0;              // previous interval ends at 
      int maxEnd = 0;   
      int cnt = 0, i = 0;           // total intervals 
      
      while(i<n && prevEnd < n) {
            // among all the intervals that have start point <= previous end point  
            // find the farthest end point possible
            while(i < n && interval[i].first <= prevEnd) {
                maxEnd = max(maxEnd, interval[i].second);
                i += 1;
            }
            // if no interval with start point <= previous end point found
            if(maxEnd == prevEnd) {
                return -1;
            }
            // count one interval 
            cnt += 1;
            // update the previous end point to max possible
            prevEnd = maxEnd;   
      }
      return cnt;
}


// in O(n)
// convert intervals to jumps 

int minTaps(int n, vector<int>& ranges) {
    vector<int> jumps(n+1, 0);

    for(int i=0; i<=n; i++) {
        int l = max(0, i - ranges[i]);
        int r = min(n, i + ranges[i]);
        // maximize the jump from l, since many intervals may start at l, 
        // we take the largest jump, jumplen = r - l 
        jumps[l] = r - l;
    }
    
    int pos = 0, dest = 0, jump = 0;
    
    for(int i=0; i<jumps.size() - 1; i++) {
        if(i > dest) {
            return -1;
        }
        dest = max(dest, i + jumps[i]);
        if(i == pos) {
            pos = dest;
            jump += 1;
        }
    }
    return jump;
}