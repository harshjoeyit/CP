#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int h = 0;
    int l = 1, r = 2;
    while(1)
    {
        if(l <= n && n < r)
            break;
        l = l*2;
        r = r*2;
        ++h;
    }

    cout << h << endl;
}