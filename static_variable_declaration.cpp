#include<iostream>
using namespace std;

static int x = 1;

void print1() {
    static int x = 10;
    x += 1;
    cout << "print1: " << x << endl;
}

void print2() {
    static int x = 20;
    x += 1;
    cout << "print2: " << x << endl;
}

void go() {
    static int x = 30;
    cout << ::x << endl;
    print1();
    print2();
    cout << x << endl << endl;

    ++x;
    ++(::x);

    cout << ::x << endl;
    print1();
    print2();
    cout << x << endl;
}


class StaticTest {
    static int x;
public: 
    static int y;
    int z = 40 ;

    int getX() {
        return x;
    }
    static int getXAgain() {
        return x;
    }
    void setZ(int _z);
};

int StaticTest::x = 5;
int StaticTest::y = 10;

void StaticTest::setZ(int _z) {
    this->z = _z;
}

int main() {
    go();
    
    cout << StaticTest::y << endl;
    StaticTest *st = new StaticTest();

    cout << "static member can be acceses by non-static member function\n";
    cout << st->getX() << endl;

    cout << "static member functions can be accesecd by object\n";
    cout << st->getXAgain() << endl;

    // of course we cannot access private variable of any kind 
    // cout << StaticTest::x << endl;

    cout << "class uses scope resolution operator\n";
    cout << StaticTest::y << endl;

    st->setZ(123);
    cout << st->z << endl;
}

