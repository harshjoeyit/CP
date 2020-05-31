#include<bits/stdc++.h>
using namespace std;

int main()
{
    int l = 1, h = 1000000, mid;
    char resp[5];

    while(l != h)
    {
        mid = (l+h+1)/2;

        printf("%d\n", mid);
        fflush(stdout);

        scanf("%s", resp);

        if(strcmp(resp, "<") == 0)
            h = mid - 1;
        else
            l = mid;
    }
    printf("! %d\n", l);
    fflush(stdout);
}