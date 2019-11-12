
#include<iostream>
#include<math.h>
using namespace std;


main()
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

        int c=1;
        if(fir==1)
        {
            ++c;
            int div=last/sec;
            while(div>1)
                {
                    div=div/sec;
                    ++c;
                }
        }
        else
        {
            int div=last/fir;
            while(div > 1)
            {
                div=div/fir;
                ++c;
            }
        }
        terms=c;
    }

    long double sum=0;

    if(fir!=1)
    {
        for(int i=1; i<=terms; i++)
            sum += pow(fir,i);
    }

    if(fir==1)
    {
        for(int i=0; i<terms; i++)
            sum += pow(sec,i);
    }

    cout<<endl<<"sum of series: "<<sum;

}
