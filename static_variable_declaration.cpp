#include<iostream>
using namespace std;

static int x = 9;

int main()
{
    static int x = 11;
    x++;
    cout << &x << endl;
}
