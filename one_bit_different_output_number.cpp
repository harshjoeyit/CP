#include<bits/stdc++.h>
using namespace std;


int binaryToDecimal(long long int binary)
{
    int decimal = 0, bit;
    for(int i = 0; binary != 0; i++ )
    {
        bit = binary % 10;
        decimal +=  bit * pow(2, i);
        binary = binary / 10;
    }
    return decimal;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long int n, y, i = 1;
        cin >> n;
        y = n;

        while(1)
        {
            if(y % 2 == 0)
                break;
            else
            {
                i = i * 10;
                y = y / 2;   
            }
        }
        i = binaryToDecimal(i);
        cout << i+n << endl;
    }
}