#include<iostream>
using namespace std;

int main()
{
     int *p;
     cout<<p<<endl<<*p<<endl;
     int i = 42;
     int &m= i;
     m=2;
     cout<<i<<endl<<m<<endl;

     int *p1 = &i;
    *p1 = *p1 * *p1;
      cout<<i<<endl;

      if(p1)
        cout<<"opt"<<endl;
      if(*p1)
        cout<<"opt2"<<endl;


2
return 0;
}
