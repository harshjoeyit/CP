#include<iostream>

using namespace std;

int i = 42,k=20;

int main()
{
    int i = 100;
    int j = i;
    cout<<i<<endl<<j<<endl;

    int sum = 0;
    for (int i = 0; i != 10; ++i)
    sum += i;
    // important.
    std::cout << i << "\n " << sum << std::endl;

    int s=0;
    for (int k = 0; k != 5; ++k)
    s+= k;
    // important.
    std::cout << k << "\n " << s << std::endl;

    return 0;
}

