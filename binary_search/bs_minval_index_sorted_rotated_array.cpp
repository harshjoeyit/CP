
/*
Exmaples of array - 
2 3 4 5 6 1
4 5 6 1 2 3
8 9 1 2 3 4 6 7
1 2 3
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long int

// min val index with duplicates, works with non-duplicates too
int findMin(vector<int>& a) {
    int low = 0, high = a.size() -1;
    while(low < high) {
        int mid = (low + high)/2;

        if(a[mid] > a[high]) {
            low = mid + 1;
        
        } else if(a[mid] < a[high]) {
            high = mid;
        
        } else {
            if (a[high - 1] > a[high]) {
                // this is the min indminex for sure 
                low = high;
                break;
            }
            high--;
        }
    }
    return a[low];
}

// min val index of rotated sorted array with no duplicates 
int minEleIndex(vector<int> &a) {
    int low = 0, high = a.size() - 1;
    
    while(low < high) {
        int mid = (low + high)/2;
        
        if(a[mid] > a[high]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}


// simple binary search in a range 
int bs(int st, int en, int target, vector<int> &a) {
    while(st <= en) {
        int mid = (st + en)/2;
        if(a[mid] == target) {
            return mid;
        } else if(a[mid] > target) {
            en = mid - 1;
        } else {
            st = mid + 1;
        }
    }
    
    return -1;
}


int search(vector<int>& a, int target) {
    // for the case when no duplicate values occur, 
    // use findMin function to get index 
    int i = minEleIndex(a);
    int n = a.size();
    
    if(target == a[i]) {
        return i;
    }
    
    int ans;
    if(target <= a[n-1]) {
        ans = bs(i, n-1, target, a);
    } else {
        ans = bs(0, i, target, a);
    }
    
    return ans;
}
