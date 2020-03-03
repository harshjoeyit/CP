#include<bits/stdc++.h>
using namespace std;

void ToH(char source, char aux1, char aux2, char dest, int n)
{
    if(n == 0)
        return;
	if(n == 1)
	{
		cout << source << "->" << dest << endl;
		return;
	}

	ToH(source, aux1, dest, aux2, n-2); 
	cout << source << "->" << aux1 << endl;
    cout << source << "->" << dest << endl;
    cout << aux1 << "->" << dest << endl;
	ToH(aux2, aux1, source, dest, n-2);
}

int main()
{
	ToH('A', 'B', 'C', 'D', 64);
}