/*
	https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1

	Time Complexity: O(9^(N*N)). 9 options per cell
	Auxiliary Space: O(N*N).
*/

#include<bits/stdc++.h>
using namespace std;
#define N 9

void printGrid (int grid[N][N])  {
    // Your code here 
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout << grid[i][j] << " ";
        } cout << "\n";
    }
}

// CHECK IF WE CAN PLAC val at (i, j)
bool check(int i, int j, int val, int grid[N][N]) {
	// check row
	for(int c=0; c<N; c++) {
		if(grid[i][c] == val) {
			return false;
		}
	}
	// check column
	for(int r=0; r<N; r++) {
		if(grid[r][j] == val) {
			return false;
		}
	}
	// check small square 
	// x, y => cordinates of top left corner
	int x = 3*(i/3), y = 3*(j/3);

	// small matrix has size 3
	for(int r=x; r<x+3; r++) {
		for(int c=y; c<y+3; c++) {
			if(grid[r][c] == val) {
				return false;
			}
		}
	}

	return true;
}

// RECURSIVE FUNCTION 
int go(int i, int j, int grid[N][N]) {
	if(i == N-1 && j == N) {
		return true;
	}

	// IMPORTANT MOVE, go to next row if this column filled 
	if(j == N) {
		i++, j = 0;
	}

	if(grid[i][j] != 0) {
		// skip this cell (same row, next column)
		return go(i, j+1, grid);
	}
	else {
		for(int num=1; num<=9; num++) {
			if(check(i, j, num, grid)) {
				grid[i][j] = num;
				// go to next cell (same row, next colum)
				if(go(i, j+1, grid)) {
					return true;
				}
				// make 0, backtrack
				grid[i][j] = 0;
			}
		}
	}
	return 0;
}


int main() {
	int grid[N][N] = {
		{3, 0, 6, 5, 0, 8, 4, 0, 0},
		{5, 2, 0, 0, 0, 0, 0, 0, 0},
		{0, 8, 7, 0, 0, 0, 0, 3, 1},
		{0, 0, 3, 0, 1, 0, 0, 8, 0},
		{9, 0, 0, 8, 6, 3, 0, 0, 5},
		{0, 5, 0, 0, 9, 0, 6, 0, 0},
		{1, 3, 0, 0, 0, 0, 2, 5, 0},
		{0, 0, 0, 0, 0, 0, 0, 7, 4},
		{0, 0, 5, 2, 0, 6, 3, 0, 0}
	};
	if(go(0, 0, grid)) {
		printGrid(grid);
	}
}