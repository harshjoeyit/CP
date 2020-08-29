/*
https://leetcode.com/problems/stone-game-iv/

Approach 

1. Playing Optimally means, each player will try to win the game and play the moves accordingly 
2. Tha catch here is that we want to find if starting with `n` stones alice wins or not 
3. **if it is Alice's turn then we just need to find one move that makes here win.
    when its Bob's turn then for all the possible moves that he makes Alice should win in every move**
4. We will write a brute force and then memoize it.
5. The DP state will be `[stones left][whose chance it is]`

*/

int dp[100005][2];
    
int go(int stones, int aliceTurn) {
    if(stones == 0) {
        return !aliceTurn;
    }
    
// memoized result for the state 
    int &ans = dp[stones][aliceTurn];
    if(ans != -1) {
        return ans;
    }
    
    if(aliceTurn) {
        ans = 0;
	      // if it is Alice's turn then we just need to find one move that makes here win
	      // so we do `OR`
        for(int i=1; i*i<=stones; i++) {
            ans = ans | go(stones - i*i, !aliceTurn);
        }
    } else {
        ans = 1;
	      // when its Bob's turn then 
	      // for all the possible moves Alice should win
	      // so we take `AND`
        for(int i=1; i*i<=stones; i++) {
            ans = ans & go(stones - i*i, !aliceTurn);
        }
    }
    
    return ans;
}

bool winnerSquareGame(int n) {
    memset(dp, -1, sizeof(dp));
// the game start with n stones Alice starting first 
    return go(n, true);
}