#include<iostream>
#include<vector>
#include<string>
#include<cctype>
using namespace std;

int main()
{
    string str("This Is Sample Text");
    for(int index=0; index<str.size(); ++index)
    {
     if(!isspace(str[index]))
        str[index]=toupper(str[index]);

        cout<<str[index];
    }
    cout<<endl;
for(unsigned int index=0; index<str.size(); ++index)
    {
     if (isalpha(str[index]))
         str[index]=tolower(str[index]);
         cout<<str[index];
    }
   cout<<endl;

    string s("string type");
    for (unsigned int i = 0; i != s.size() && !isspace(s[i]); ++i)
        s[i] = toupper(s[i]); // capitalize the current character
        cout<<s<<<endl;

    const string strin("Keep Out !");
    for (auto c : strin)
        {
            cout<<c;
        }

 // vector string

    vector<string> vstr{"harshit","gangwar","is","a nice guy"};
    vector<string>::iterator it;

    it=vstr.begin();
    while(it!=vstr.end())
    {
        for(auto s: *it++)
        {
            s=toupper(s);
            cout<<s;
        }
        cout<<" ";
    }




return 0;
}
