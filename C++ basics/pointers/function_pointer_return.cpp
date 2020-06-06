#include<bits/stdc++.h>
using namespace std;

void f1(int i,float f)   // f1 prints i and f
{
	cout<<"f1 called : "<<i<<" "<<f<<endl;
}

decltype(f1) * f2( void (*p)(int ,float) )   // return type- pointer to f1 , argument - pointer to f1 
{
	return (p);
}

int main()
{
	void (*ptr)(int,float) = &f1;  // ptr- pointer to f1
	  
	// ptr2 and ptr3 also points to f1 
	// auto has type of function pointer of f1
	auto ptr2 = f2(ptr);      // calling f2 with argument - pointer to f1
	auto ptr3 = f2(f1);      // calling f2 with f1( f1 itself serves as a pointer.)

	(*ptr)(10,20.3);
	(*ptr2)(20,40.6);
	(*ptr3)(30,12.23);

	return 0;
}