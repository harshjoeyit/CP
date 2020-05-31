#include<bits/stdc++.h>
using namespace std;

using PF = int(*)(int, int);

int add(int x, int y)
{
	return (x+y); 
}

int sub(int x, int y)
{
    return (x-y);
}

int pro(int x, int y)
{
    return (x*y);
}

int divi(int x, int y)
{
    return (x/y);
}

int main()
{
	vector < PF > vec;  // vector type pointer to function with int return and two int arguments 
	int x=10,y=2;
	int (*add_ptr)(int ,int ) = &add;
	int (*sub_ptr)(int ,int ) = &sub;
    int (*pro_ptr)(int ,int ) = &pro;
    int (*div_ptr)(int ,int ) = &divi;

    cout<<x<<" + "<<y<<" = "<<(*add_ptr)(x,y)<<endl;
    cout<<x<<" - "<<y<<" = "<<(*sub_ptr)(x,y)<<endl;
    cout<<x<<" * "<<y<<" = "<<(*pro_ptr)(x,y)<<endl;
    cout<<x<<" / "<<y<<" = "<<(*div_ptr)(x,y)<<endl;

    return 0;
}