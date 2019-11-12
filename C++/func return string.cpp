#include<iostream>
#include<string>
using namespace std;

void testing()
{
    cout<<"test st 1";
    return ;
    cout<<endl<<"test st 2";
}

int retint(char ch)    // while returning the type is converted to an int (corresponding ASCII value)
{
    return ch;
}

char retch(int in)    // while returning the type is converted to an int (corresponding ASCII value)
{
    return in;
}

string uppercase(string s1,string s2)  //ASCII value is converted to the char type :
{
    if(isupper(s1[0]))
        return s1;
    else
    if(isupper(s2[0]))
        return s2;
    else
        return("none");
}
int main()
{
    testing();
    cout<<endl<<"ended";

    string name1, name2;
    cout<<endl<<"enter the names: "<<endl;
    cin>>name1>>name2;
    cout<<uppercase(name1, name2);

    char ch;
    cout<<endl<<"char: ";
    cin>>ch;
    cout<<"int of char : "<<retint(ch);

    int in;
    cout<<endl<<"char: ";
    cin>>in;
    cout<<"char of int : "<<retch(in);

    return 0;
}
