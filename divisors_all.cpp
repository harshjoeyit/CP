#include<bits/stdc++.h>
using namespace std;

void printDivisors(int n) 
{ 
    // Note that this loop runs till square root 
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            // If divisors are equal, print only one 
            if (n/i == i) 
                printf("%d ", i); 
  
            else // Otherwise print both 
                printf("%d %d ", i, n/i); 
        } 
    } 
} 
 

int main()
{
    printDivisors(10); cout << endl;
    printDivisors(1);   cout << endl;
    printDivisors(23);  cout << endl;
    printDivisors(625);  cout << endl;
}