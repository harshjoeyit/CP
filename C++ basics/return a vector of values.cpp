#include<iostream>
#include<vector>
using namespace std;

vector<string> names(string name)
{
    return{"gangwar","19","b.tech"};
}

int main()
{
    string name("harshit");
    vector<string> vstr;

    vstr=names(name);
    for(auto t = vstr.begin();  t != vstr.end();  t++)
        cout<<*t<<endl;
    return 0;
}
