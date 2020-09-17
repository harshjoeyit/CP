
/*
https://leetcode.com/problems/video-stitching/

Generally 
we are given itervals [start, end] time 
merge minimum to form a interval [0, T]
*/

#include <bits/stdc++.h> 
#include <vector> 
using namespace std; 

/*
- You might have figured out we need a travesal scheme.
- Also you would have thought to order the clips in increasing order of {start, end} time
- For travesal, did you think of some kind of BFS?
- You are correct, we attempt this problem by a similar approach.
- Since we have sorted things will be easy
- We try to combine the clip[i] {st, en} with clip[j] {currSt, currEn} , where j > i and j < n only when
    a. when the ovelapp is partial, i.e clip[j] should not be completly inside clip[i].
    b. We come up with following formula for merging
    c. (st < currSt && currSt <= en && en < currEn)
- While merging we store the minimimum (merged) for each clip
*/

int videoStitching(vector<vector<int>>& clips, int T) {
    int n = clips.size();
    sort(clips.begin(), clips.end());
    
    // sotres the min clips to get to the clip i
    vector<int> minToReach(n, 2*T);
	// a high value 
    int ans = 2*T;
    
    for(int i=0; i<n; i++) {
		// starting and ending time 
        int st = clips[i][0];
        int en = clips[i][1];
        
        if(st == 0) {
			// first clip
            minToReach[i] = 1;
        }
        
        if(en >= T) {
			// last clip update ans 
            ans = min(ans, minToReach[i]);
            continue;
        }
        
		// for all the intermediate clips 
        for(int j=i+1; j<n; j++) {
			// starting and ending time
            int currSt = clips[j][0];
            int currEn = clips[j][1];
                
            if(st < currSt && currSt <= en && en < currEn) {
				// valid clip, update min clips to reach here  
                minToReach[j] = min(minToReach[j], minToReach[i] + 1);
            }
        }
    }
    
    return (ans == 2*T? -1: ans);
}