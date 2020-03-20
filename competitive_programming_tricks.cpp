#include<bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {1, 2, 3, 3, 5, 7, 7, 8, 9};
    int n = sizeof(a)/sizeof(a[0]);

    // binary search in a sorted array

    cout << binary_search(a, a+n, 5) << endl;
    cout << binary_search(a, a+n, 3) << endl;
    cout << binary_search(a, a+n, 4) << endl;

    // binary of a number

    cout << bitset<20>(n) << "\n";

    // min of >=2 elements 

    int x  = min({2, 3, 4, -1, 3, 7, 8, 9});
    cout << x << endl;

}