#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e6;
int isprime[mxN];
int fpf[mxN];

vector<int>divisors(int n) { 
    vector<int> divs;   
    for (int i=1; i<=sqrt(n); i++) { 
        if (n % i == 0) { 
            if (n / i == i) {
                divs.push_back(i);
            } else {
                divs.push_back(i);
                divs.push_back(n / i);
            } 
        } 
    } 
    return divs;
} 
 
int count_divisors(int n) {
    if(n == 1) {
        return 1;
    }
    int cnt = 0;
    for(int i=1; i*i<=n; i++) {
        if(n%i == 0) {
            if(i == n/i) {
                ++cnt;
            } else {
                cnt += 2;
            } 
        }
    }
    return cnt;
}

// fpf[i] = smallest prime factor of i
void seive() {
      for (int i = 2; i < mxN; i++) {
            isprime[i] = 1;
      }
      for (int i = 2; i * i < mxN; i++) {
            if(isprime[i] == 1) {
                  fpf[i] = i;
                  for (int j = i * i; j < mxN; j += i) {
                        fpf[j] = i;
                        isprime[j] = 0;
                  }
            }
      }
      for (int i = 2; i <= 100; i++) {
            cout <<i << " "<< fpf[i] << "\n";
      }
      cout << endl;
}

int main() {
    
}