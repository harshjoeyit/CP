#include<bits/stdc++.h>
using namespace std;

template <typename T> 
void print(initializer_list<T> args) {
    for(auto arg: args) {
        cout << arg << " ";
    }cout << endl;
}

// using vaiadic templates 


// base case for recursive call 
void print() {
    cout << endl;
}

// template parameter pack
template <typename T, typename...Params>
// function paramenter pack 
// we use refernce since inrecursion many copies will be created
void print(const T &a, const Params&... args) {
    // cout << sizeof...(args) << " ";
    cout << a;
    if(sizeof...(args) != 0) {
        cout << ", ";
    }
    print(args...);
}

int main() {
    // argument must be of the same type
    print({1, 2, 3, 4});
    print({"a", "b", "c"});

    // using Params
    print('a', 1, 2.5, "hello");
    /*
    calls to print functions are like 
    print('a', 1, 2.5, "hello");
    print(1, 2.5, "hello");
    print(2.5, "hello");
    print("hello");
    print();

    In each recursive call 1 argument reduces
    */
}