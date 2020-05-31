#include<bits/stdc++.h>
using namespace std;

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

int main() {
    string s = "i am a lover boy "; 

    // dont worry function is called only once
    for(auto x: split_str(s)) {
        cout << x << endl;
    }
}