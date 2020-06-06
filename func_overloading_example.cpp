#include<bits/stdc++.h>
using namespace std;

void f1(int a, int b)   // f1
{
	cout<<"f1 called"<<endl;
}

void f1(double a,double b)  //f2
{
	cout<<"f2 called :"<<endl;
}



int main()
{

	f1(2,3); // correct 
	f1(2.3,8.9);  // no issues 
     	f1(2,3.5);   // error: compiler cannot decide whether to call f1 or f2 since bith require only trsnsfornation (int to double or double to int)
		f1(3.5,6.5);   // error: same goes for this function .  hence an error message is displayed 

	return 0;
}