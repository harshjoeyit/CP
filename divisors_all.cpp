#include<bits/stdc++.h>
using namespace std;

void print(vector<int> divs) {
    for(auto div: divs) {
        cout << div << " ";
    }cout << endl;
}

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

int main() {
    cout << count_divisors(10) << ": ";
   print(divisors(10)); cout << endl;
    cout << count_divisors(12) << ": ";
   print(divisors(12));   cout << endl;
    cout << count_divisors(25) << ": ";
   print(divisors(25));  cout << endl;
    cout << count_divisors(36) << ": ";
   print(divisors(36));  cout << endl;
    cout << count_divisors(56) << ": ";
   print(divisors(12));  cout << endl;
}