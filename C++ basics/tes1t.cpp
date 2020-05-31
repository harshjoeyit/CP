// CPP program to illustrate
// Different methods to find length
// of a string
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
    // String obj
    string str;
    cin>>str;

    // 1. size of string object using size() method
    cout << str.size() << endl;

    // 2. size of string object using length method
    cout << str.length() << endl;

    // 3. size using old style
    // size of string object using strlen function
    cout << strlen(str.c_str()) << endl;

    // The constructor of string will set it to the C-style string,
    // which ends at the '\0'

    // 4. size of string object Using while loop
    int i = 0;
    while (str[i] != '\0')
    {
        ++i;
    }
    cout << i << endl;

    // 5. size of string object using for loop
    for (i=0; str[i]!='\0'; i++)
    {
    }
    cout << i << endl;

return 0;
}
