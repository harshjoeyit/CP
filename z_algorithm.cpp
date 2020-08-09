#include<bits/stdc++.h>
using namespace std;

template <typename T>
void print(vector<T> v) {
    for(auto x: v)
        cout << x << " ";
    cout << endl;
}

// trivial z function takes 
// O(n^2) time
vector<int> z_function_trivial(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1; i < n; ++i)
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
    return z;
}

//efficient z function
// O(n) time
vector<int> z_function(string s)  {
    int n = (int) s.length();
    vector<int> z(n);
    
    for (int i=1, l=0, r=0; i<n; ++i)  {
        if (i <= r) {
            z[i] = min (r-i+1, z[i-l]);
        }       
        // segment should not stretch out of the array while copying previous values so (r-i+1)
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
            ++z[i];
        }
        // i + z[i] - 1 = rightmost index of the segment
        if (i+z[i]-1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

void count_unique_substrings(string s) {
    string temp;
    int ans = 0;
    for(int i=0; i<s.length(); i++) {
        temp = s.substr(0, i+1);
        reverse(temp.begin(), temp.end());
        auto pi = z_function(temp);
        int mx = *max_element(pi.begin(), pi.end());
        ans += temp.length() - mx;
    }
    cout << "number of different substring: ";
    cout << ans << endl;
}

int main() {
    // string pat, s;
    // cin >> s >> pat;
    // s = pat + '*' + s;

    // vector<int> z1 = z_function(s);
    // vector<int> z2 = z_function_trivial(s);
    // print(z1);
    // print(z2);

    // // printing the original indices in the string where the pattern match is found
    // for(int i = pat.length()+1; i < s.length(); i++)
    //     if(z1[i] == pat.length())
    //         cout << i - pat.length() - 1;
    // cout << endl;


    // string s;
    // cin >> s;
    // count_unique_substrings(s);

    /*   
    Compressing a string 
    A solution is: compute the Z-function of s, loop through all i such that i divides n. 
    Stop at the first i such that i+z[i]=n. Then, the string s can be compressed to the length i.
    */
}