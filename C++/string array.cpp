#include<iostream>
#include<cctype>
#include<string>
#include<cstring>
using namespace std;

// IMPORTANT - string array is passed by reference by default
void process(string b[])
{
   for(int i=0; i<3; i++)
   {
      auto sit=b[i].begin();
      auto sit2=b[i].end();
      while(sit!=sit2)
      {
          *sit=toupper(*sit);
          sit++;
      }
   }
}
void output(string b[])
{
    for(int i=0; i<3; i++)
        cout<<b[i];
}

int main()
{
    string a[]={"Joey","Chandler","Ross"};
    output(a);
    cout<<endl;
    process(a);
    output(a);
    cout<<endl;

    cout<<a[0]<<a[1]<<a[2];
    cout<<endl;

    char s[]={'a','b','c'};
    char s1[]="abc";
    int i=0;
    while( i!=3)
    {
        cout<<s[3]<<" "<<s1[3]<<endl;  // s[3] prints a garbage value is s[3 does not exit
        i++;                            // s1[3] prints any value since it is null character
                                       // s1[3] appear as spaces
    }
    cout<<endl<<s1[0]<<s1[3]<<s1[1]<<s1[3]<<s1[2];
    cout<<endl<<s[0]<<s[3]<<s[1]<<s[3]<<s[2];
return 0;
}
