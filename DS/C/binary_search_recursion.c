#include<bits/stdc++.h>
using namespace std;

int bin_src_recn( vector<int> &vec ,int low , int high , int search )
{
    if( low > high )
        return -1;

    int mid = (low + high)/2;
    if(search > vec[mid])
        return bin_src_recn( vec , mid + 1 , high , search );
    else
    if(search < vec[mid])
        return bin_src_recn( vec , low , mid - 1 , search );
    
    return mid;
}

int main()
{
    vector<int> vec = { 1,2,3,4,5,6,7,8,9 };
    int search;
    while( cin>> search )
        cout<<"index: "<<bin_src_recn( vec , 0 , vec.size() - 1 , search )<<endl;

}