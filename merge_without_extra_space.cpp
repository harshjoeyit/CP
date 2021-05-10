
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

// Observation: all elements in b are greater than equal to all elements in a

/*
    Implementation 1.
    i points to back of a, a[i] is largest element in a, 
    j points to front of b, b[j] is smallest element in b
    we swap untill the largest in a <= smallest in b
*/
void merge(int a[], int b[], int n, int m) {  
    int i=n-1, j=0; 
    
    while(i >= 0 && j < m) {
        if(a[i] > b[j]) {
            swap(a[i], b[j]);
            i--, j++;
        } else {
            break;
        }
    }
    sort(a, a+n);
    sort(b, b+m);
}

// Implementation 2: 
// main goal swap(a[largest], b[smallest]);
void merge(int a[], int n, int b[], int m) {
    int i=0, j=0, largest=n-1;
    // i, j points to smallest element in a, b, 
    // largest points to the largest element in a
    while(i <= largest && j < m) {
        if(a[i] > b[j]) {
            // if an element in b is smaller than in a , it means it belongs in array a
            swap(b[j], a[largest]);
            largest--;
            j++;

        } else {
            ++i;
            // a[i] < b[j] this means elements are in correct arrays as they should be
        }
    }
    
    // sort both arrays
    sort(a, a+n);
    sort(b, b+m);
}

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];

    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int j=0; j<m; j++)
        cin >> b[j];

    merge(a, n, b, m);
}

signed main() {
    solve();
}