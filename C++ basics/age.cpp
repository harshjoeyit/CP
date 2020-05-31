#include<iostream>
using namespace std;

int main()
{
    int Age;
    cout<<"Enter Your Age: "<<endl;
    cin>>Age;

    if(Age<18)
        cout<<"You can not VOTE";
    else
        cout<<"You can VOTE";

    return 0;
}

