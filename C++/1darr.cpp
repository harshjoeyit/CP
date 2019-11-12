#include<iostream>
using namespace std;

int main()
{
    int s[5],max1=0,i=0;

    cout<<"enter";
    for(i=0;i<5;i++)
    {
        cin>>s[i];
    }
    i=0;
    for(int j=0;i<5;i++)
    {
        if(s[i]>max1)
            max1=s[i];
    }
    cout<<" \n max= "<<max1;
    return 0;
}
