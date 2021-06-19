
/*
    https://www.geeksforgeeks.org/stack-permutations-check-if-an-array-is-stack-permutation-of-other/
    Given Two permutation a and b
    Check if b is stack permutation of a
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {1, 2, 3, 4};
    vector<int> b = {4, 1, 3, 2};
    
    int i = 0, j = 0;
    stack<int> st;

    while(i < a.size()) {
        while(i < a.size() && j < b.size() && a[i] != b[j]) {
            st.push(a[i]);
            i++;
        }
        i++;
        j++;

        while(j < b.size() && !st.empty()) {
            if(st.top() != b[j]) {
                cout << "no!";
                break;
            }
            st.pop();
            j++;
        }
    }

    if(st.empty() && j == b.size()){
        cout << "Yes";
    }
}