#include<bits/stdc++.h>
using namespace std;


vector<long long int>& fib(long long int n , vector<long long int>& fibvec) 
{
    fibvec[0] = 0;
    fibvec[1] = 1;

    for(long long int i = 2; i < n+1; i++ )
        fibvec[i] = fibvec[i-1] + fibvec[i-2];

    return fibvec;
}

int main()
{
    vector<long long int> fibvec(10000000, 0);
    long long int n = 20;
    fib(n, fibvec);

    for(long long int i = 0; i<n+1; i++ )
        cout << fibvec[i] << " ";
}