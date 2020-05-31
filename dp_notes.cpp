/*
Dynamic Programming



Let us say that you are given a number N, 
you've to find the number of different ways 
to write it as the sum of 1, 3 and 4.

DPn = DPn-1 + DPn-3 + DPn-4.

-----------------------------------------------------------------------------------------



Imagine N wine bottles are placed in a bar in a shelf.
The price of wine increases every to become y*p, where y is the year
starting from now, p is original price.
You want to sell exactly one wine per year, starting 
on this year. One more constraint - on each year you are 
allowed to sell only either the leftmost or the rightmost wine 
on the shelf and you are not allowed to reorder the wines on the shelf 

Greedy Approach : 
Every year, sell the cheaper of the two (leftmost and rightmost) available wines.
It fails as Although the strategy doesn't mention what to do when the 
two wines cost the same, this strategy feels right

p1=2, p2=3, p3=5, p4=1, p5=4
2 * 1 + 3 * 2 + 4 * 3 + 1 * 4 + 5 * 5 = 49.

Solved By DP.
2 * 1 + 4 * 2 + 1 * 3 + 3 * 4 + 5 * 5 = 50.


Backtracking function: 

O(n2) - as be, en combinations are n2, our function can run for these diff arguments 

    int profit(int be, int en) {
        if (be > en)
            return 0;
         
        if(dp[be][en] != -1)
            return dp[be][en];
        int year = N - (en-be+1) + 1;
          
        return dp[be][en] = max(
            profit(be+1, en) + year * p[be],
            profit(be, en-1) + year * p[en]
            );
    }

--------------------------------------------------------------------------------------



Finding Minimum-Cost Path in a 2-D Matrix

MinCost(i,j) = min(MinCost(i-1,j),MinCost(i,j-1)) + Cost[i][j]

The above statement means that to reach cell (i,j) with 
minimum cost, first reach either cell(i-1,j) or cell 
(i,j-1) in as minimum cost as possible. From there, 
jump to cell (i,j)

dp[0][0] = cost[0][0];

for(j: 1 - n)
    dp[0][j] = dp[0][j-1] + Cost[0][j]

for(i: 1 - n)
    dp[i][0] = dp[i-1][0] + Cost[i][0];


for(i: 1 - n)
    for(j: 1 - n)
        dp[i][j] = min( dp[i-1][j],  dp[i][j-1] );



---------------------------------------------------------------------------------------




Finding the number of ways to reach from a starting position to an ending position travelling in specified directions only.

numways(i,j) = numways(i-1,j) + numways(i,j-1)

dp[0][0] = 1;
// initialize first row of dp matrix
F(j,1,Y-1)
    dp[0][j] = 1;
//Initialize first column of dp Matrix
F(i,1,X-1)
    dp[i][0] = 1;

use n2 loops to solve 


Another variant -
Some blocks are blocked and cannot be travelled to 
so for such blocks

bool f = 0;
for(int j=1; j<m; j++) {
    if(Mat[0][j] == '#')                // no block after  a '#' can be reaached
        f = 1;
    if(f)   
        dp[0][j] = 0;
    else 
        dp[0][j] = 1;
}
f = 0;
for(int i=1; i<n; i++) {
    if(Mat[i][0] == '#')                // no block after a '#' can be reached 
        f = 1;
    if(f)
        dp[i][0] = 0;
    else 
        dp[i][0] = 1;
}


for(i: 1-n)
    for(j: 1-n)
        if(Mat[i][j] == '#')
            dp[i][j] = 0;               // number of ways to reach here is zero 
                                        // it coontributes 0 to next blocks 

        else {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];     
            // dp[i-1][j] or dp[i][j-1] > 0 or = 0 if blocked
        }




------------------------------------------------------------------------------------------------



Problem Statement : You are given a 2-D matrix A of n rows and m columns where 
A[i][j] denotes the calories burnt. 
Two persons, a boy and a girl, start from two corners of this matrix. The boy starts from cell (1,1) 
and needs to reach cell (n,m). 
On the other hand, the girl starts from cell (n,1) and needs to reach (1,m). The boy can move right and down. 
The girl can move right and up. 
As they visit a cell, the amount in the cell A[i][j] is added to their total of calories burnt. 

You have to maximize the sum of total calories burnt by both of them 
under the condition that they shall 
meet only in one cell and the cost of this cell shall not be included in either of their total.


(i, j) - is meeting cell

Boy

(i,j-1)-->(i,j)-->(i,j+1)
(i,j-1)-->(i,j)-->(i+1,j)
(i-1,j)-->(i,j)-->(i,j+1)
(i-1,j)-->(i,j)-->(i+1,j)

Girl

(i,j-1)-->(i,j)-->(i,j+1)
(i,j-1)-->(i,j)-->(i-1,j)
(i+1,j)-->(i,j)-->(i,j+1)
(i+1,j)-->(i,j)-->(i-1,j)


Only 1 time meeting possibility

Boy: (i,j-1)-->(i,j)-->(i,j+1) and Girl: (i+1,j)-->(i,j)-->(i-1,j)
and 
Boy: (i-1,j)-->(i,j)-->(i+1,j) and Girl:  (i,j-1)-->(i,j)-->(i,j+1)




Now, we can solve the problem by creating 4 tables:

Boy's journey from start (1,1) to meeting cell (i,j)
Boy's journey from meeting cell (i,j) to end (n,m)
Girl's journey from start (n,1) to meeting cell (i,j)
Girl's journey from meeting cell (i,j) to end (1,n)


----------------------------------------------------------------------------------------




4. Edit Distance
Edit distance is a way of quantifying how dissimilar two strings are, i.e., how many operations (add, delete or replace character) it would take to transform one string to the other. 


----------------------------------------------------------------------------------------








*/