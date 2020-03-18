#include<iostream>
#include<vector>
using namespace std;

int binarysearch(int searchy, vector<int>::iterator h, vector<int>::iterator l)
{
    auto mid=l+(h-l)/2;
    while(mid!=h)
    {
        if(*mid==searchy)
            return 0;
        if(*mid>searchy)
            h=mid;
        else
            l=mid+1;

        mid=l+(h-l)/2;
    }
    return -1;

}

void vectorin(vector<int> &vec1)   //by reference ,the variable defined is just a dummy variable
{
    int c=1;
    while(c!=0)
    {
       int n=0;
       cout<<"\n enter the n:";
       cin>>n;
       vec1.push_back(n);
       cout<<"\n press 0 to stop adding and any other no. to continue";
       cin>>c;
    }
}

int main()
{
    vector<int> vec;
    vectorin(vec);

    auto low=vec.begin();
    auto high=vec.end();
    int searchx;
    cout<<"enter the value to be searched : ";
    cin>>searchx;

    if (binarysearch(searchx,high,low)==0)
        cout<<"found \n";
    else
        cout<<"not found \n";


return 0;
}
