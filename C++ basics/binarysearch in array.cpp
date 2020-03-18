#include<iostream>
using namespace std;

vector<int> binarysearch(int searchy, vector<int>::iterator l, vector<int>::iterator h, vector<int> ivec)
{
    while(l<=h)
    {
        vector<int>::iterator mid;
        mid =(l+h)/2;

        if (*mid==searchy)
            return 0;

        else if(*mid<searchy)
            l=mid+1;

        else if(*mid>searchy)
            h=mid-1;
    }
    return -1;
}

int main()
{
    vector<int> vec;

    auto low=vec.begin();
    auto high=vec.end();
    int searchx;
    cout<<"enter the value to be searched : ";
    cin>>searchx;

    if (binarysearch(searchx,high,low,b)==0)
        cout<<"found \n";
    else
        cout<<"not found \n";


return 0;
}
