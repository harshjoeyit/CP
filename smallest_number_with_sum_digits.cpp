
#include<bits/stdc++.h>
using namespace std;

 string smallestNumber(int S, int D){
    string s(D, '0');
    int i=D-1;
    while(i >= 0 && S > 0) {
        int dig = min(S, 9);
        S -= dig;
        s[i] = (char)('0' + dig);
        i--;
    }
    if(i == -1) {
        return s;
    }
    s[i+1] = (char)(s[i+1] - 1);
    s[0] = '1';
    return s;
}

int main() {
    cout << smallestNumber(9, 2);
}