// The awkwardness of this configuration of students
// is defined as the sum of pairwise distances between
// each boy and girl. The distance between the i-th and
// j-th student in the line is |i−j|. Formainty, the awkwardness is

// summation(1 to n (summation(i+1 to n)(j-i)))
                            // s[i] != s[j]
// ith and jth items are different 


#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        int size = str.size();
        int cb = 0;
        int cg = 0;

        for (int i = 0; i < size; i++) {
            if(str[i]=='g')
                cg++;
            else
                cb++;
        }

        if(cg<cb) {
            swap(cg, cb);
        }

        str = "";
        int temp = cg-cb;
        int temp1 = temp/2;
        int temp2 = temp-temp1;
        
        for(int i=0;i<temp1;i++)
            str += "g";
        for(int i=0;i<cb;i++)
            str += "gb";
        for(int i=0;i<temp2;i++)
            str += "g";

        int ans = 0;
        int Nb = 0;
        int Ng = 0;

        for (int i = 0; i < size; i++) {
            if(str[i]=='g') {
                ans += i*Nb - i*(cb-Nb);
                Ng++;
            } else {
                ans += i*Ng - i*(cg-Ng);
                Nb++;
            }
        }
        cout << ans << "\n";
    }
}