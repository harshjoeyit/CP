#include<iostream>
using namespace std;

int main()
{
    int n;
    char ans;

    start:
        cout<<"enter a number: ";
        cin>>n;
    if(n%2==0)
        cout<<n<<" : even"<<endl;
    else
        cout<<n<<" : odd "<<endl;

    cout<<"type n, no ,N to exit : ";
    cin>>ans;

    if(ans=='n' || ans=='N' || ans=='no')
        goto start;
    else
        return 0;
}
