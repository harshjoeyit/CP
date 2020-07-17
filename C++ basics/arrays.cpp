#include <iostream>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

// auto can be used as a return type
// but cannot be used as paramenter type
auto someVal()
{
    vector<int> v = {1, 3};
    return v;
}

void printStr(const char *p)
{
    if ((p))
        // stops on the null char
        while (*(p))
            cout << *(p++);
}

int main() {
    
    // pointer to strings 
    string str("gangwar");
    const char *sp = str.c_str();
    cout << (sp+1) ;
    cout << endl;

    // vector initialization using a vector 
    int arr[] = {10, 20, 30, 40, 50};
    vector<int> vec(begin(arr) + 1, end(arr) - 1); 
    
    // copying the vector to an array
    vector<int> ivec{10, 20, 30, 40, 50, 60, 70, 80, 90};
    int *ab = &ivec[0];
    for(int i=0; i<ivec.size(); i++) {
        cout << *(ab + i) << " ";
    }

    // using the begin and the end pointer
    int array1[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int *pb = begin(array1);
    int *pe = end(array1);

    while (pb != pe) {
        cout << *pb << " ";
        ++pb;
    }

    // ptrdiff_t is the signed library type that suitable to store the differences of the  pointer
    ptrdiff_t N = begin(array1) - end(array1); 
    cout << N << endl;

    const char *s = "harshit";
    printStr(s);

    int foo[] = {10, 20, 30, 40, 50};
    vector<int> bar;

    // begin(foo) returns pointer to base address of foo 
    for (auto it = std::begin(foo); it != std::end(foo); ++it)
        bar.push_back(*it);

    // can be used on vectors to 
    for (auto it = std::begin(bar); it != std::end(bar); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    // an be used on map
    map<int, int> mp;
    mp[1] = 2;
    mp[3] = 1;
    
    for(auto it = begin(mp); it != end(mp); it++) {
        cout << it->first << " ";
    }
    cout << endl;
}
