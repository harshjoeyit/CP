/*
matrix exponentiation
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

class Matrix {
public: 
        const static int mod = 1e9+7;
        vector<vector<int>> mat;
        int rows;
        int cols;
        
        Matrix(int rows, int cols) {
                this->rows = rows;
                this->cols = cols;
                (this->mat).assign(rows, vector<int>(cols));
        }
        // static function can be invoked using just class reference as class::function()
        static Matrix multiply(Matrix a, Matrix b) {
                Matrix res = Matrix(a.rows, b.cols);
                for(int i=0; i<a.rows; i++) {
                        for(int j=0; j<b.rows; j++) {
                                for(int k=0; k<b.cols; k++) {
                                        res.mat[i][k] += a.mat[i][j] * b.mat[j][k];
                                        res.mat[i][k] %= mod;
                                }
                        }
                }
                return res;
        }
        static Matrix identityMatrix(int size) {
                Matrix res = Matrix(size, size);
                for(int i=0; i<size; i++) {
                        res.mat[i][i] = 1;
                }
                return res;
        }
        Matrix power(int exp) {
                if(exp == 0) {
                        return identityMatrix(rows);
                }
                if(exp == 1) {
                        return *this;
                }
                Matrix res = power(exp >> 1); 
                res = multiply(res, res);
                if((exp & 1) == 1) {
                        res = multiply(res, *this);
                }
                return res;
        }
        void print() {
                for(int i=0; i<rows; i++) {
                        for(int j=0; j<cols; j++) {
                                cout << mat[i][j] << " ";
                        }cout << endl;
                }
        }
};


signed main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        
        /*
                [1 1] * | 0 1 |^k = [f[k] f[k+1]]
                        | 1 1 |

        */

        // Matrix init(1, 2);
        // init.mat[0][0] = 1;       init.mat[0][1] = 1;

        // Matrix recur(2, 2);
        // recur.mat[0][0] = 0;       recur.mat[0][1] = 1;
        // recur.mat[1][0] = 1;       recur.mat[1][1] = 1;

        // // nth fibonacci number 
        // int n;
        // cin >> n;
        // auto ans = Matrix::multiply(init, recur.power(n));
        // cout << ans.mat[0][0];


        // .........................................sum of first i fibonacci numbers 

        // Matrix init(1, 3);
        // init.mat[0][0] = 2;             init.mat[0][1] = 1;          init.mat[0][2] = 1;

        // Matrix recur(3, 3);
        // recur.mat[0][0] = 1;            recur.mat[0][1] = 0;         recur.mat[0][2] = 0;
        // recur.mat[1][0] = 1;            recur.mat[1][1] = 0;         recur.mat[1][2] = 1;
        // recur.mat[2][0] = 1;            recur.mat[2][1] = 1;         recur.mat[2][2] = 1;


        // int n;
        // cin >> n;
        // auto ans = Matrix::multiply(init, recur.power(n-1));
        // cout << ans.mat[0][0] << "\n";
}       
