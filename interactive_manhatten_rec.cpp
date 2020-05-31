#include<bits/stdc++.h>
using namespace std;

#define int long long int 

// MANREC- codechef
// manhatten rectangle - interactive

signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int x1, x2, y1, y2, r1, r2, r3, r4, u = 1e9;
        
        printf("Q %d %d\n",0,0);
        fflush(stdout);
        scanf("%lld", &r1);
        
        printf("Q %lld %d\n",u,0);
        fflush(stdout);
        scanf("%lld", &r2);
        
        printf("Q %lld %d\n",(r1-r2+u)/2, 0);
        fflush(stdout);
        scanf("%lld", &r3);

        printf("Q %d %lld\n",0, u);
        fflush(stdout);
        scanf("%lld", &r4);

        y1 = r3;
        x1 = r1 - y1;
        x2 = u + y1 - r2;
        y2 = x1 + u - r4;

        printf("A %lld %lld %lld %lld\n",x1, y1, x2, y2);
        fflush(stdout);
        scanf("%lld", &u);   

        if(u < 0)
            exit(0);     
    }    
}