#include<bits/stdc++.h>
using namespace std;

// count subarrays with the product less than a given number
int count_subarrays(vector<int> &v, int k)
{
    int st = 0, en = 0, prod = v[0], Count = 0;


    while(en != v.size())
    {
        if(prod < k)
        {
            Count += (en - st) + 1;
            //cout << "st: " << st << " end " << en << endl;
            //cout << Count << endl;
            prod = prod * v[++en];
        }
    
        while(prod >= k)
            prod = prod/v[st++];
    }
    return Count;
}

int main()
{
    vector<int> v = {1,9,2,8,6,4,3};
    cout << count_subarrays(v, 150) << endl;
}