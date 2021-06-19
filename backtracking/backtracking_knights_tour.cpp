/*
Another Solution using
Warnsdorff’s algorithm for Knight’s tour problem
https://www.geeksforgeeks.org/warnsdorffs-algorithm-knights-tour-problem/
*/


#include<bits/stdc++.h>
using namespace std;

/*
	Backtracking: On every cell knight has 8 moves, there are total N*N cells
	T(n) = O(8^N^2)
*/

#define N 8
int mat[N][N];
int dirX[8] ={ 2, 1, -1, -2, -2, -1, 1, 2 };
int dirY[8] ={ 1, 2, 2, 1, -1, -2, -2, -1 };

void printSolution();

int go(int i, int j, int moves) {
    mat[i][j] = moves;
    // cout << i << " " << j << " " << moves << endl;

	if (moves == N*N - 1) {
        printSolution();
        return 1;
    }

	for (int k = 0; k < 8; k++) {
		int x = i + dirX[k];
		int y = j + dirY[k];
        if (x < 0 || y < 0 || x >= N || y >= N || mat[x][y] != -1) {
            continue;
		}
        
        if (go(x, y, moves + 1)) {
            return 1;
        }
	}

    mat[i][j] = -1;
	return 0;
}

int main() {
	memset(mat, -1, sizeof(mat));
	if (!go(0, 0, 0)) {
		cout << "Solution does not exist";
		return 0;
	}
	// printSolution();
	return 1;
}


void printSolution() {
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++)
			cout << " " << setw(2) << mat[x][y] << " ";
		cout << endl;
	}
}