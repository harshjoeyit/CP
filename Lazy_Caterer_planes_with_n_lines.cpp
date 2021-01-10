
/*
	Lazy Caterer problem 
	With n cuts, what is the maximum number of piece of cake that can be made 
    Genrelly, with n lines, what is mazimum number of parts a plane can be divided
    
	cuts  |  pieces 
	  0   |   1
	  1   |   2
	  2   |   4
	  3   |   7
	  ...
	  ..
	  .

	f(n) = n + f(n-1)
	f(n) = n + n-1 + n-2 + .. ... 1 + f(0)
	f(n) = n*(n+1)/2 + 1;
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	cout << n*(n+1)/2 + 1 << "\n";
}