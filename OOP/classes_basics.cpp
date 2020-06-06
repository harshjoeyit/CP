#include<bits/stdc++.h> 
using namespace std;

struct taxes {
    int GST;
    int cross_border;
};

struct sales_data {
    int a , b;
    // if const is used after paameterlist then it cannot change the values in the object
    int sum() const {
        return (a+b);
    }
    
    int diff();
    
    void change_data() { // const - if const is used here then the increment is not possible 
        a++;
        b++;
    }

    sales_data* combine( struct taxes &T ) {
        a = a + T.cross_border + T.GST;
        b = b + T.cross_border + T.GST;
        // returning this - pointer to object of the class
        return this;               
    }          
    // if we return *this , then return type = sales_data&
    // derefrence *this gives reference to the object 
};

int sales_data::diff() {
    return (a>b)? (a-b): (b-a) ;
}

int main() {
    struct sales_data sd;
    struct taxes T;

    cout<<"item cost: ";
    cin>>sd.a>>sd.b;
    cout<<"taxes: ";
    cin>>T.cross_border>>T.GST;

    cout<<"a: "<<sd.a<<endl;
    cout<<"b: "<<sd.b<<endl;
    cout<<"sum : "<<sd.sum()<<endl;
    cout<<"diff : "<<sd.diff()<<endl;
    
    sd.change_data();
    cout<<"a: "<<sd.a<<endl;
    cout<<"b: "<<sd.b<<endl;

    auto ptr_sd = sd.combine(T);        //ptr_sd is pointer to class object
    cout<<"after combine: "<<endl;
    cout<<"a: "<<ptr_sd->a<<endl;
    cout<<"b: "<<ptr_sd->b<<endl;
}