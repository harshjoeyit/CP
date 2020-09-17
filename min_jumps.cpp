
/*
      nums[i] = max size forward jump person can take if he is at a[i]
*/

#include<bits/stdc++.h>
using namespace std;

// dp solution works in O(n * max element)

// greedy 
int jump(vector<int> &nums) {
     int pos = 0;
     int dest = 0;
     int jump = 0;

     for(int i=0; i<nums.size()-1; i++) {
           // untill we reach the pos
           // find the farthest destination possible,
           // well jump to it 
           dest = max(dest, i + nums[i]);

           if(pos == i) {
                 pos = dest;
                 jump++;
            }
     }
     return jump;
}