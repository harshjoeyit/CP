/*
    https://www.geeksforgeeks.org/three-way-partitioning-of-an-array-around-a-given-range/
*/

#include<bits/stdc++.h>
using namespace std;


void threeWayPartition(vector<int>& arr, int a, int b) {
    int n = arr.size(), l = 0, h = n - 1;
    // Note: i <= h
    for(int i=0; i<=h; ) {
        if(arr[i] < a) {
            swap(arr[i++], arr[l++]);
        }
        else if(arr[i] > b) {
            swap(arr[i], arr[h--]);
        }
        else {
            i++;
        }
    }
}


/*
    My method, WA on GFG
*/

// partition by val
// all a[i] in range [0....pi-1]  are <= val
int partition(vector<int> &a, int l, int r, int val) {
    int pi = l;
    for (int i = l; i <= r; i++) {
        if(a[i] <= val) {
            swap(a[i], a[pi]);
            pi++;
        }
    }
    return pi-1;
}

void threeWayPartition(vector<int>& arr, int a, int b) {
    int pi = partition(arr, 0, arr.size()-1, a);
    pi = partition(arr, pi+1, arr.size()-1, b);
}

int main() {

}