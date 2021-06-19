/*
    divided into K non-empty subsets with equal sum of elements
    https://practice.geeksforgeeks.org/problems/partition-array-to-k-subsets/1#
*/

#include<bits/stdc++.h>
using namespace std;

/*
    Method 1.
    Time Complexity : O(k * 2^n)
*/

// To mark elements that are already used in a partition
vector<int> used;

int go(int i, int a[], int n, int ksum) {
    if(i == n) {
        return ksum == 0;
    }
    if(ksum < 0) {
        return 0;
    }
    // skip
    if(go(i+1, a, n, ksum)) {
        return 1;
    }
    
    if(!used[i]) {
        used[i] = 1;
        if(go(i+1, a, n, ksum - a[i])) {
            // recursive call was successful, used[i] remains 1
            return 1;       
        }
        // set used to 0 since the recursive call was not successfull
        used[i] = 0;
    }
    return false;
}

bool isKPartitionPossible(int a[], int n, int k) {
    int sum = accumulate(a, a+n, 0);
    if(sum % k != 0) {
        return false;
    }
    int ksum = sum/k;
    used.assign(n, 0);

    /*
        check if k partitions are possible 
    */
    while(k--) {
        if(!go(0, a, n, ksum)) {
            return 0;
        }
    }
    return 1;
}


/*
    Method 2.
    Time Complexity : O(k * n * sum)
*/

int dp[11][1005];

int go(int i, int a[], int n, int target) {
    if(i == n) {
        return target == 0;
    }
    if(target < 0) {
        return 0;
    }
    if(dp[i][target] != -1) {
        return dp[i][target];
    }
    
    return dp[i][target] = (go(i+1, a, n, target) || go(i+1, a, n, target - a[i]));
}


bool isKPartitionPossible(int a[], int n, int k) {
    int sum = accumulate(a, a+n, 0);
    if(sum % k != 0) {
        return false;
    }
    int ksum = sum/k;

    /* 
        Any single element of array cannot exceed ksum. For ex - 
        a[] = {4 3 2 3 5 2 1}
        k = 5, ksum = 4
        Without this max_element check, this gives output 1, as 
        sum = 4, 8, 12, 16, 20 all are possible but "5" cannot lie in any partition becuase ksum = 4
    */ 
    if(*max_element(a, a+n) > ksum) {
        return false;
    }
    /*
        we check if partition with 
        ksum, 2*ksum, 3*ksum, .........  k * ksum 
        all all possible 
    */
    for(int i=1; i<=k; i++) {
        memset(dp, -1, sizeof(dp));
        if(!go(0, a, n, i * ksum)) {
            return 0;
        }
    }
    return 1;
}