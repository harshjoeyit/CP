/*
    Combination Sum
    https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1#
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
vector<int> curr;

void go(int i, int sum, vector<int> &a, int target) {
    if(i == a.size()) {
        if(sum == target) {
            ans.push_back(curr);
        }
        return;
    }
    if(sum > target) {
        return;
    }
    // 1. include
    curr.push_back(a[i]);
    go(i, sum + a[i], a, target);
    curr.pop_back();  
    // 2. skip
    go(i+1, sum, a, target);
   /*
    Note this order of recursive call arranges the possible combinations in increasing order 
    a = {1, 1, 2, 3}, target = 4 => {{1, 1, 2}, {1, 3}}
   */
}

// remove duplicates from the array
vector<int> removeDups(vector<int> &a) {
    vector<int> b;
    for(int i=0; i<a.size(); ) {
        b.push_back(a[i]);
        int j = i+1;
        while(j < a.size() && a[i] == a[j]) j++;
        i = j;
    }
    return b;
}

// returns all unique combinations
vector<vector<int> > combinationSum(vector<int> &a, int target) {
    ans.clear();
    // sorting arranges each combination in increasing order 
    sort(a.begin(), a.end());
    a = removeDups(a);
    go(0, 0, a, target);
    return ans;
}
