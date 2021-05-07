
/*
    https://practice.geeksforgeeks.org/problems/word-wrap1646/1
    Given the maximum characters a line can have, distribute the words in each line such that empty spaces are evenly distributed (cost is minimum)
*/

#include<bits/stdc++.h>
using namespace std;

int getArrangement(vector<int> &result, int n, vector<vector<int>> &ans) {
    int k;
    if(result[n] == 1) {
        k = 1;
    } else {
        k = getArrangement(result, result[n]-1, ans) + 1;
    }
    ans.push_back({result[n], n});
    return k;
}

vector<vector<int>> solveWordWrap (vector<int>nums, int lineWidth) { 
    int n = nums.size();
    vector<vector<int>> es(n+1, vector<int>(n+1, 0));
    vector<vector<int>> cost(n+1, vector<int>(n+1, 0));

    /* calculate empty spaces when putting words from i to j in one line. 
    If words don't fit in one line then empty spaces < 0 */
    for(int i=1; i<=n; i++) {
        es[i][i] = lineWidth - nums[i-1];
        for(int j=i+1; j<=n; j++) {
            es[i][j] = es[i][j-1] - nums[j-1] - 1;
        }
    }

    /* calculate cost of empty spaces for each line
    for x empty spaces, cost = x*x  */
    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j++) {
            if (es[i][j] < 0) {
                cost[i][j] = INT_MAX;
            }
			else if (j == n && es[i][j] >= 0) {
                // for last line, the remaining space are not considered, since there will be no words after this line
                cost[i][j] = 0;
            }
			else {
                cost[i][j] = es[i][j]*es[i][j];
            }
        }
    }

    vector<int> minCost(n+1, 0);
    vector<int> result(n+1, 0);

    minCost[0] = 0;
    for(int j = 1; j <=n; j++) {
        minCost[j] = INT_MAX;
        for(int i = 1; i <= j; i++) {
            if(minCost[i-1] != INT_MAX && cost[i][j] != INT_MAX && (minCost[i-1] + cost[i][j] < minCost[j])) {
                minCost[j]  = minCost[i-1] + cost[i][j];
                result[j] = i;
            }
        }
    }

    vector<vector<int>> ans;
    getArrangement(result, n, ans);
    return ans;
}

int main() {
    auto ans = solveWordWrap({3, 5, 7, 4, 3, 4, 1, 5, 8, 5}, 12);

    for(auto v: ans) {
        for(auto val: v) {
            cout << val << " ";
        }cout << "\n";
    }
}