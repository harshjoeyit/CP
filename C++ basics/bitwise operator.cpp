#include<iostream>
using namespace std;


main()
{
    unsigned long a=0;
    unsigned long b=0;
    1UL << 27;
     a |= 1UL<<27;  // prints 1
     b |= 1UL<<27;
      bool x=a&b;
     cout<<x<<endl;  // prints 1
     cout<<b<<endl;  // prints 2^27

     b &= ~(1UL << 27);// bit turned off
     cout<<b<<endl;

     unsigned long u1 =5;
     unsigned long u2 =4;

     auto y= u1&&u2;// returns a bool
     // prints zero only if one of the operand is zero otherwise 1
     cout<<y<<endl;

     unsigned int in =7;
     auto po= ~in<<4;

     cout<<po<<endl;

}
