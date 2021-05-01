/*
    https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/
    Find the min and max from array with minimum comparisons 
*/

#include<bits/stdc++.h>
using namespace std;

/*
Method 1 (Simple Linear Search) 
In this method, the total number of comparisons is 1 + 2(n-2) in the worst case and 1 + n – 2 in the best case. 
In the above implementation, the worst case occurs when elements are sorted in descending order and 
the best case occurs when elements are sorted in ascending order.
*/


/*
METHOD 2 (Tournament Method)
Divide and Conquer
T(n) = T(floor(n/2)) + T(ceil(n/2)) + 2  
T(2) = 1
T(1) = 0
If n is a power of 2, then we can write T(n) as: 
T(n) = 2T(n/2) + 2
T(n)  = 3n/2 -2
Thus, the approach does 3n/2 -2 comparisons if n is a power of 2. 
And it does more than 3n/2 -2 comparisons if n is not a power of 2.
*/

// {min, max}
pair<int, int> findMinMax(vector<int> &a, int low, int high) {
    if(low == high) {
        return {a[low], a[high]};
    }
    else if(low + 1 == high) {
        if(a[low] < a[high]) {
            return {a[low], a[high]};
        }
        return {a[high], a[low]};
    }

    int mid = (low + high)/2;
    auto left = findMinMax(a, low, mid);
    auto right = findMinMax(a, mid+1, high);
    pair<int,int> ans = {0, 0};
    
    // min
    if(left.first < right.first) {
        ans.first = left.first;
    }
    else {
        ans.first = right.first;
    }
    // max
    if(left.second > right.second) {
        ans.second = left.second;
    }
    else {
        ans.second = right.second;
    }
    return ans;
}


/*
METHOD 3 (Compare in Pairs) 
If n is odd then initialize min and max as first element. 
If n is even then initialize min and max as minimum and maximum of the first two elements respectively. 
For rest of the elements, pick them in pairs and compare their 

If n is odd:    3*(n-1)/2  
If n is even:   1 Initial comparison for initializing min and max, 
    and 3(n-2)/2 comparisons for rest of the elements  
    =  1 + 3*(n-2)/2 = 3n/2 -2

Best approach in any case comparisons = 3n/2-2
*/

pair<int, int> findMinMax(vector<int> &a) {
    int n = a.size(), i = 0;
    pair<int, int> ans = {0, 0};
    if(n%2 == 1) {
        ans = {a[0], a[0]};
        i = 1;
    }
    else {
        if(a[0] < a[1]) {
            ans = {a[0], a[1]};
        }
        else {
            ans = {a[1], a[0]};
        }
        i = 2;
    }

    for(; i+1<n; i++) {
        if(a[i] < a[i+1]) {
            if(a[i+1] > ans.second) {
                ans.second = a[i+1];
            }
            if(a[i] < ans.first) {
                ans.first = a[i];
            }
        }
        else {
            if(a[i] > ans.second) {
                ans.second = a[i];
            }
            if(a[i+1] < ans.first) {
                ans.first = a[i+1];
            }
        }
    }
    return ans;
}


int main() {
    vector<int> a = {4, 3, 3, 5, 8, 5, 1};
    int n = a.size();
    auto ans = findMinMax(a, 0, n-1);
    cout << ans.first << " " << ans.second << "\n";
    ans = findMinMax(a);
    cout << ans.first << " " << ans.second << "\n";
}