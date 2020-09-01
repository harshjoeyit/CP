
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
// main goal swap(a[largest], b[smallest]);
void merge(int a[], int n, int b[], int m) {

    int i=0, j=0, largest=n-1;                
    // i, j points to smallest elemnt in a, b, largest points to the largest element in a
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
    
    // all elements in b are greater than equal to all elements in a
    // for(int i=0; i<n; i++)
    //     cout << a[i] << " ";
    // for(int j=0; j<m; j++)
    //     cout <<  b[j] << " ";
    // cout << endl;
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