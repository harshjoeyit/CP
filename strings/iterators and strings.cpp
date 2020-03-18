// iterators on strings

#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main()
{
    string s;
    cout<<"enter the string : ";
    getline(cin,s);

    auto iterb= s.begin();
    auto itere= s.end();

    cout<<"size of iterb and itere :  "<<sizeof(iterb)<<" , "<<sizeof(itere)<<endl;

    if (iterb==itere)
        cout<<"string is empty"<<endl;
    else
    {
        for(auto x=iterb; x<itere; x++)     //method1 to use iterators
            cout<<*x;
        cout<<endl;

        for(auto x=iterb; x<itere; x++)     //process
            *x=toupper(*x);

        while(iterb != itere)               // method 2 to use iterators
        {
            cout<<*(iterb++);   // similar to
        }                       // cout<<*iterb
          //cannot dereference  // itere ++;
          // cout<<*itere;
    }
return 0;
}
