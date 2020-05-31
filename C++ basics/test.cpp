#include<iostream>
using namespace std;

int main()
{

    long double fir;
    cout<<" enter first term: ";
    cin>>fir;

    long double sec;
    cout<<"enter the second term: ";
    cin>>sec;

    cout<<"type ' enter ' to type no of terms if known \ntype 'findnow' to calculate it"<<endl;
    long double terms;
    string ukn;
    cin>>ukn;
    if(ukn=="enter")
    {
        cout<<" enter the known no. of terms: ";
        cin>>terms;
    }

    else if(ukn=="findnow")
    {
        long double last;
        cout<<"enter the last term: ";
        cin>>last;

        int c=0;
        if(fir==1)
        {
            while((last/sec) !=1)
                ++c;
        }
        else
        {
            while((last/fir) > 1)
                ++c;
        }
        terms=c;
        cout<<endl<<c;
    }

}
