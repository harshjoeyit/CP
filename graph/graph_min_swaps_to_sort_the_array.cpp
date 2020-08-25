
/*
Minimum swaps to sort the array
*/

#include<bits/stdc++.h>   
using namespace std; 

int minSwaps(int arr[], int n) { 
    
    pair<int, int> arrPos[n]; 
    for (int i = 0; i < n; i++) { 
        arrPos[i].first = arr[i]; 
        arrPos[i].second = i; 
    }   
    
    sort(arrPos, arrPos + n); 
    // after the sorting the 
    // correct index of arrPos[i].first (element) is i 
    // and wrong index is arrPos[i].second
    // so we make a cycle from correct index to wrong index and carray on untill 
    // we revisit any index

    vector<bool> vis(n, false); 
    int ans = 0; 

    for (int i = 0; i < n; i++) { 
        // element already swapped and corrected (as arrPos[i].second is the correct position)
        // or already present at correct pos 
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