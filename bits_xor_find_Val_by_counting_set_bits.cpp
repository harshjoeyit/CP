 
// XOR - problemd
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

        for(int j=0;j<20;j++){
            if(a[i]&(1<<j)){
                cnt[j]++;
            }
        }
    }

    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;

        for(int i=0;i<20;i++){
            if(x&(1<<i)){
                cnt[i]=(n-cnt[i]);
            }
        }

        ans=0;

        //  cnt[i] - count of bits at i;
        // to calculate value this array corresponds
        // if ith bit - has[i] -that means (1 << i) must be added has[i] times
        // has[] - [0, 3, 1, 2]
        // val =  0*(1) + 3*(2) + 1*(4) + 2*(8)

        for(int i=0;i<20;i++){
            ans+=cnt[i]*(1<<i);
        }
        printf("%lld\n",ans);
    }   
}