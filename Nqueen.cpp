#include<bits/stdc++.h>
using namespace std;

/*  
ld[] is an array where its indices indicate row-col+N-1 
(N-1) is for shifting the difference to store negative indices
checks whether quen can be placed on the left diagonal 

rd[] is an array where its indices indicate row+col 
and used to check whether a queen can be placed on right diagonal or not

column array where its indices indicates column and  
used to check whether a queen can be placed in that row or not
*/

const int mxN = 40;
int board[mxN][mxN];
int ld[30];
int rd[30];
int cl[30];
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
    if(col >= n)
        return 1;
    
    // try all the rows for this column
    for(int i=0; i<n; i++) {
        // check horizontal and diagnonal attack
        if(ld[i-col+n-1] != 1 && rd[i+col] != 1 && cl[i] != 1) {
            // its safe to place here
            board[i][col] = ld[i-col+n-1] = rd[i+col] = cl[i] = 1;

            if(solve(col+1)) {
                return 1;
            }

            // this combination is not a valid one, remove the placed queen
            board[i][col] = ld[i-col+n-1] = rd[i+col] = cl[i] = 0;
        }
    }
    return 0;
}

int main() {
    n = 4;
    int total = solve(0);
    print();
    cout << total << endl;
}