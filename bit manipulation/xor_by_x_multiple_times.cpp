 
// XOR - problem
// https://www.hackerrank.com/contests/pir2/challenges/aayush-loves-xor

#include<bits/stdc++.h> 
using namespace std;
#define int long long int
#define ll long long int

int cnt[20];
int ans=0;
int a[1000005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];

        // cnt[j] - count of the jth bit 
        for(int j=0;j<20;j++){
            if(a[i] & (1 << j)){
                cnt[j]++;
            }
        }
    }

    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;

        // for input x we need to x^a[i] for all array elements 
        // for the bits that are set in x  x^a[i] will either 
        // set the bit if it is unset in a[i] and unset if it is set in a[i]
        for(int i=0; i<20; i++){
            if(x & (1 << i)){
                cnt[i] = (n - cnt[i]);              
                // if cnt[i] number of ith bit we set - now n-cnt[i] number of bits will be set due to xor         
            }
        }

        ans=0;
        // cnt[i] - count of bits at i;
        // to calculate value this array corresponds
        // if ith bit - has[i] -that means (1 << i) must be added cnt[i] times
        // cnt[] - [0, 3, 1, 2]
        // val =  0*(1) + 3*(2) + 1*(4) + 2*(8)

        for(int i=0;i<20;i++){
            ans += cnt[i] * (1 << i);
        }
        printf("%lld\n",ans);
    }   
}