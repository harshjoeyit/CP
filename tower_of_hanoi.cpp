#include<bits/stdc++.h>
using namespace std;

void ToH(char source, char aux, char dest, int n)
{
	if(n == 1)
	{
		cout << source << "->" << dest << endl;
		return;
	}

	// move n-1 to aux
	ToH(source, dest, aux, n-1);
    // move 1 to dest
	cout << source << "->" << dest << endl;
    // move n-1 from aux to dest
	ToH(aux, source, dest, n-1);
}

int main()
{
	ToH('A', 'B', 'C', 3);
}