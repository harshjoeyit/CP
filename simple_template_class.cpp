#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Array
{
    private:
    int i = 0;
    T array[10];
    public:
    void input(T val)
    {
        array[i++] = val;
    }
    void display()
    {
        for(int j = 0; j < i; j++)
            cout << array[j] << " ";
        cout << endl;
    }
};

int main()
{
    Array<int> A;
    A.input(4);
    A.input(5);
    A.input(77);
    A.display();

    Array<string> B;
    B.input("roy");
    B.input("dopple");
    B.input("sgima");
    B.display();
}