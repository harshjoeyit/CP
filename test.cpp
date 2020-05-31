/*
weighted job scheduling
*/

#include<bits/stdc++.h>
using namespace std;

struct job {
      int st, en, profit;
};

bool comp(job &a, job &b) {
      return (a.en < b.en);
}

const int mxN = 1000;
job jobs[mxN];
int n;

int binary_search(int index) {
      int l=0, h=index-1;
      while(l <= h) {
            int mid = (l+h)/2;
            if(jobs[mid].en <= jobs[index].st) {
                  // there could be multiple jobs ending at same time, 
                  if(jobs[mid+1].en <= jobs[index].st) {
                        l = mid+1;
                  } else {
                        return mid;
                  }
            } else {
                  h = mid-1;
            }
      }
      return -1;
}

int go() {
      int dp[n];
      memset(dp, 0, sizeof(dp));
      dp[0] = jobs[0].profit;

      for(int i=1; i<n; i++) {
            int x = jobs[i].profit;
            int l =  binary_search(i);
            if(l == -1) {
                  x += dp[i];
            }
            dp[i] = max(x, dp[i-1]);
      }     

      return dp[n-1];
}

int main() {      
      cin >> n;
      for(int i=0; i<n; i++) {
            cin >> jobs[i].st >> jobs[i].en >> jobs[i].profit;
      }
      sort(jobs, jobs+n, comp);

      cout << go() << endl;
}