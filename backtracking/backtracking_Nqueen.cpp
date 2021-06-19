#include<bits/stdc++.h>
using namespace std;

/*
    Very Inefficient Brute Force Backtraking solution
    
    We choose a column for each row and place the queen there. We do it recursively for each row. 
    Finally when we all queens are place when check if the arrangement good or not.
    
    Time Complexity
    Since we have n rows and cols
    nC1 * nC1 * nC1 ......... n time (for n rows) = n * n * n........ n times

    T(n) = O(n^n)
*/

/*
    Inefficient Backtracking Approach 
    
    We check if the position is safe to before placing a queen. A brute force checking if the position is safe or not takes 
    O(n) time since we have check each column, left diagonal, right diagonal that is marked. This checking function 
    runs in a for loop that can run n times.
    Also in each recursive call for n, we can make at most n-1 more recursive call (in for loop)

    T(n) =  n        *       ( T(n-1)       +     O(n) )
            for loop       recursive call       check position safe
    T(n) = n*T(n-1) + O(n^2) 
    T(n) = n^3 + n!
    
    T(n) = O(n!)
*/

/*  
Efficient Backtracking solution

how do we find if current is placed queen is not under attack by 
any other previously placed queens ?

queens can attack along rows, diagnols (both), colums

we are filling the queens colums wise - place queen in cols 0, 1, ...
making sure attacks dont happen

note - i is common is all same row elements 
note - abs(i - col) is common in all left diagonal elements 
note - abs(i + col) is common in all right diagonal elements 
so we can mark the them.

    Time Complexity 
    In this approach the checking position safe time is O(1)

    T(n) = n * (T(n-1) + O(1))
    T(n) = n!

    Time complexity on paper is still n! but it is 20* faster than the previous approach 
*/

vector<vector<int>> grid;
vector<int> col, leftDia, rightDia;

void printGrid();

void go(int i, int n) {
    if(i == n) {
        printGrid();
        return;
    }
    for(int j=0; j<n; j++) {
        // check if andy of col, leftDia, rightDia is marked 
        // + n-1 is used in i-col to avoid negetive indexes 
        if(col[j] || rightDia[i+j] || leftDia[j+n-1]) {
            continue;
        }
        // so its safe to place here
        grid[i][j] = 1, col[j] = 1, rightDia[i+j] = 1, leftDia[j+n-1] = 1;
        // recursive call for next row
        go(i+1, n);
        // remove this queen for finding more possible positions 
        grid[i][j] = 0, col[j] = 0, rightDia[i+j] = 0, leftDia[j+n-1] = 0;
    }
}

void nQueen(int n) {
    grid.assign(n, vector<int>(n, 0));
    col.assign(n, 0);
    leftDia.assign(2*n, 0);
    rightDia.assign(2*n, 0);
    go(0, n);
}

int main() {
    int n = 4;
    nQueen(n);
}

void printGrid() {
    for(auto row: grid) {
        for(auto val: row) {
            cout << val << " ";
        } cout << endl;
    } cout << endl;
}