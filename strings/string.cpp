#include<iostream>
#include <string>
using namespace std;

void stringfn(string s2)
{
    char s3=' ';

    for(unsigned int i=0;i<s2.size();i++)
    {
        if (s2[i]==s3)
            cout<<endl;
        else
            cout<<s2[i];
    }
}

int main()
{

string s1("time to go");
stringfn(s1);


return 0;
}
