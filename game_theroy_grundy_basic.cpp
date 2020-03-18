/*
The game starts with 3 piles having 3, 4 and 5 stones, 
and the player to move may take any 
positive number of stones upto 3 only from any of the piles 
[Provided that the pile has that much amount of stones]. 
The last player to move wins. 
Which player wins the game assuming that both 
players play optimally?
*/


/*
    ....................Variations of Nim .............................
    1.  Simple N poles Nim 
    2.  N poles Nim with players can remove or put coins on the stack
    3.  An array is given (values are probably repeating) find ways first person can pick any number of similar values and win the game 
        here similar values are coins on same stack, and number of distinct values are total number of stacks
        we have to find winning ways of player that starts 
*/

#include<bits/stdc++.h> 
using namespace std;

#define int long long int 
#define P1 1
#define P2 2

int calculateMex(unordered_set<int> Set) 
{ 
    int Mex = 0; 
  
    while (Set.find(Mex) != Set.end()) 
        Mex++; 
  
    return (Mex); 
} 

int calculateGrundy(int n, int Grundy[])
{
    Grundy[0] = 0;
    Grundy[1] = 1;
    Grundy[2] = 2;
    Grundy[3] = 3;

    if(Grundy[n] != -1)
        return (Grundy[n]);

    unordered_set<int> Set;
    for(int i = 1; i <= 3; i++)
        Set.insert(calculateGrundy(n-i, Grundy));

    Grundy[n] = calculateMex(Set);
    return (Grundy[n]);
}

void declareWinner(int whoseTurn, int piles[], int Grundy[], int n) 
{ 
    int xorValue = Grundy[piles[0]]; 
  
    for (int i=1; i<=n-1; i++) 
        xorValue = xorValue ^ Grundy[piles[i]]; 
  
    if (xorValue != 0) 
    { 
        if (whoseTurn == P1) 
            printf("Player 1 will win\n"); 
        else
            printf("Player 2 will win\n"); 
    } 
    else
    { 
        if (whoseTurn == P1) 
            printf("Player 2 will win\n"); 
        else
            printf("Player 1 will win\n"); 
    } 
    return; 
} 


signed main()
{
    int piles[] = {3, 4, 5};
    int n = sizeof(piles)/sizeof(piles[0]);

    int maximum = *max_element(piles, piles+ n);

    int Grundy[maximum + 1];
    memset(Grundy, -1, sizeof(Grundy));

    for(int i = 0; i < n; i++)
        calculateGrundy(piles[i], Grundy);

    declareWinner(P1, piles, Grundy, n);
}