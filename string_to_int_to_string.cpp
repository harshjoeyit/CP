#include<bits/stdc++.h>
using namespace std;

// string to number and number to string 
int main()
{
    double d = -42.8126;
    //converts integer or floating point values to string 
    string s = to_string(d);
    cout<<"string: "<<s<<endl;

    //stod() // function 
    d = stod(s);
    cout<<"string to double: "<<d<<endl;

    // stoi(i) function 
    cout<<"string to int: "<<stoi(s)<<endl;

    string str = "3254 with words ";  // can be converted
   // string str1 = "words with 3453";  , cannot be converted
    cout<<"string to int: "<<stoi("123456789")<<endl;

    string s2 = "pi = 3.14";

    cout<<to_string(12345678999) + "hihi";

    // solution for the str1 case 
    d = stod(s2.substr(s2.find_first_of("+-.0123456789")));
    cout<<"to double"<<d<<endl;

    // if the string cannot be converted into the int then an exception is thrown 
    string S = "klkl";
    cout<<"S to int : "<<stoi(S)<<endl;
}

