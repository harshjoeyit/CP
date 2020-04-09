#include<bits/stdc++.h>
using namespace std;


bool is_shorter( const string &s1 , const string &s2 )
{
    return ( s1.size() < s2.size() );
}


bool word_length( const string &s )
{
    return( s.size() > 6 );  // return true for the words greater than 6
}


bool first_letter( const string &s )
{
    return ( s[0] == 'a' );
} 


string make_plural(size_t ctr, const string &word, const string &ending) 
{    
    return (ctr > 1) ? word + ending : word; 
}

bool check_size( const string &s , string::size_type sz )
{
    return (s.size() > sz );
}

void f( int x , int y , int z , int m , int n)
{
    cout<<x<<endl;
    cout<<y<<endl;
    cout<<z<<endl;
    cout<<m<<endl;
    cout<<n<<endl;
}

// returning an ostream object 
ostream &print(ostream &os , const string &s , char c )
{
    return os<<s<<c;
}




// DRIVER FUNCTION:     
int main()
{
    // reordering words by size ( if sames size then alphabetical order )
    deque<string> fruits{"peach" , "apple" ,"apricot" , "avocado" , "pomegranate" , "mango" , "melon" , "pineapple", "berrys" , "raspberry"};
    // soting algo , customized
    sort( fruits.begin() , fruits.end() , is_shorter ); // remember that there is no need to pass the arguments
    
    cout<<"\nfruits: ";
    for( auto it = fruits.begin() ; it!= fruits.end(); it++ )
        cout<<" "<<*it;
    

    // partition algo rithm , takes , function argument as predicate , returns iteratorpast the last element for which the predicate returns true value  
    auto it_true_end = partition( fruits.begin() , fruits.end() , word_length );

    cout<<"\nfruits: ";
    for( auto it = fruits.begin() ; it!= fruits.end(); it++ )
        cout<<" "<<*it;
    // erasing the values that have wordlength < 6 
    fruits.erase( it_true_end , fruits.end() );

    cout<<"\nfruits: ";
    for( auto it = fruits.begin() ; it!= fruits.end(); it++ )
        cout<<" "<<*it;

    // if not found then find_if returns the off end iterator 
    // so a chek by of neccessary 
    auto fir_let_a = find_if( fruits.begin() ,fruits.end() , first_letter ); 
    // limitation:  first_letter can only be an unary argument function 
    // limitation is later overcome using lambda capture as here we are unable to pass the size into the function  
    if( fir_let_a != fruits.end() )
        cout<<"\n1st word with 1st letter a : "<<*fir_let_a;


    vector<int> numbers{10,3,5,8,11,23,7};
    // sorting in descending order with the help of lambda 
    sort( numbers.begin(), numbers.end() , []( int a , int b ){ return (a>b);} ); 
                                            // parameter list^
    cout<<"\nnumber list: ";
    for( auto it = numbers.begin() ; it!= numbers.end(); it++ )
        cout<<" "<<*it;
    
    
    // calling the find_if function 
    int sz = 9;
    auto wc = find_if( fruits.begin(), fruits.end() , [sz](const string &s ){return ( s.size() < sz );});
    
    if( wc != fruits.end() )
        cout<<"\n1st word with size less than mentioned : "<<*fir_let_a;
   
    auto count = fruits.end() - wc; 
    cout << endl << count << " " << make_plural(count, "word", "s")<< " of length " << sz << " or shorter" << endl;
 
   // for each
   // repeats the condition for a givne set of iterators 
   // printing the elements less than word_length 9
    cout<<"size < 9: ";
    for_each( wc, fruits.end(), [](const string &s){cout << s << " ";}); 
    cout << endl;

    // printing the elements greator or equal to  than word_length 9
    cout<<"size > 9: ";
    for_each( fruits.begin(), wc , [](const string &s){cout << s << " ";}); 
    cout << endl;
   
    
    
    //using lambda capture to add two values 
    // explicit capture 
    int x = 19;
    int y = 21;
    ostream &os = cout;
    auto sum = [&os , &x , &y](){ os<<"sum: "<<x+y<<endl<<"returned sum : "; return x+y; };
    cout<<sum()<<endl;

    // mix implicit capture
    // = deals with the capture of x and y by value, works as default capture type unless specified, implicitly
    // ostream object needs to be captures by reference so , we need to specify , it by reference ,
    // because the default type is , = : by value
    x = 5;
    y = 6;
    [ = , &os ](){ os<<"sum: "<<x+y<<endl<<"returned sum : "; return x+y; };
    cout<<sum()<<endl;
      

    
    forward_list<int> ls{ 1,2,-3,-4,-5,6,7};
    cout<<"absolute values:";

    // transform algorithm :  here used for replacing -ve values with their absolute values 
    transform(ls.begin() , ls.end() , ls.begin() , [](int i ){return (( i > 0 ) ?i : -i);} );
    for( auto it = ls.begin(); it != ls.end(); it++ )
        cout<<*it << " "; 
    cout<<endl;


    // capturing a local variable and decrementing its value until it reaches zero 
    int cap = 10;
    auto ret_lambda = [&](){ while( cap != 0 ) cap--; return cap;};
    // reference is necesssary since we are changing the value of the captured item

    cout<<"cap: "<<ret_lambda()<<endl;



     //: IMP
    list<int> lst = {1,2,3,1,2,3,4,4} , lst2, lst3 , lst4;     // empty lists 
    // after copy  completes, 1st2 contains 4 3 2 1
    copy(lst.cbegin(), lst.cend(), front_inserter(lst2)); 
    // after copy completes, 1st3 contains 1 2 3 4 
    copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));

    // unique copy
    deque<int> dq1{1,2,3,4,1,2,3,4} , dq2 , dq3;
    sort(dq1.begin(), dq1.end());               // sorting is nust before copy unique algo
    unique_copy(dq1.cbegin(), dq1.cend(), front_inserter(dq2));
    unique_copy(dq1.cbegin(), dq1.cend(), inserter(dq3, dq3.begin()));
    
    for(auto x : dq1)
        cout<<x<<" ";
    cout<<endl<<"dq2: ";
    for(auto x : dq2)
        cout<<x<<" ";
    cout<<endl<<"dq3: ";
    for(auto x : dq2)
        cout<<x<<" ";
    cout<<endl;
    
    /*................ ....... ........ */
    vector<string> svec= {"sweet charlie went to bring sweets but bought a suite instead"};
    for_each( svec.begin() , svec.end() , []( string str ){ for_each( str.begin() , str.end() , []( char s ){ if(s == ' ' ) cout<<endl; else cout<<s; } ); } );
    //^ each word in new line  ^
}