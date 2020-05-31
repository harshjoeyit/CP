#include<bits/stdc++.h>
using namespace std;

using PF = int(*)(int, int);

int test_func(int x, int y)
{
	return ( (x>y) ? x : y);  // return the greater value 
}

int main()
{
	vector < PF > vec;  // vector type pointer to function with int return and two int arguments 
	
	int (*ptr)(int ,int ) = &test_func;
	int (*ptr1)(int ,int ) = &test_func;   // creating pointer to the functions 

	vec.push_back(ptr);   // filling the vector with pointer to the function
	vec.push_back(ptr1);
	vec.push_back(test_func);  // function name itself serves as a pointer 

	int ret1= (*vec[0])(2,4);  // could have done without the *
	int ret2= (*vec[1])(3,9);  
	int ret3= (vec[2])(4,16);  // without *

	cout<<ret1<<" "<<ret2<<" "<<ret3<<endl;

	int t1 = 5,t2 = 10;

	for( auto it = vec.begin(); it != vec.end(); it++ )
	{
		cout<< ( *it)(t1++ , t2++) << " " ;   // *it gives us one of th pointer such as vec[0],vec[1]
	}
}