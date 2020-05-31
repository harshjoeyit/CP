#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool neg = false;

    if(n < 0)
        neg = true;

    n = abs(n);

    int i = 10;
    int m = 0;

    while(n > 0)
    {
        int last_dig = n % 10;
        m = m * i + last_dig;
        n = n / 10;
    }

    if(neg)
        cout << -m << endl;
    else
        cout << m << endl;
}