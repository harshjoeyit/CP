
#include<bits/stdc++.h>
using namespace std;

namespace india {
    int a = 20;
    void sayHello() {
        cout << "Namaste\n";
    }
}

namespace other {
    int a = 10;
    void sayHello() {
        cout << "Hi\n";
    }
}

int main() {
    cout << india::a << " " << other::a << "\n";
    india::sayHello();
    other::sayHello();
}