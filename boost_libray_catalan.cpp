#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp> 
using boost::multiprecision::cpp_int;
using namespace std;

cpp_int coefficient(int n, int k){
    cpp_int res=1;
    for(int i=0; i<k; i++){
        res = res*(n-i);
        res = res/(i+1);
    }
    return res;
}
int main(){
   int t;
   cin>>t;
   while(t--){
    int n;
    cin>>n;
        cpp_int result = coefficient(2*n,n);
        cout << result/(n+1)<<endl;
   }
}