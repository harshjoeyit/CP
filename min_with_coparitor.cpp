#include<bits/stdc++.h>
using namespace std;

int val = 10;
bool comp(int a, int b) {
    return (a % 5) < (b % 5);
}
int main() {
    // normal min val
    cout << min({3, 2, 1, 4, 5, 0}) << "\n";
    // finding value which has min val % 5 
    cout << min({3, 4, 2, 1, 5}, comp) << "\n";
}
