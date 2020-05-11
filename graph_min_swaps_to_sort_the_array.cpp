
/*
Minimum swaps to sort the array

Similar problem - min swaps to sort a binary array 
Approach - count the no of zeroes from i = n-1 to i = 0, if(a[i] == 1) ans += zeroes_cnt
1 0 0 1 0 1
ans = 0+1+3 = 4
1 1 0 0 
ans = 2+2
1 0 1 0 1 0
ans = 1+2+3 = 6
*/

#include<bits/stdc++.h>   
using namespace std; 

int minSwaps(int arr[], int n) { 
    
    pair<int, int> arrPos[n]; 
    for (int i = 0; i < n; i++) { 
        arrPos[i].first = arr[i]; 
        arrPos[i].second = i; 
    }   
    // after sorting the elements are at their correct place and THERE IS AN EDGE BETWEEN arrPos[i].second ----> arrPos[i].first 
    sort(arrPos, arrPos + n); 

    vector<bool> vis(n, false); 
    int ans = 0; 

    for (int i = 0; i < n; i++) { 
        // already swapped and corrected or already present at correct pos 
        if (vis[i] || arrPos[i].second == i) 
            continue; 
  
        // count the nodes in this cycle 
        int cycle_size = 0; 
        int j = i; 
        while (!vis[j]) { 
            vis[j] = 1; 
            // move to next node 
            j = arrPos[j].second; 
            cycle_size++; 
        }  
        if (cycle_size > 0) { 
            ans += (cycle_size - 1); 
        } 
    } 
    return ans; 
} 


int main()  { 
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    cout << minSwaps(a, n) << "\n"; 
} 