#include<iostream>
#include<vector>
using namespace std;

void input(vector<int> &vec1)   //by reference ,the variable defined is just a dummy variable
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

void prefix(vector<int> &vec1, vector<int> &vec2)
{
    int prefix=0;

    for(auto x=0; x<vec1.size(); x++)
    {
        if(vec1[x]!=vec2[x])
        {
            cout<<"not a prefix "<<endl;  // value of prefix does not change
            break;
        }
        else
            prefix=1;   // prefix changes to 1 true condition for the following loop
    }
    if(prefix==1)
        cout<<"prefix"<<endl;
}

int main()
{
    vector<int> vec1,vec2;
    cout<<"enter vector 1: "<<endl;
    input(vec1);
    cout<<"enter vector 2: "<<endl;
    input(vec2);

    prefix(vec1,vec2);


return 0;
}
