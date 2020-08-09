#include<bits/stdc++.h>
using namespace std;

/*  
how do we find if current is placed queen is not under attack by 
any other previously placed queens ?

queens can attack along rows, diagnols (both), colums

we are filling the queens colums wise - place queen in cols 0, 1, ...
making sure attacks dont happen


note - i is common is all same row elements 
note - abs(i - j) is common in all left diagonal elements 
note - abs(i + j) is common in all right diagonal elements 
so we can mark the them.

*/

const int mxN = 40;
int board[mxN][mxN];
int ld[30];
int rd[30];
int rw[30];
int n;

void print() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int solve(int col) {
    if(col >= n) {
        print();
        cout << endl;
        return 0;
    }
    
    // try all the rows for this column
    for(int i=0; i<n; i++) {
        // check horizontal and diagnonal attack
        // + n-1 is used in i-col to avoid negetive indexes 
        if(ld[i-col+n-1] != 1 && rd[i+col] != 1 && rw[i] != 1) {
            // so its safe to place here
            board[i][col] = ld[i-col+n-1] = rd[i+col] = rw[i] = 1;

            // if we want just 1 solution return 1 from here 
            solve(col+1);

            // remove this queen for finding more possible positions 
            board[i][col] = ld[i-col+n-1] = rd[i+col] = rw[i] = 0;
        }
    }
    return 0;
}

int main() {
    n = 5;
    int total = solve(0);
}