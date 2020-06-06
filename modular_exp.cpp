#include<iostream>
using namespace std;
#define int long long int
const int mod = 1e9+7;

// ...............................................................
int modEx(int x, int n) {
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return modEx((x*x) % mod, n/2);
    else
        return (x*modEx( (x*x) % mod, (n-1)/2)) % mod;
}

// ................................................................
int invMod(int x) {
    return modEx(x, mod-2);
}
// ................................................................
int power(int x, unsigned int y) { 
    int res = 1;    
    while (y > 0) { 
        if (y & 1) {
            res = res*x;
        } 
        y = y >> 1;  
        x = x * x;  
    } 
    return res; 
}

// .........................................................
inline int mul(int a,int b){
    a=(a+mod)%mod;
    b=(b+mod)%mod;
    int c=a*b;
    c=(c+mod)%mod;
    return c;
}
inline int add(int a,int b){
    a=(a+mod)%mod;
    b=(b+mod)%mod;
    int ans=(a+b);
    ans=(ans+mod)%mod;
    return ans;
}
int power2(int a,int b,int c=0){
    int ans=1;
    while(b){
        if(b&1){
            ans=mul(ans,a);
        }
        a=mul(a,a);
        b=b/2;
    }
    return ans;
}

// ..................................................................
signed main() {
    cout << power(5, 9)%13 << endl;
    cout << modEx(5, 9) << endl;
    cout << power2(5, 9) << endl;
}