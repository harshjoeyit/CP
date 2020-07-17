#include <iostream>
using namespace std;

// passing 2d array as an argument as array of pointers
void TwoDArrayAsArg(int (*matrix)[4], int rows) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < 4; col++)
            cout << matrix[row][col] << "\t";
        cout << endl;
    }
    
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < 4; col++)
            //whole row prints
            cout << (*(matrix))[col] << "\t"; 
        // change the row
        matrix++;        
        cout << endl;                 
    }
}

int main()
{
    int matrix[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    TwoDArrayAsArg(matrix, 3);
    return 0;
}
