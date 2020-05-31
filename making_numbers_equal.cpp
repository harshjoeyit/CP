#include<bits/stdc++.h>
using namespace std;
 

/*
	given two numbers a, b find the minimum number of steps that would make the two numbers equal 
	in each step you can increment any number by the step number 

	step 1 ... add 1 to a or b
	step 2 ... add 2 to a or b
	step 3 ... add 3 to a or b 
	....
	..

	find minimum steps to do so 

	logic - find the diff, and move untill the sum diff of becomes even - that means there exists a combination such that the numbers 1,2,3,4.... 
	can be added in such a way that make the numbers equal 
	
*/

int main()
{
	int T;
    cin >> T;
	while (T--)
	{
		int a,b;
        cin >> a >> b;
		int d = abs(a-b);
		int i;
		for (i = 0; i*(i+1)/2 < d ||(i*(i+1)/2 + d) % 2 == 1; i++);
            cout << i << endl;
	}
	return 0;
}