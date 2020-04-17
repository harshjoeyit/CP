
// IMP: PIR
// maximum value lexiographically for an array of string of number 

#include<bits/stdc++.h>
using namespace std;


bool util_bool(string a, string b) {
    int l1 = a.length();                // for this function l1 <= l2
    int l2 = b.length();

    // normal string comp per char
    for(int i = 0; i < l1; i++) {
        if(a[i] < b[i])
            return false;

        if(a[i] > b[i])
            return true;
    }

                                        // all char of smaller string are same as larger string, then 
    if(l1 < l2) {
        for(int i = l1; i < l2; i++)
        {    if(a[l1-1] < b[i])
                return false;

            else if(a[l1-1] > b[i])
                return true;
        }
    }
                                        // if both strings are exactly same or are of form 856, 85666666, 85666
    return true;        
}


bool comp(string a, string b) {
    if(a.length() <= b.length())
        return util_bool(a, b);

    return ! util_bool(b, a);            // opposite result as now a = b and b = a
}


// IMP: short and nice
bool comp(string &s1, string &s2) {
    string t1 = s1+s2;
    string t2 = s2+s1;
    if(stoi(t1) > stoi(t2))
        return 1;
    return 0;
}


int main()
{
    vector<string> svec = { "44426", "44", "4", "425", "44456", "444445", "4441"};
    vector<string> s = {"989", "9", "90", "991", "921", "901"};

    sort(svec.begin(), svec.end(), comp);

    for(auto &x: svec)
        cout << x << " ";
    cout << endl;


    sort(s.begin(), s.end(), comp);

    for(auto &x: s)
        cout << x << " ";
    cout << endl;

    // make 
}