

#include<bits/stdc++.h>
using namespace std;

const int N = 1000;


// O(n*k*k), O(k) Space Solution (using index array)

pair<int,int> findSmallestRange(int arr[][N], int n, int k)
{
    int ansL = 0, ansR = INT_MAX;
    
    // index[i] = current index in ith list
    int index[k] = {0};
    bool flag = true;
    
    while(flag) {
        int minVal = INT_MAX, minI = 0;
        int maxVal = 0;

        // find the minimum, maximum value among the top elements of the k lists
        for(int i=0; i<k; i++) {
            if(index[i] == n) {
                flag = false;
                break;
            }
            if(arr[i][index[i]] < minVal) {
                minVal = arr[i][index[i]];
                minI = i;
            }
            maxVal = max(maxVal, arr[i][index[i]]);
        }
    
        if(flag) {
            // check if current range smaller than answer range
            if(maxVal - minVal < ansR - ansL) {
                ansR = maxVal;
                ansL = minVal;
            }
            
            // move to next element in the list which has the minimum value
            index[minI]++;
        }
    }
    
    return {ansL, ansR};
}


struct st {
    int val, list, idx;
    bool operator < (const st &rhs) const {
        return val > rhs.val;
    }
};

// O(n*k*loog(k)) time, O(k) space solution

pair<int,int> findSmallestRange(int arr[][N], int n, int k) {
    priority_queue<st> pq;
    // max element
    int mx = INT_MIN;
    int ansL = 0, ansR = INT_MAX;
    
    for(int i=0; i<k; i++) {
        pq.push({arr[i][0], i, 0});
        mx = max(mx, arr[i][0]);
    }
    
    while(1) {
        auto t = pq.top(); pq.pop();
        int mn = t.val, lst = t.list, i = t.idx;
        
        if(mx - mn < ansR - ansL) {
            ansL = mn; 
            ansR = mx;
        }
        // list is finished
        if(i == n-1) {
            break;
        }
        i++;
        
        // update max element
        mx = max(arr[lst][i], mx);
        pq.push({arr[lst][i], lst, i});
    }
    
    return {ansL, ansR};
}

int main() {
}