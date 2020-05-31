
// coins are in denomination 1, 2, 5, 10
// quantity of each is given A, B, C, D   - are no of coins of each type
// money amount = N
// find total ways of making n

// brute force 

for(a=0; a<=A; a++)
            for(b=0; b<=B; b++)
                for(c=0; c<=C; c++)
                    for(d=0; d<=D; d++)
                        if((a+(b*2)+(c*5)+(d*10)) == N)
                            ans ++;

// optimization 1

for(a=0; a<=A && a<=N; a++)
    for(b=0; b<=B && a+b*2<=N; b++)
        for(c=0; c<=C && a+b*2+c*5<=N; c++)
            for(d=0; d<=D && a+b*2+c*5+d*10<=N; d++)
                if((a+(b*2)+(c*5)+(d*10)) == N)
                    ans ++;

/// optimization 2

for(b=0; b<=B && b*2<=(N); b++)
    for(c=0; c<=C && b*2+c*5<=(N); c++)
        for(d=0; d<=D && b*2+c*5+d*10<=(N); d++)
            if(((b*2)+(c*5)+(d*10)) >= (N-A))
                ans ++;

// opmt 3 

for(b=0; b<=B && b*2<=N; b++)
    for(a=0; a<=A && a+b*2<=N; a++)
        ways[a+b*2]++;                  // counting ways 

for(c=0; c<=C && c*5<=(N); c++)
    for(d=0; d<=D && c*5+d*10<=(N); d++)
        ans+= ways[N-c*5-d*10];         // adding those ways 
                // = a + b*2