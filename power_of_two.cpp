#include<bits/stdc++.h>
using namespace std;



int main()
{
    int n;
    cin >> n;

    while(n > 1)
    {
        if( (n & 1) == 0)
            n = n >> 1;
        else
            break;
    }

    if(n > 1)
        cout << "not" << endl;
    else
        cout << "power" << endl;
}