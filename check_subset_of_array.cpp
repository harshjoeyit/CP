#include<bits/stdc++.h>
using namespace std;

// Note each element is unique in a and b
// check if b is a subset of a

/*
    Brute force, O(n*m)
    use two loops to check 
*/

/*
    hashing, O(n) time, O(n) space
*/
string isSubset(int a[], int b[], int n, int m) {
    unordered_set<int> st;
    for(int i=0; i<n; i++) {
        st.insert(a[i]);
    }
    for(int i=0; i<m; i++) {
        if(!st.count(b[i])) {
            return "No";
        }
    }
    return "Yes";
}

/*
    binary search approach, O(nlogn) time, O(1) space
*/
string isSubset(int a[], int b[], int n, int m) {
    sort(a, a + n);
    for(int i=0; i<m; i++) {
        if(!binary_search(a, a+n, b[i])) {
            return "No";
        }
    }
    return "Yes";
}

int main() {
    
}