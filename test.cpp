#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &a);
w

int main() {

    // array
    int a[] = {8, 13, 7, 6, 4, 8, 5, 15, 11, 13, 18} ;
    int n = sizeof(a)/sizeof(int);
    sort(a, a+n);
    cout << binary_search(a, a + n, 6);

    // vector
    // vector<int> a =  {-2, 3, -1, -1, 2, 4, 12, 11, -1};
    // vector<int> a = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};

    // input
    // int n;
    // cin >> n;
    // vector<int> v(n);
    // for(auto &val: v) {
    //     cin >> val;
    // }

    // int ans 
    // cout << ans << "\n";
    
}


void print(vector<int> &a) {
    for(auto val: a) {
        cout << val << " ";
    }cout << endl;
}