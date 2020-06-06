#include<bits/stdc++.h>
using namespace std;

int interpolation_search( vector<int> v, int data)
{
    int mid, l = 0, h = v.size()-1;

    while(l <= h)
    {
        mid = l + (h-l)*((data - v[l])/(v[h] - v[l]));

        if(data == v[mid])
            return mid;
        else if(data > v[mid])
            l = mid + 1;
        else 
            h = mid - 1;
    }
    return -1;
}

int main()
{
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    cout << "index of " << 5 << " is : " << interpolation_search(v, 5) << endl;
}