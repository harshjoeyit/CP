#include<bits/stdc++.h>
using namespace std;


/*
monk had n classsmates 
over time some of them became rivals , and some friends

m1 - friend relations 
m2- rivals relations 

Group of friends will be formed only by the given inputs. If given, A is a friend of B, 
B is a friend of C, 
then  A B C forms a friendship group, and you cannot pick a subgroup from it.

For example, if given A is a friend of B, 
and B is a friend of C then A and C are friends.


Two people are said to be enemies of each other, only and only if their enemy relation is given. For example, if given A is a enemy of B, and B is a enemy of C, 
\then A and C are not enemies of each other, unless it is given in the input.

(i.e you cannot use disjoint set union for enemy set)

There won't be any case, where both friend and enemy relation is given for two people.

*/

const int N = 100005;
int Arr[N];
int Size[N];

void initialize(int n)
{
    for(int i = 0; i <= n; i++)
    {
        Arr[ i ] = i ;
        Size[i] = 1;
    }
}


int root(int i)
{
    while(Arr[ i ] != i)
    {
        Arr[ i ] = Arr[ Arr[ i ] ] ;            // changing the parent to parent of parent
        i = Arr[ i ]; 
    }
    return i;
}


void Union(int u, int v)
{
    if(root(u) == root(v))
        return ;
    
    int rv = root(v);
    int ru = root(u);
    if(Arr[rv] < Arr[ru])         // by default the parent is the bigger number 
    {
        Arr[rv] = ru;
        Size[ru] += Size[rv];
        Size[rv] = 0; 
    }
    else
    {
        Arr[ru] = rv;
        Size[rv] += Size[ru];
        Size[ru] = 0; 
    }
}


int main()
{
    int n, m1, m2, u, v;
    cin >> n >> m1;

    initialize(n);

    while(m1--)
    {
        cin >> u >> v;        
        Union(u,v);
    }  

    // for(int i = 1; i <= n; i++)
    //     cout << Size[i] << " ";
    // cout << endl;

    cin >> m2;

    while(m2--)
    {
        cin >> u >> v;
        int ru = root(u);
        int rv = root(v);

        if(ru == rv)
            Size[rv] = 0;

    }

    // for(int i = 1; i <= n; i++)
    //     cout << Size[i] << " ";
    // cout << endl;

    int Max = -1;
    for(int i = 1; i <= n; i++)
        if(Size[i] > Max)
            Max = Size[i];

    cout << Max << endl;
}