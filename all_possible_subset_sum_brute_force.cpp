#include<bits/stdc++.h>
using namespace std;

void print_all_possible_sums(int a[], int n, int i, int sum, set<int> &s) {
    if(i <= n) {
        s.insert(sum);
        print_all_possible_sums(a, n, i+1, sum, s);
        print_all_possible_sums(a, n, i+1, sum+a[i], s);
    }
}

int main() {
    int a[] = {2, 5, 1};
    set<int> s;
    print_all_possible_sums(a, sizeof(a)/sizeof(a[0]), 0, 0, s);
    for(auto x: s)
        cout << x << " ";
    cout << endl;

    // using bitsets
    // field should be set keeping the max sum in mind 
    bitset<20> b;   
     b[0]  = 1;
     for (int i = 0; i < 3; i++) {
           b = b | (b << a[i]);
     }

     cout << b << endl;
     for (int s = 0; s < 20; s++) {
           if(b[s]) {
                 cout << s << endl;
           }
     }
}