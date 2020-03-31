#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e6+10;
vector<pair<int, int>> divs[mxN + 7];               // divs - pairs of {prime factor, its power}
                                                    // eg. divs[12] --> {2, 2}, {3, 1}

void sieve(int n) {
	for(int i = 2; i <= n; i++) {
	    if(divs[i].size()) 
            continue;
	    for(int j = i; j <= n; j += i) 
            divs[j].push_back({i, 0});
	}

	for(int i = 2; i <= n; i++) {                       
	    for(int j = 0; j < divs[i].size(); j++) {
	        int cur = divs[i][j].first;
	        int cnt = 0, val = i;
	        while(val % cur == 0) 
                val = val / cur, cnt++;
	        divs[i][j].second = cnt;
	    }
	}
}

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

