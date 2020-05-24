#include<bits/stdc++.h>
using namespace std;

vector<int> *dyn_vec()
{
    // creating an empty vector 
    vector<int> *pvec = new vector<int>();
    // function retruns a pointer to vec , pvec is invalidated after return 
    return pvec;
}

void input_dyn_vec( vector<int> *pvec )
{
    int n;
    cin >> n;
    int inp;
    cout<<"input: ";
    while(n-- )
    {
        cin >> inp;
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
    
    // deallocating the memory when the task is complete
    delete pvec;
    // pvec ivalidated here
}



// driver function 
int main()
{
    // creating vector
    auto *pvec = dyn_vec();
    input_dyn_vec( pvec );
    use_dyn_vec( pvec );
    // vector was dealloacted, pvec doent point to a vector now 
    // pvec , here is a dangling pointer so 
    pvec = NULL;
    // pvec may be used for another task in code later 
    //NOTE: that assigning pointer to NULL must be done after deallocating for avoiding memory leakage 
}
