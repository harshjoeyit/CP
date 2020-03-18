#include<bits/stdc++.h>
using namespace std;

class stu{
    public: 
    int i = 20;
};


void foo()
{
    class stu{
        public:
        int i = 10;
    };

    stu x;
    cout << x.i << endl;
}

int main()
{
    foo();
    stu x;
    cout << x.i << endl;
}