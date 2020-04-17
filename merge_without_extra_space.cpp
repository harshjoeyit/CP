
// IMP: 
// final content should be in those arrays itself

/*
Input: arr1[] = {10};
       arr2[] = {2, 3};
Output: arr1[] = {2}
        arr2[] = {3, 10}  

Input: arr1[] = {1, 5, 9, 10, 15, 20};
       arr2[] = {2, 3, 8, 13};
Output: arr1[] = {1, 2, 3, 5, 8, 9}
        arr2[] = {10, 13, 15, 20} 

*/

#include<bits/stdc++.h>
using namespace std;

#define int long long 

// APPROACH: all elements in b are greater than equal to all elements in a
// a is the larger size array, b is the smaller size array

void merge(int a[], int n, int b[], int m) {

    int i=0, j=0, k=n-1;                // i, j points to smallest elemnt in a, b
                                        // k points to the largest element in a
    while(i <= k && j < m) {
        if(a[i] > b[j]) {               // if an element in b is smaller than in a , it means it belongs in array a
            swap(b[j], a[k]);           // one of the values from array a(the last value) should be swapped with this value in array b
            k--;                        // k points to largest element in a again
            ++j;                        // j points to smallest element in b again 
        } else {
            ++i;                        // a[i] < b[j] this means elements are in correct arrays as they should be
        }
    }
    sort(a, a+n);                       // sort both arrays
    sort(b, b+m);
                                        // all elements in b are greater than equal to all elements in a
    for(int i=0; i<n; i++)
        cout << a[i] << " ";
    for(int j=0; j<m; j++)
        cout <<  b[j] << " ";
    cout << endl;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];

    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int j=0; j<m; j++)
        cin >> b[j];
    
    if(n > m) {                     // send the larger array as the first argument 
        merge(a, n, b, m);
    } else {
        merge(b, m, a, n);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}