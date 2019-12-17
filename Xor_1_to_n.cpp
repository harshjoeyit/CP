#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;


// Direct XOR of all numbers from 1 to n 
int computeXOR(int n) 
{ 
    if (n % 4 == 0) 
        return n; 
    if (n % 4 == 1) 
        return 1; 
    if (n % 4 == 2) 
        return n + 1; 
    else                // rem = 3
        return 0; 
} 

int main()
{
    cout << computeXOR(4) << endl;
}