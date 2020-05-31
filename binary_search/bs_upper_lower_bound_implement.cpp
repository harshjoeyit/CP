#include<bits/stdc++.h>
using namespace std;

bool binary_search(int l, int h, vector<int> v, int x) {
    while( l <= h)
    {
        int mid = l + (h-l)/2;
        if(x == v[mid])
            return true;
        else if(x > v[mid])
            l = mid + 1;
        else
            h = mid - 1;
    }
    return false;
}

int upperbound(int l, int h, vector<int> v, int x) {
    int ans = -1;
    while( l <= h) {
        int mid = l + (h-l)/2;
        if(v[mid] > x) {
            h = mid - 1;
            ans = mid;
        }
        else
            l = mid + 1;
    }
    return ans;
}

int lowerbound(int l, int h, vector<int> v, int x) {
    int ans = -1;
    while( l <= h) {
        int mid = l + (h-l)/2;
        if(v[mid] >= x) {
            h = mid - 1;
            ans = mid;
        }
        else
            l = mid + 1;
    }
    return ans;
}

int main()
{
    vector<int> v = {12,2,3,4,7,9,5,5,5,11,8,33,10};
    sort(v.begin(), v.end());
    int x = 5;

    cout << "binary search : " << binary_search(0, v.size()-1, v, x) << endl;
    cout << "upperbound is at: " << upperbound(0, v.size()-1, v, x) << " value: " << v[upperbound(0, v.size()-1, v, x)] << endl;
    cout << "lowerbound is at: " << lowerbound(0, v.size()-1, v, x) << " value: " << v[lowerbound(0, v.size()-1, v, x)]<< endl;
    
    
}