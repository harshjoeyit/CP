#include<bits/stdc++.h>
using namespace std;

// function returns the maximum number as power of two which is less than the number supplied
long long int maxp2(long long int N)
{
    int j = 1;
    int count = 1;
    while(count < 64)           // for 64 bits maximum
    {
        N = N | (N >> j);       // OR with sifted bits
        j = j * 2;              // shift 2 bits next time
        count = count + j;
    }
    // N = 11111111111.......
    cout << N << endl;
    // return 100000000.....
    return ((N + 1) >> 1);
}

int main()
{
    int n;
    cin >> n;
    cout << maxp2(n) << endl;
}