#include<bits/stdc++.h> 
using namespace std;

//todo: try a comlicated file rather than just text input.

struct PersonInfo
{
    string Name;
    vector<string> Phones;
};


// writing the standard output 
void print( ostream &stdoutput , ifstream &TextFile )       // refernce is important att both the places because , we need not create a copy of the if stream object , we refer to the same file 
{
    while( TextFile )
    {
        string line;
        getline( TextFile , line );
        cout<<line<<endl;
    }
    TextFile.close();
}


// writing from statdard input 
ofstream &write( istream &input , ofstream &TextFile )
{
    while(TextFile)
    {
        string line;
        getline( input , line );

        if( line == "-1")
            break;
            
        TextFile<<line<<". "<<endl;
    }
    return TextFile;
}


// writing to another file 
ofstream &copyfile( ifstream &TextFile , ofstream &TextFile2 )
{
    while( TextFile )
    {
        string line;
        getline( TextFile , line );
        replace( line.begin() , line.end() , ' ' , '_' );          // replacing spaces by _
        TextFile2<<line<<endl;
    }
    TextFile.close();
    return TextFile2;
}



bool valid( const string &num )
{
    return ( num.size() == 10 );
}

string format( const string &num )
{
    return ( "(" + num + ")" );
}




// driver program 
int main()
{
    ofstream wFile1;
    wFile1.open("doc1.txt"); // for app ( "file_name.txt" , ios :: app );
    write( cin , wFile1 ).close();        // input the contents and then cloose the file 

    ifstream rFile1("doc1.txt");
    ofstream wFile2("doc2.txt");
    copyfile( rFile1 , wFile2 ).close();        // copy the content and then close the file

    rFile1.open("doc1.txt");
    ifstream rFile2("doc2.txt");
    print( cout , rFile1 );
    print( cout , rFile2 );
    
    rFile1.open("doc1.txt");
    // writing the contents of a file into a vector 
    string line;
    vector<string> svec;
    while( rFile1 )
    {
        getline( rFile1 , line );
        svec.push_back( line );
    }
    rFile1.close();
    // display each number in the next line ...
    for_each( svec.begin() , svec.end() , []( string str ){ for_each( str.begin() , str.end() , []( char s ){ if(s == ' ' ) cout<<endl; else cout<<s; } ); } );

    
    
    
    // istringstream 
    string justEx;
    cout<<"string : ";
    getline( cin , justEx );            // must use the getline function 
    istringstream holdJustEx( justEx );
    string Ex;
    while( holdJustEx >> Ex )
        cout<<Ex<<endl;



    // reading from standard input
    cout<<"phones : "; 
    vector<PersonInfo> people;
    while( getline( cin , line ))
    {
        PersonInfo info;
        istringstream record(line);
        string number;
        record>>info.Name;
        while( record >> number )
            info.Phones.push_back(number);
        people.push_back(info);
    }
    
    for( auto &x : people )
    {
        cout<<x.Name<<": ";
        for( auto &y : x.Phones )
            cout<<y<<" ";
        cout<<endl;
    }



    // reading from a file 
    ifstream phone_doc("phone.txt");
    while( getline( phone_doc , line ))
    {
        PersonInfo info;
        istringstream record(line);
        string number;
        record>>info.Name;          // reads until at the space then stops 
        while( record >> number )   // read till the space and stop 
            info.Phones.push_back(number);
        people.push_back(info);
    }
    phone_doc.close();
    cout<<endl;
    for( auto &x : people )     // people has records from pnone.txt
    {
        cout<<x.Name<<": ";
        for( auto &y : x.Phones )
            cout<<y<<" ";
        cout<<endl;
    }



    // using ostringstream
    ofstream phone2_doc("phone2.txt");
    for( const auto &entry : people )
    {
        ostringstream formatted , badNums;      // object created on each loop 
        
        for ( const auto &nums : entry.Phones )
        {
            if( !valid(nums) )
                badNums<<" "<<nums;
            else
                formatted <<" "<< format( nums );
            
        }
        if( badNums.str().empty() )
            phone2_doc << entry.Name<<" "<< formatted.str() << endl;
        else
            cerr << "input error: "<< entry.Name <<" invalid number(s)"<< badNums.str() << endl;
    }
    // check the phone2.txt in the folder we aee that formatted putput is set 
    // the entries are done
}