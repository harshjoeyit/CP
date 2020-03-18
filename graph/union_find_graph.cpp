#include <stdio.h>
#include <string.h>

int parent[1000000],rank[1000000];
int u[1000000],v[1000000];
char oprtr[100000][2];

int find(int x)
{
    while(parent[x] != x)
    {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}


void unionSet(int x,int y)
{
    int xRoot = find(x);
    int yRoot = find(y);

    if(xRoot == yRoot)
        return;

    if(rank[xRoot] > rank[yRoot])
        parent[yRoot] = xRoot;

    else if(rank[xRoot] < rank[yRoot])
        parent[xRoot] = yRoot;

    else
    {
        parent[yRoot] = xRoot;
        rank[xRoot]++;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k,i,j,flag = 0;
        scanf("%d %d",&n,&k);

        for(i=1;i<=n;i++)
            parent[i] = i;

        for(i=0;i<1000000;i++)
            rank[i] = 0;

        for(i=0;i<k;i++)
        {
            scanf("%d %s %d",&u[i],&oprtr[i],&v[i]);
            if(oprtr[i][0] == '=')
                unionSet(u[i],v[i]);
        }

        for(i=0; i<k; i++)
        {
            if(oprtr[i][0] == '=')
                continue;
            else
            {
                if(find(u[i]) == find(v[i]))
                {
                    flag = 1;
                }
            }
        }
        if(flag == 0)
            printf("YES\n");
        else if(flag == 1)
            printf("NO\n");
    }
    return 0;
}