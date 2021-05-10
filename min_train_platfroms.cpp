
/*
version 1: trains arrive on stations min platfrom needed
version 2: guest arrive in restraunt min table needed

https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

NOTE: If time read Editorial, there is also a multimap approach
*/


#include<bits/stdc++.h>
using namespace std;


// O(nlogn) time, O(n) space
int findPlatform(int arr[], int dep[], int n) {
	vector<pair<int, int>> times;
	for(int i=0; i<n; i++) {
	    times.push_back({arr[i], 'a'});
	    times.push_back({dep[i], 'd'});
	}
	sort(times.begin(), times.end());
	
    int ans = 1, curr = 0;
	for(auto t: times) {
	    if(t.second == 'a') {
            curr++;
            ans = max(ans, curr);
	    } else {
	        curr--;
	    }
	}
	return ans;
}

// O(n) time, O(time_range) space
int minPlatform(int arrival[], int departure[], int n) {
    // as time range from 0 to 2359 in 24 hour clock,
    // we declare an array for values from 0 to 2360
    int platform[2361] = {};
    int ans = 1;
    for (int i = 0; i < n; i++) {
        // increment the platforms for arrival
        ++platform[arrival[i]]; 
         // once train departs we decrease the platform count
        --platform[departure[i] + 1];
    }

    // do the prefix sum
    for (int i = 1; i < 100000; i++) {
        platform[i] = platform[i] + platform[i - 1]; 
        ans = max(ans, platform[i]);
    }
    return ans;
}


// O(nlogn) time, O(1) space
int min_platforms_needed(vector<int> arr, vector<int> dep) {
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int platforms = 1, result = 1;
    int i = 1, j = 0, n = arr.size();   // starting from the arrival of second train as 
                                        // min 1 platfrom will always bww needed 
    while(i < n && j < n) {
        //  if arrival time is same as dep time of another train, 
        // then min 2 platforms are needed, we cannot have 2 trains at same time on 1 platform
        if(arr[i] <= dep[j]) {
            ++platforms;
            ++i;
            result = max(platforms, result);
        }
        else {
            --platforms;
            ++j;
        }
    }
    return result;
}


int main() {
}