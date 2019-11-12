#include<bits/stdc++.h>
using namespace std;

vector<int> *dyn_vec()
{
    // creating an empty vector 
    vector<int> *pvec = new vector<int>();
    // function ends , invalidates p
    return pvec;
}

void input_dyn_vec( vector<int> *pvec )
{
    int inp;
    cout<<"input: ";
    while( cin>>inp )
    {
        // using the arrow operator 
        pvec->push_back( inp );
        cout<<"input: ";
    }
    // pvec local , invalidated when function ends
}

void use_dyn_vec( vector<int> *pvec )
{
    // sorting the vector in this function 
    // in descending order , by lambda functions
    sort( pvec->begin() , pvec->end() , []( int x , int y){ return (x>y); } );
    // printing
    cout<<"vector: ";
    for_each( pvec->begin() , pvec->end() , []( int i ){ cout<<i<<" "; });
    // deallocating the mempry when the task is complete
    delete pvec;
    // pvec (local ) ivalidated , here
}



// driver function 
int main()
{
    // creating vector
    auto *pvec = dyn_vec();
    input_dyn_vec( pvec );
    use_dyn_vec( pvec );
    // no since the memory is deallocated 
    // pvec , here is a dangling pointer so 
    pvec = NULL;
    // pvec may be used for another task in code later 
    //NOTE: that assigning pointer to NULL must be done after deallocating  
}
