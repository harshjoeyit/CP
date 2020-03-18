#include<bits/stdc++.h>
using namespace std;

template <typename T>
void print(vector<T> v)
{
    for(auto x: v)
        cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> v = {1,1,1,2,2,3,5,6,6};
    v.erase(unique(v.begin(), v.end()), v.end());
    print(v);
}