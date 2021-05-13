/*
    https://www.geeksforgeeks.org/find-maximum-sum-possible-equal-sum-three-stacks/

    Find If sum of three stacks can become equal after popping at max 3 elements from each.
*/
#include<bits/stdc++.h>
using namespace std;

int getSum(vector<int> &a) {
    return accumulate(a.begin(), a.end(), 0);
}

int maxSum(vector<int> a, vector<int> b, vector<int> c) {
    // index 0 is stack top
    int la = a.size(), lb = b.size(), lc = c.size();
    int sa = getSum(a), sb = getSum(b), sc = getSum(c);
    int i, j, k;
    i = j = k = 0;

    while(i < min(la, 3) && j < min(lb, 3) && k < min(lc, 3)) {
        if (sa == sb && sb == sc) {
            return sa;
        }
        else if (sa >= sb && sa >= sc) {
            sa -= a[i];
        } 
        else if (sb >= sa && sb >= sc) {
            sb -= b[j];
        }
        else {
            sc -= c[k];
        }
    }
    return -1;
}

int main() {
    cout << maxSum({ 3, 2, 1, 1, 1 }, {4, 3, 2}, {1, 1, 4, 1}) << endl;
}