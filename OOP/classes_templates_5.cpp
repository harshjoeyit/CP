#include<bits/stdc++.h>
using namespace std;

template<typename T>
class PrettyPrinter {
        T *ptr;
public:
        PrettyPrinter(T *data) : ptr(data) {

        }
        void Print() {
                cout << "{" << *ptr << "}" << endl;
        }
        T *getData() {
                return ptr;
        }
};

// explicit specialization for const char *
template<typename T>
class PrettyPrinter<const char *> {
         char *ptr;
public:
        PrettyPrinter(char *data) : ptr(data) {

        }
        void Print() {
                cout << "{" << ptr << "}" << endl;
        }
        char *getData() {
                return ptr;
        }
};


int main() {    
        int data = 5;
        float f = 8.2f;
        PrettyPrinter<int> p1(&data);
        PrettyPrinter<float> p2(&f);
        p1.Print();
        p2.Print();

        string s = "myname";
        PrettyPrinter<string> p3(&s);
        p3.Print();

        const char *p = "harshit";
        PrettyPrinter<const char *> p4(&p);             // we have to pass the address 
        p4.Print();
        auto ans = p4.getData();                        // return pointer to pointer 
        // cout << ans << endl;                         // prints address 
        
        // we create a specialization for const char *
}