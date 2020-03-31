#include<iostream>
using namespace std;

// complexity = O(log n)
int modEx(int x, int n, int M)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return modEx((x*x)%M, n/2, M);
    else
        return (x*modEx( (x*x)%M, (n-1)/2, M)) % M;
}


// complexity of the problem = O(log y)
int power(int x, unsigned int y) 
{ 
    int res = 1;     // Initialize result 
   
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = res*x; 
   
        // n must be even now 
        y = y>>1; // y = y/2 
        x = x*x;  // Change x to x^2 
    } 
    return res; 
}

typedef long long ll;

ll mulmod(ll a, ll b, ll mod) 
{ typedef long long ll;

    ll res = 0; // Initialize result 
    a = a % mod; 
    while (b > 0) 
    { 
        // If b is odd, add 'a' to result 
        if (b % 2 == 1) 
            res = (res + a) % mod; 
  
        // Multiply 'a' with 2 
        a = (a * 2) % mod; 
  
        // Divide b by 2 
        b /= 2; 
    } 
  
    // Return result 
    return res % mod; 
} 

int main()
{
    cout<<power(5, 9)%13<<endl;
    cout<<modEx(5, 9, 13)<<endl;
    cout<<mulmod(987,654,540)<<endl;
    cout<<(987*654)%540<<endl;
}