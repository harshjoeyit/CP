#include<iostream>
#include<string>
using namespace std;
int main()
{

    string one;
    string two;
    string three;
    string four;
    string total;
    string sub;
    int l,n=3;

    cout<<"start inputting values \n";
    cin>>one>>two>>three;
    cout<<one<<endl<<two<<endl<<three<<endl;
    total = one + two + three;
    cout<<total<<endl;

    l=total.length();
    cout<<l<<endl;
    sub= total.substr(0,6);
    cout<<"\n"<<sub;

    while(n>0)
    {
        cin>>four;
        cout<<four<<endl;

    }


    return 0;

}
