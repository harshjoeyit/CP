#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    for(int i=32; i<255; i++)  // 32 is space character: " "
       {
          char ch= i;
          cout<<i<<" = "<<ch<<endl;
       }

       char ch =48;      // 0-9 start from 48
       cout<<endl<<ch;

}
