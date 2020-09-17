#include<bits/stdc++.h>
using namespace std;

/*
Template instantiation - compiler examine the type of T when 
function is invoked(by typename deductions process ). 
multiple functions instances are created according to the arguments  

compiler generates code from template(blueprint)
*/

template<typename T>
T arraySum(T *arr,  int n) {
    T sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    }
    return sum;
}

template<typename T>
T Max(T x, T y) {
    return x > y ? x: y;
}

// Explicit Instatiation of template
template char Max(char x , char y);


// Explicit Specialization - gives correct result 
/*
template<> const char* Max(const char*x, const char *y) {
    return (strcmp(x, y) > 0 ? x : y);
}
*/


// Examples 

// template functions
template <typename T> 
void fun(vector<T> v) {
    cout << v[0] << endl;
}

// template classes 
template <typename T1, typename T2> 
class Pair {
public: 
    T1 first;
    T2 second;
    Pair(T1 f, T2 s):first(f), second(s) {
    }
    void getPair() {
        cout << first << " " << second << endl;
    }
};




int main() {
    
    cout << Max(2.3, 4.3) << endl;
    cout << Max("wee", "pee") << endl;

    float arr[] = {3.4, 5.3, 2.8};
    int a[] = {5, 3, 1, 4, 5};
    cout << arraySum(arr, 3) << endl;
    cout << arraySum(a, 5) << endl;

    // instantiated 
    cout << Max<float>(2.3, 2) << endl;

    // instantiated 
    int (*fptr)(int, int) = &Max;

    
    
    // therse arent raw strings 
    string B = "B";
    string A = "A";
    cout << Max(A, B) << endl;

    // print wrong ans without specialization
    cout << Max("d", "z") << endl;

    const char *b = "B";
    const char *a = "A";
    // Template is working wrong for raw strings here - address are getting compared 
    // so we need explicit "specialization for this type"
    // comment explicit specialization for wrong ans
    cout << Max(a, b) << endl;


    // Examples 

    vector<float> v1 = {4.3};
    vector<string> v2 = {"sds"};
    fun(v1);
    fun(v2);
    
    
    Pair<int, char> p1 = {3, 'f'};
    p1.getPair();
}