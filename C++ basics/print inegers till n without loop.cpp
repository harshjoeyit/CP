#include<iostream>
#include<vector>
using namespace std;

void print(int n,int m)
{
    if(n!=0)
    {
        cout<<m-n+1;
        n--;
        print(n,m);
    }
}

main()
{
    int num;
    cout<<"enter: ";
    cin>>num;
    print(num,num);
}
