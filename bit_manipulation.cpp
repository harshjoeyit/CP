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
    else
        return 0; 
} 

int main()
{
    cout << computeXOR(13) << endl;

    int x = 8;

    cout << "Number of leading zeroes in "<< x << " : " <<  __builtin_clz(x) << endl;
    cout << "Number of trailing zeroes in "<< x << " : " <<  __builtin_ctz(x) << endl;
    cout << "Number of 1- bits in "<< x << " : " <<  __builtin_popcount(x)  << endl;
  
}