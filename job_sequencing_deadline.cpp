

#include<bits/stdc++.h>
using namespace std;

struct job { 
    int id, dead, prof;
    bool operator < (const job &rhs) const {
        return prof > rhs.prof;
      }
};
int n;


// Using Greedy O(n*n)
void jobSequencing(vector<job> &jobs) {
      vector<bool> slot(n, false);
      vector<int> result(n);
      int profit = 0, cnt = 0;

      for (int i = 0; i < n; i++) {
            // find slot, closest to deadline, i.e greatest slot < deadline 
            for (int j = min(n, jobs[i].dead) - 1; j >= 0; j--) {
                  if(slot[j] == false) {
                        // found a slot, this job can be done in [j, j+1] slot
                        slot[j] = true;
                        result[j] = i;
                        // if only profit or number of jobs is required, we can calculate it here.
                        // cnt++, profit += jobs[i].prof;
                        break;
                  }
            }
      }

      // result array is only useful when the order of jobs is asked
      for (int i = 0; i < n; i++) {
            if(slot[i]) {
                  // filled slot
                  // cout << jobs[result[i]].id << endl;
                  profit += jobs[result[i]].prof;
                  cnt += 1;
            }
      }
      cout << cnt << " " << profit << endl;
}


// Using disjoint set 
// the costly operation of finding the greatest free slot < deadline 
// is made faster using findSet, path compression

vector<int> parent;
void makeSet(int n) {
      parent.assign(n + 1, 0);
      for (int i = 1; i <= n; i++) {
            parent[i] = i;
      }
}
int findSet(int a) {
      if(a == parent[a]) {
            return a;
      }
      return parent[a] = findSet(parent[a]);
}

void jobSequencingDSU(vector<job> &jobs) {
      // max deadline
      int mxDead = 0;
      for(auto j: jobs) {
            mxDead = max(mxDead, j.dead);
      }
      makeSet(mxDead);

      int cnt = 0, profit = 0;

      for (int i = 0; i < n; i++) {
            // find available slot
            int slot = findSet(jobs[i].dead);
            if (slot > 0) {
                  // slot available, union
                  parent[slot] = slot - 1;
                  // slot - 1, becomes parent = slot
                  cnt += 1;
                  profit += jobs[i].prof;
            }
      }
      cout << cnt << " " << profit << endl;
}

int main() {
      cin >> n;
      vector<job> jobs(n);
      for(auto &j: jobs) {
            cin >> j.id >> j.dead >> j.prof;
      }
      sort(jobs.begin(), jobs.end());
      
      // jobSequencing(jobs);
      jobSequencingDSU(jobs);
}