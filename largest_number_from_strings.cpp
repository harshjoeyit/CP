// maximum value lexiographically for an array of string of number 

#include<bits/stdc++.h>
using namespace std;

bool util_bool(string a, string b)
{
    // normal string comp
    for(int i = 0; i < a.length(); i++)
    {
        if(a[i] < b[i])
            return false;

        if(a[i] > b[i])
            return true;
    }

    // all char of smaller string are same as larger string, then 
    if(a.length() < b.length())                             
    {
        for(int i = a.length(); i < b.length(); i++)
        {    if(a[a.length()-1] < b[i])
                return false;

            else if(a[a.length()-1] > b[i])
                return true;
        }
    }

    return true;        
}


bool comp(string a, string b)
{
    if(a.length() <= b.length())
        return util_bool(a, b);

    return ! util_bool(b,a);
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