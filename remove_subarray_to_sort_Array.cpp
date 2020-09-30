
/*
Remove smallest subarray to make array sorted 
*/

#include<bits/stdc++.h>
using namespace std;

int smallestSubarray(vector<int>& a) {
    int n = a.size();
    int en = n - 1;
    
    // find largest sorted subarray from the end
    while(en > 0 && a[en - 1] <= a[en]) {
        en -= 1;
    }
    
    auto ans = en;
    int st = 0;
    
    // try joining the subarray from start to the end subarray 
    while(st < en && (st == 0 || a[st - 1] <= a[st])) {
        // to make join possible
	  // a[st] <= a[en], so move en to right untill the condition is reached
	  while(en < n && a[en] < a[st]) {
            en += 1;
        }
	  // remove current window
        ans = min(ans, en - st - 1);
        st += 1;
    }
    
    return ans;
}

int main() {
}