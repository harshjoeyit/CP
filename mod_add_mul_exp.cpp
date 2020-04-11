#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

inline int mul(int a,int b){
    a=(a+MOD)%MOD;
    b=(b+MOD)%MOD;
    int c=a*b;
    c=(c+MOD)%MOD;
    return c;
}
inline int add(int a,int b){
    a=(a+MOD)%MOD;
    b=(b+MOD)%MOD;
    int ans=(a+b);
    ans=(ans+MOD)%MOD;
    return ans;
}
int power(int a,int b,int c=0){
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

int main() {
    cout << power(2, 4);
}