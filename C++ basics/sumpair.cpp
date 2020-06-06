// enter to print the numbers wit inputted sum in pairs
#include<iostream>
#include<vector>
using namespace std;

void vectorin(vector<int> &vec1)   //by reference ,the variable defined is just a dummy variable
{
    int c=1;
    while(c!=0)
    {
       int n=0;
       cout<<" enter the n:";
       cin>>n;
       vec1.push_back(n);
       cout<<" press 0 to stop adding and any other no. to continue";
       cin>>c;
    }
}

void solve(const vector<int> &vec1, int s)
{
    int low =0;
    int high = vec1.size()-1;

    while(low<high)
    {
        int sum = vec1[high]+vec1[low];
        if(sum=s)
            cout<<"("<<vec1[high]<<"+"<<vec1[low]<<") ="<<s<<endl;
        ++low;
        --high;
    }
}

main()
{
    vector<int> ivec;
    int s;
    vectorin(ivec);
    cout<<"enter the sum"<<endl;;
    cin>>s;
    // vector must be sorted here
    solve(ivec,s); //passing the vector and the sum
}
