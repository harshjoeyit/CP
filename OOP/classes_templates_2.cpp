#include<bits/stdc++.h>
using namespace std;

// No-type template argument
// is computed at the complile time 

template<int size> void print() {
    cout << size << endl;
}

template<typename T>
T sum(T *arr, int size) {
    int s = 0;
    for(int i=0; i<size; i++) {
        s += arr[i];
    }
    return s;
}

template<typename T, int size>
T sum(T (&arr)[size]) {
    T s = 0;
    for(int i=0; i<size; i++) {
        s += arr[i];
    }
    return s;
}

int main() {
    // Non-type template arguments must be constant
    print<3>();
    int i = 3;
    // Error
    // print<i>();  

    int arr[] = {-1, 1, 1, 1, 2, 2};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << sum(arr, size) << endl;  
    // array size is not passed 
    cout << sum(arr) << endl;
    auto &ref = arr;
    cout << sum(ref) << endl;

    auto x = std::begin(arr);   
}