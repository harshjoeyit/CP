#include<bits/stdc++.h>
using namespace std;

// dynamic vector has 
// capacity == size 
shared_ptr<vector<int>> shared_pvec()
{
    shared_ptr<vector<int>> spvec =  make_shared<vector<int>>();
    return spvec;
}



void input_dyn_vec(shared_ptr<vector<int>> spvec ) // function uses the copy of original pointer used in the function  
{               // copying a shared pointer increases refrence counter by 1
    int inp;                    // counter = 2
    cout<<"input: ";
    while( cin>>inp )
    {
        // using the arrow operator 
        spvec->push_back( inp );
        cout<<"input: ";
    }
    // spec local goes out of scope 
    // counter decreases by 1 , counter = 1;
}

void use_dyn_vec( shared_ptr<vector<int>> &spvec )  // spvec is the reference to the original pointer used in the call of the function 
{                   // copying a shared pointer increases refrence counter by 1
                     // counter = 2
    // sorting the vector in this function 
    // in descending order , by lambda functions
    sort( spvec->begin() , spvec->end() , []( int x , int y){ return (x>y); } );
    // printing
    cout<<"vector: ";
    for_each( spvec->begin() , spvec->end() , []( int i ){ cout<<i<<" "; });
}



// driver function 
int main()
{
    // creating vector
    // there is no need to specify * in declaring the variable 
    // it is alredy a pinter 
    // but to access the values we must dereference it , or use arrow operator 
    shared_ptr<vector<int>> spvec = shared_pvec() ;
    input_dyn_vec( spvec );
    use_dyn_vec( spvec );  


    // allocating memory to a vector , using a 
    // initializer list for initialization 
    initializer_list<int> ili = {1,2,3,4,5};
    shared_ptr<vector<int>> svptr = make_shared<vector<int>>(ili);
    svptr->reserve(50);
    cout<<svptr->capacity()<<endl;
    cout<<svptr->size()<<endl;
}

