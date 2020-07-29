#include<bits/stdc++.h>
using namespace std;

// general for any delimiter like space comma etc
vector<string> split_str(string s) {
    vector<string> v;
    string delimiter = " ";
    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        v.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    return v;
}

// space seperated using stringstream
vector<string> split(string s) {
    vector<string> v;
    stringstream ss;
    // Alt: using constructor 
    // stringstream ss(s);
    ss << s;
    while(ss >> s) {
        v.push_back(s);
    }
    return v;
}

void forMultipleStrings() {
    
    /*
    for multiple strings
    stringstream ss;
    string s1 = "this is a nice place tp sit";
    ss << s1;
    string word;
    while(ss >> word) {
          cout << word << endl;
    }
    
    string s2 = "here i am again!";
    ss.clear();
    ss << s2;
    while(ss >> word) {
          cout << word << endl;
    }
    */
}

int main() {
    string s = "i am a lover boy "; 

    // IMP: function is called only once
    for(auto x: split_str(s)) {
        cout << x << endl;
    }
    cout << ".............................\n";
    for(auto x: split(s)) {
        cout << x << endl;
    }
}