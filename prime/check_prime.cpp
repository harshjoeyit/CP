#include<bits/stdc++.h>
using namespace std;
#define int long long

// O(sqrt(n))
bool isPrime(int N) {
    int count = 0;
    for(int i=2; i*i <=N;++i) {
        if( N % i == 0) {
            ++count;
        }
    }
    return ((count==0) ? 1: 0);
}

int main( ) 
{
    cout << isPrime(15);
}
