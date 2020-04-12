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
 
int count_divisors(int n) {
    if(n == 1)
        return 1;
    
    int cnt = 0;
    for(int i=1; i*i<=n; i++) {
        if(n%i == 0) {
            if(i == n/i)
                ++cnt;
            else 
                cnt +=2;            // for i, n/i
        }
    }
    return cnt;
}

int main()
{
    cout << count_divisors(10) << ": ";
    printDivisors(10); cout << endl;
    cout << count_divisors(12) << ": ";
    printDivisors(12);   cout << endl;
    cout << count_divisors(25) << ": ";
    printDivisors(25);  cout << endl;
    cout << count_divisors(36) << ": ";
    printDivisors(36);  cout << endl;
    cout << count_divisors(9383) << ": ";
    printDivisors(9383);  cout << endl;
}