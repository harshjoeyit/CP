
/*
Two players play the game of choosing the stone fron either end.
On each change the score of sum of remainging stones after choosing.
Find the minimum score difference
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

// Method 1.

vector<int> prefix;
int dp[1002][1002];

int go(int i, int j, int sum, vector<int> &a) {
    if(i > j) {
        return 0;
    }
    
    int &ans = dp[i][j];
    if(ans != -1) {
        return ans;
    }
    
    // we subtract go(...)
    // because each player wants to substract the result of other player 
    int front = sum-a[i] - go(i+1, j, sum-a[i], a);
    int back = sum-a[j] - go(i, j-1, sum-a[j], a);
    // since alice has the first choice she has advantage of winning each time
    
    return ans = max(front, back);
}


int stoneGameVII(vector<int>& a) {
    int n = a.size();
    int sum = accumulate(a.begin(), a.end(), 0);
    memset(dp, -1, sizeof(dp));
    
    return go(0, n-1, sum, a);
}



// Method 2
// More intuitive solution by Aman

pair<int, int> dp[1001][1001][2];
vector<int> pref;

pair<int, int> solve(vector<int> &stones, int i, int j, int flag) {
    if(i > j) return {0, 0};
    
    int &ans = dp[i][j][flag]
	if(ans.first != -1) {
		return ans;
	}
    int sum = pref[j];
    if(i > 0) {
        sum -= pref[i - 1];
    }
    
    auto front = solve(stones, i + 1, j, !flag);
    auto back = solve(stones, i, j - 1, !flag);
	
	int front_alice_next = front.first, front_bob_next = front.second;
	int back_alice_next = back.first, back_bob_next = back.second; 
    
    if(flag) {
        // Alice's turn
        int a = (sum - stones[i]) + front_alice_next;
        int b = front_bob_next;
        
        int x = (sum - stones[j]) + back_alice_next;
        int y = back_bob_next;
        
        if((a - b) > (x - y)) {
            return ans = {a , b};
        } 
        return ans = {x, y};
    }

    // Bobs Turns;
    int b = (sum - stones[i]) + front_bob_next;
    int a = front_alice_next;

    int y = (sum - stones[j]) + back_bob_next;
    int x = back_alice_next;
    
    if((a - b) < (x - y)) {
        return ans = {a, b};
    }
    return ans = {x, y};
}

int stoneGameVII(vector<int>& stones) {  
	for(int i=0; i<1001; i++) {
		for(int j=0; j<1001; j++) {
			for(int k=0; k<2; k++) {
				dp[i][j][k] = {-1, -1};
			}
		}
	}
    pref.clear();
    int sum = 0;
    for(int i = 0; i < stones.size(); i++) {
        sum += stones[i];
        pref.push_back(sum);
    }
    auto p = solve(stones, 0, stones.size() - 1, 1);
    int ans = p.first - p.second;
    return ans;
}
