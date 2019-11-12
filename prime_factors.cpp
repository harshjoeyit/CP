#include<bits/stdc++.h>
using namespace std;

vector<int> factorize(int n) 
{
    vector<int> res;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {                // loop fo checking the repeated factors 
            res.push_back(i);
            n /= i;                         
        }
    }
    if (n != 1) {
      res.push_back(n);
    }
    return res;
}


int divisors(int n) 
{
    map<int, int> freq;
    
    for (int i = 2; i * i <= n; ++i) 
        while (n % i == 0) 
        {                // loop fo checking the repeated factors 
            ++freq[i];
            n /= i;                         
        }
    if (n != 1) 
        ++freq[n];

    int d = 1;
    for(auto it = freq.begin(); it != freq.end(); it++ )
        d *= (it->second + 1);

    return d;  
}


int main()
{
    int x = 36;
    vector<int> v = factorize(x);
    cout<<"prime factors: ";
    for( auto x: v)
        cout<<x<<" ";
    cout<<endl;
    cout << "divisors: " << divisors(x) << endl;
}

