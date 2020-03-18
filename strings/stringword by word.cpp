#include<iostream>
#include <string>
#include<cctype> // equivalent to <ctype.h> in C
using namespace std;

void stringfn(string s2)
{
                   // string s3=" "  <------   wrong
    char s3=' ';   // must use the char variable sincwe you cannot compare a string to a char

    for(unsigned int i=0;i<s2.size();i++)
    {
        if (s2[i]==s3)          //s2[i] has a type char it must be compared to character
            cout<<endl;
        else
            cout<<s2[i];
    }
}

int main()
{

string s1("time to go");
stringfn(s1);

cout<<endl<<s1.at(3)<<" "<<s1.at(5)<<endl;  // print without using a loop

/*for (auto &c:s1) // for every char in str
c=toupper(c);
cout << c << endl; */ // print the current character followed by a newline


string s2("time_to \n #cccccc ;;?  &go");
cout<<endl;

for(int i=0;i<s2.size();i++)

if(isgraph(s2[i]))
               // does not read spaces
cout<<s2[i];

cout<<endl;

for(int i=0;i<s2.size();i++)

if(isprint(s2[i]))

cout<<s2[i];

cout<<endl;

for(int i=0;i<s2.size();i++)

if(isxdigit(s2[i]))  // prints hexadecimal digits

cout<<s2[i];

cout<<endl;

for(int i=0;i<s2.size();i++)

if(ispunct(s2[i]))

cout<<s2[i];



return 0;
}
