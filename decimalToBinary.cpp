#include<bits/stdc++.h>
using namespace std;


vector<int> converted;

void decimalTo(int n, int x)
{
    if(n == 0)
        return;
    int rem = n % x;
    n = n / x;
    decimalTo(n, x);

    converted.push_back(rem);
}


int main()
{

    int number, radixBase;
    cout << "number: ";
    cin >> number;
    
    cout<<"Radix base: ";
    cin >> radixBase;

    decimalTo(number, radixBase);
    for(auto x: converted)
        cout << x ;
    cout << endl;
    
}