#include<iostream>
using namespace std;

void error_msg(initializer_list<string> il)  // a large number of arguments of same data type can be passed using an initializer list
{
/*for (auto beg = il.begin(); beg != il.end(); ++beg)
cout << *beg << " " ;
cout << endl;*/

for (const auto &out: il)
    cout << out << " " ;
cout << endl;
}

void error_msg(initializer_list<int> il)
{
    auto beg= il.begin();
    auto sum= *beg++ + *beg;
    cout<<endl<<"sum = "<<sum;
}

int main()
{
    string expected,actual;
    cout<<"enter the strings: "<<endl;
    cin>>expected>>actual;

    if (expected != actual)
        error_msg({ expected,"- is not same as -", actual});
    else
        error_msg({"same-o", "okay"});

    int a,b;
    cout<<"enter the int vars: "<<endl;
    cin>>a>>b;
    // add using initializer list
        error_msg({a,b});

return 0;
}
