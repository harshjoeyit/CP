/*
    GREEDY Activity Selection: Aim is to maximize number of jobs done 
    Similar Problems:
    https://www.geeksforgeeks.org/maximum-trains-stoppage-can-provided/
*/

#include<bits/stdc++.h>
using namespace std;

int activitySelection(vector<vector<int>>& jobs) {
    int n = jobs.size();
    
    // sort based on end time 
    auto comp = [](const vector<int> &a, const vector<int> &b) {
        if(a[1] == b[1]) {              // this may be skipped
            return a[0] < b[0];
        }
        return a[1] < b[1];
    };  
    sort(jobs.begin(), jobs.end(), comp);
    
    int ans = 1, prev = 0;       // previous job done

    for(int i=1; i<n; i++) {
        if(jobs[i][0] > jobs[prev][1]) {
            prev = i;
            ans += 1;
        }
    }
    return ans;
}

int main() {
    
}