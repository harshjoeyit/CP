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
    // for both methods we need to sort the vector

    vector<int> v = {6, 7, 8, 1,1, 5, 5, 1,2,2,3,5,6,6};
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    print(v);

    vector<int> vec = {1, 2, 3, 2, 2, 1, 1, 3, 4, 6, 6, 1};
    sort(vec.begin(), vec.end());
    vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
    print(vec);
}


