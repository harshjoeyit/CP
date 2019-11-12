#include<iostream>
#include<vector>
using namespace std;

int binarysearch(int searchy, vector<int>::iterator h, vector<int>::iterator l)
{
    vector<int>::iterator mid;
    while(l<=h)
    {
        mid=l+(h-l)/2;

        if(*mid==searchy)
            return 1;
        if(*mid>searchy)
            h=mid-1;
        else
            l=mid+1;
    }
    return 0;

}

void vectorin(vector<int> &vec1)   //by reference ,the variable defined is just a dummy variable
{
    int c=1;
    while(c!=0)
    {
       int n=0;
       cout<<"enter the n:";
       cin>>n;
       vec1.push_back(n);
       cout<<"press 0 to stop adding and any other no. to continue";
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
// MAJOR ERROR: SORT THIS VECTOR USING COMPARITOR FUNCTION
    while(cin>>searchx)
    {
    if (binarysearch(searchx,high,low) == 1)
        cout<<"found \n";
    else
        cout<<"not found \n";
    }

return 0;
}
