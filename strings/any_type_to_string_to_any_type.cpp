
/*
    conversion of strings
    stringstream can be used to convert from typeA to typeB
    
    write typeA to stringstream
    ss << typeA 
    
    read the value as typeB from stringstream
    ss << typeB
*/


#include<bits/stdc++.h>
using namespace std;

template<typename T>
string toString(T i) {
    stringstream ss;
    ss << i;
    // ss has a method that directly returns the content as string
    return ss.str();
    // ALITER 
    // string str; 
    // s >> str;
    // return str;
}

float toFloat(string s) {
    stringstream ss;
    ss << s;
    float f;
    ss >> f;
    return f;
}

int main() {
    float f = 150.50;
    string s = toString(f);
    cout << s + "5555555" << endl;

    f = toFloat(s);
    cout << f+ 25.353 << endl;
}
