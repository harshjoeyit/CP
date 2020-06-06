#include<bits/stdc++.h>
using namespace std;

//class 1.....................................
class absInt
{
    public : 

    int operator()( int val ) const 
    {
        return val < 0 ? -val : val ;
    }
};



//class 2 .....................................
class PrintString
{
    public: 
        // constructor 
        PrintString( ostream &o = cout , char c = ' ' ): os(o) , sep(c) { }

        void operator()(const string &s ) const 
        {
            os<<s<<sep;
        }
    private:
        ostream &os ;
        char sep;
};


//..class3 ..........................................
class ifThenElse
{
    public: 

    const string& operator() ( const string& s1 , const string& s2 , const string& s3 )const
    {
        if( s1.length() > 5 )
            return s2;
        else
            return s3;
    } 
};
\

//class 4.................................................
class InputString
{
    public: 
        
        void operator() ( istream &stdInput , vector<string> &svec )
        {
            string line;
            while(cin>>line)
                svec.push_back(line);
        }
};


//class 5..........................
class CompareString
{
    public:             // constructor 
        CompareString( const string &s ) : str(s) { }
 
        bool operator() ( const string &s ) const
        {
            return s == this->str;
        }

    private:
        string str;
};


//class 6.....................
class ShorterString 
{ 
    public:    
    bool operator()(const string &s1, const string &s2) const    
    {
        return( s1.size() < s2.size() ); 
    }
};




int main()
{
    // 1............
    int i = -42;
    absInt absObj;
    int ui = absObj(i);         // although abs is an object , we can use the function call operator 
    cout<<ui<<endl;

    
    //2..............
    PrintString printer;
    printer("revoke");                  // gives a space after printing
    PrintString errors( cerr , '\n' );
    errors("revoke");                           // gives anew line after printing

    vector<string> svec{"club11" , "bar99" , "motel42" ,"cafeteria22" , "club07" , "bar54"};
    
                                    // functions with a temporary object of type class provided
    for_each( svec.begin() , svec.end() , PrintString(cerr,'\n') );


    //3................
    ifThenElse IF;
    const string& res = IF("purple" , "win" , "lose" ); 
    
    cout<<"iftehelse: "<< res <<endl;

    //4...............................
    InputString Is;
    Is(cin,svec);               // store the input in  the vector 

    for( auto x : svec )
        cout<<x<<" ";
    cout<<endl;    

    //5.........*****....................
    CompareString IsEqual("respawn");
    bool b1 = IsEqual("reckon");
    bool b2 = IsEqual("respawn");

    cout<< endl <<b1 <<" "<<b2<< endl;
                                // using a temp object of the class for doing the same job a lamda would do  
    replace_if( svec.begin() , svec.end() , CompareString("motel42") , "Motel999" );
                // sort according the word length if , word lenght is equal the sort them lexiographically
    stable_sort( svec.begin() , svec.end() , ShorterString() );

    for( auto x : svec )
        cout<<x<<" ";
    cout<<endl;

    
}