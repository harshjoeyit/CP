#include<bits/stdc++.h>
using namespace std;

struct stu {
    int el, cnt;
};

// Method 1 
// (Brute Force, count occurance of each element)
// O(n*n) time, O(1) space

// Method 2: 
// Hash table 
// O(n) time O(n) space

// Method 3: 
// Sort and count 
// O(n*logn) time and O(1) space

// Method 4:
// O(n*k) time and O(k) space

int countOccurence(int a[], int n, int k) {
    vector<stu> store(k-1);
    
    // takes O(n*k)
    for(int i=0; i<n; i++) {
        bool found = false;
        int vacant = -1;
        
        for(int j=0; j<k-1; j++) {
            if(store[j].el == a[i]) {
                store[j].cnt++;
                found = true;
            }
            if(store[j].cnt == 0) {
                vacant = j;
            }
        }

        if(!found) {
            if(vacant == -1) {
                // none vacant, decrease count of each by 1 and ignore a[i]
                for(auto &s: store) {
                    s.cnt--;
                }
            }
            else {
                // utilize vacant spot
                store[vacant] = {a[i], 1};
            }
        }
    }

    // count the total number of occurances of the elements in store 
    // NOTE: cnt in store is not the actal freq of the element 
    int ans = 0;
    for(auto &s: store) {
        if(s.cnt > 0 && count(a, a+n, s.el) > n/k) {
            ans++;
        }
    }

    return ans;
}



int main() {

}