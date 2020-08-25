

/* 
basic lambda expression

- NOTE: no functions can be called from inside the lambda function


- NOTE: Never | Never use bool to denote type of return of lambda 
        always use auto 
        


[capture](args) { 
    functionality 
}
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<int> v = {1, 3, 5, 1, -4, 6, 8, 10};
    // function to count numbers greater than or equal to 5 
    int count_5 = count_if(v.begin(), v.end(), [](int a)                               
    { 
        return (a >= 5); 
    }); 
    cout << "The number of elements greater than or equal to 5 is : "
         << count_5 << endl; 

        
    /*
      [&] :     capture all external variable by reference
      [=] :     capture all external variable by value
      [a, &b] : capture a by value and b by reference
    */

    vector<int> v1 = {3, 1, 7, 9}; 
    vector<int> v2 = {10, 2, 7, 16, 9}; 
  
    //  access v1 and v2 by reference( [&] is used for v1 and v2)
    auto pushinto = [&] (int m) 
    { 
        v1.push_back(m); 
        v2.push_back(m); 
    }; 
  
    // it pushes 20 in both v1 and v2 
    pushinto(20);


    // access v1 by copy 
    auto print = [v1]() { 
        for_each(v1.begin(), v1.end(), [](int a){cout << a << " ";});
        // or simply
        cout << "\n";
        for(auto a: v1)
            cout << a << " ";
        cout << "\n";
    }; 

    print();

    int N = 5; 
  
    // below snippet find first number greater than N 
    // [N]  denotes,   can access only N by value 
    vector<int>:: iterator p = find_if(v1.begin(), v1.end(), [N](int i) 
    { 
        return i > N; 
    }); 
    cout << *p << endl;




    // function to count numbers greater than or equal to N 
    // [=] denotes,   can access all variable 
    int count_N = count_if(v1.begin(), v1.end(), [=](int a) 
    { 
        return (a >= N); 
    }); 
  
    cout << "The number of elements greater than or equal to 5 is : "
         << count_N << endl; 

    
}