#include<bits/stdc++.h>
using namespace std;


void eliminate_duplicate( vector<string> &words ) // containers are not passes by reference by default 
{
    sort(words.begin(), words.end());
    // unique overrites the elements and makes the starting elements unique and returns iterator to one past the unique sequence 
    auto end_unique = unique( words.begin() , words.end() );
    // erase removes the elements apprearing after the iterator rreturned
    words.erase( end_unique , words.end() );
}


bool is_shorter( const string &s1 , const string &s2 )
{
    return ( s1.size() < s2.size() );
}


int main()
{
    int a[11] = {1,2,3,4,4,2,8,2,1,2,11};
    int val = 2;
    auto Count = count(begin(a), end(a), val);
    cout<<Count<<endl;
    auto result = find(begin(a), end(a), val);
    cout<<"result: "<<*result<<endl;


    list<string> names = {  "harshit",
                            "gangwar",
                            "is",
                            "sangam",
                            "city",
                            "assassin",
                            "city",
                            "hart"
                        };

    vector<int> vec{2,6,2,3,8,2,9,1 ,1 , 1};

    // accumulate
    auto sum = accumulate(vec.cbegin() , vec.cend() , 0 );
    cout<<"sum: "<<sum<<endl;
    // last arguement determines the type of addition operator to use 
    string concat = accumulate( names.cbegin() , names.cend() , string(""));
    cout<<"concatinated : "<<concat<<endl;


    // equal function 
    vector<string> svec = { "jhonny" , "mera", "naam"};
    list<const char*> list_items = {"jhonny" , "mera", "naam" , "hai"};
    // returns true if the container elements are same 
    bool b = equal( svec.cbegin() , svec.cend() , list_items.cbegin() );
    cout<<b<<endl;
    // compares every element in container one to container two , 
    // if 1 is a subset of 2 then the comparison stops at 1.cend() and 1 is returned if the previous values are all equal 
    // if two is subset of one then there is serious error , 
    // function tries to access the values beyond 2.cend 


    // writing algorithms 
    // fill function
    fill(vec.begin(), vec.begin() + vec.size()/2, 5);
    sum = accumulate(vec.cbegin() , vec.cend() , 0 );
    cout<<"sum: "<<sum<<endl;

    // back_inserter , each call is  a push_back call 
    // that is why this algo could work on a 
    auto it = back_inserter(vec);
    *it = 42;
    cout<<"last element in the vector : "<< *(vec.cend() - 1)<<endl;


    // copy algo 
    int a1[] = {0,1,2,3,4,5,6,7,8,9}; 
    int a2[sizeof(a1)/sizeof(*a1)];   // a2 has the same size as a1 
                                     // ret points just past the last element copied into a2 
    auto ret = copy(begin(a1), end(a1), a2);  // copy a1 into a2
    cout<<"array 2: ";
    for( auto x: a2)
        cout<<x<<" ";
    // ret is the begin() iterator 
    cout<<"\nvalue of the returned iterator "<<*ret<<endl;


    //replace 
    // replace 1st value by 2nd 
    replace( begin(a), end(a) , 2 , 9 );
    cout<<"array 1: ";
    for( auto x: a)
        cout<<x<<" ";


    // replace_copy
    vector<int> ivec{4,5,6};
    list<int> ilst = {1,2,3,4,5,1,1};

    cout<<"\nivec: ";
    // ilst is unchanged, and ivec contains a copy of ilst with the exception that every element in ilst with the value 1 has the value 99 in ivec
    replace_copy(ilst.begin(), ilst.end() , back_inserter(ivec), 1,  99);
    for( auto it = ivec.begin() ; it!= ivec.end(); it++ )
        cout<<" "<<*it;
    

    // remove_duplicates
    vector<string> words{"the", "quick", "red", "fox" , "jumps" ,"over" , "the" , "red" , "turtle"};
    eliminate_duplicate(words);
    cout<<"\nwords :";
    for( auto it = words.begin() ; it!= words.end(); it++ )
        cout<<" "<<*it;



    // reordering words by size ( if sames size then alphabetical order )
    deque<string> fruits{ "peaches" , "apple" ,"apricot" , "avocado" , "pomegranate" , "mango" , "melon" , "pineapple"};
    sort( fruits.begin() , fruits.end() , is_shorter ); // remember that there is no need to pass the arguments
    cout<<"\nfruits: ";
    for( auto it = fruits.begin() ; it!= fruits.end(); it++ )
        cout<<" "<<*it;
    /*................ ....... ........ */
}