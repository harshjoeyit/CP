#include<iostream>
using namespace std;
int main()
{
    int i=5;
    unsigned s;
    s=5;
    cout<<s<<endl;
    cout<< i-s<<endl;

   if(i)
    {
        cout<<"value change \n";
        i=0;
    }
    if(i)
    {
        cout<<"value change";
    }
    else
    {
     cout<<"worked \n";
    }
    return 0;
}


