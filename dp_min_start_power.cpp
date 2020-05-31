
/*
https://leetcode.com/problems/dungeon-game

ex - 
3 3
-2 -3 3
-5 -10 1
10 30 -5
7
*/


#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> dp;
int memorizedDFS(int row, int col, vector<vector<int>>& dungeon){
    	if(dp[row][col] != -1)
      	return dp[row][col];
    
    	int a = INT_MAX;
    	if(col < dungeon[0].size()-1)
    		a = memorizedDFS(row, col+1, dungeon);
    	if(row < dungeon.size()-1)
    	    	a = min(memorizedDFS(row+1, col, dungeon), a);
    	if(dungeon[row][col] < 0)
    	    	dp[row][col] = a - dungeon[row][col];
    	else{
    	    	dp[row][col] = - min(0LL, dungeon[row][col] - a);
    	}
    	return dp[row][col];
}


int calculateMinimumHP(vector<vector<int>>& dungeon) {
    if(dungeon.size() == 0 || dungeon[0].size() == 0)
        return 0;
    dp = vector<vector<int>>(dungeon.size(), vector<int>(dungeon[0].size(), -1));
    dp.back().back() = max(-dungeon.back().back(), 0LL);
    return memorizedDFS(0, 0, dungeon) + 1;
}

signed main() {
	int rows, cols;
	cin >> rows >> cols;
	vector<vector<int> > a(rows, vector<int>(cols));

	for(int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			cin >> a[i][j];
		}
	}

	cout << calculateMinimumHP(a) << endl;

	for(int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}