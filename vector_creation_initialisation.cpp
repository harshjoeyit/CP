#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[]={1,2,3,4,5,6,7,8,9,10};
    
    vector<int> vec (a,a+8);  // to int pointers

    for(auto it = vec.begin(); it != vec.end(); it++)
        cout<<*it<<" ";

    vector<int> vec1 (vec.begin(), vec.begin()+5);  // to iterators

    cout<<endl;
    for(auto it = vec1.begin(); it != vec1.end(); it++)
        cout<<*it<<" ";

    return 0; 
}