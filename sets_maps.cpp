#include<bits/stdc++.h>
using namespace std;


bool comp( int a , int b )
{
    return (a<b);
}


int main()
{
    map<string, size_t> word_count;
    set<string> punctuation = {"," , "." , ";" ,":"};
    string word;

    cout<<"enter some words , press ctrl+Z :\n";
    while( cin>>word )
    {
        if( punctuation.find(word)  == punctuation.end() )
            ++word_count[word]; 	       // add words to the map that are not punctuation marks
    }
    
    for( const auto &w : word_count )
    cout<<w.first<<" occurs: "<<w.second<<( (w.second > 1) ? "times" : "time") << endl;



    // multimap or a multiset
    vector<int> ivec; 
    for (vector<int>::size_type i = 0; i != 10; ++i) 
    {    
        ivec.push_back(i);    
        ivec.push_back(i);  // duplicate copies of each number 
    }

    set<int> iset( ivec.cbegin() , ivec.cend() );
    multiset<int> miset( ivec.cbegin() , ivec.cend() );

    cout<<ivec.size() <<endl;
    cout<< iset.size() <<endl;
    cout<< miset.size()<<endl;


    // mapping the family name to first names
    vector<string> child_name = { "jason roy" , "oliver queen" , "james vetich" , "james macroni" };    
    map<string , string> surname_to_name;

    for( auto it = child_name.begin() ; it != child_name.end(); it++ )
    {
        string name = *it , first_name , sur_name;
        auto space = find(name.begin() , name.end() , ' ');
        first_name = string(name.begin() , space );
        sur_name = string( space + 1 , name.end() );
        surname_to_name.insert({sur_name , first_name});
    }

    cout<<"names retrieved from map: \n"<<endl;
    for( auto it = surname_to_name.begin(); it != surname_to_name.end(); it++)
        cout<<it->first<<","<<it->second<<endl;


    // using a multimp for thr same problem
    vector<string> children = { "jason roy" , "oliver queen" , "james vetich" , "james macroni" , "alisha roy" , "may queen" ,"thea queen" , "gwen vetich" , "sasha green" };    
    multimap<string , string> surNameToName;

    for( auto it = children.begin() ; it != children.end(); it++ )
    {
        string name = *it;
        
        auto space = find(name.begin() , name.end() , ' ');
        string first_name = string(name.begin() , space );
        string sur_name = string( space + 1 , name.end() );
     surNameToName.insert({sur_name , first_name});
    }

    cout<<"names retrieved from multimap: \n"<<endl;
    for( auto it = surNameToName.begin(); it != surNameToName.end(); it++)
        cout<<it->first<<","<<it->second<<endl;



    // multiset can only be defined with a comparitor function
    multiset<int , greater<int> > mlset;
    mlset.insert(40);
    mlset.insert(15);
    mlset.insert(20);
    mlset.insert(33);
    mlset.insert(4);

    cout<<"\nmultiset1: "<<endl;
    for( auto it = mlset.begin(); it != mlset.end(); it++)
        cout<<*it<<" ";
    cout<<endl;


    // using the comparitor function defined previously
    // syntax
    multiset<int , decltype(comp)* > mlset2(comp);
    mlset2.insert(40);
    mlset2.insert(15);
    mlset2.insert(20);
    mlset2.insert(33);
    mlset2.insert(4);
    mlset2.insert(20);
    mlset2.insert(33);

    cout<<"multiset2: "<<endl;
    for( auto it = mlset2.begin(); it != mlset2.end(); it++)
        cout<<*it<<" ";
    cout<<endl;



    // also be defined as -
    multiset<int, bool(*)(int a , int b)> mlset3(comp);
    mlset3.insert(5);
    mlset3.insert(3);
    mlset3.insert(4);
    mlset3.insert(1);
    mlset3.insert(3);

    cout<<"multiset3: "<<endl;
    for( multiset<int, bool(*)(int a , int b)>::iterator it = mlset3.begin(); it != mlset3.end(); it++)
        cout<<*it<<" ";
    cout<<endl;


    // multimap
    multimap<int, int> mlmap;
    mlmap.insert( pair<int, int>( 6,40) );      // only keys are sorted , the values for the same keys are not sorted they are in the default order of the input 
    mlmap.insert( pair<int, int>( 6,20) );
    mlmap.insert( pair<int, int>( 5,14) );
    mlmap.insert( pair<int, int>( 1,12) );
    mlmap.insert( pair<int, int>( 3,15) );
    mlmap.insert( pair<int, int>( 3,51) );
    mlmap.insert( pair<int, int>( 1,30) );
    mlmap.insert( pair<int, int>( 1,10) );

    // elements are ordered according to the key
    cout<<"multimap: \n";
    for(auto it = mlmap.begin(); it != mlmap.end(); it++ )
        cout<<it->first<<"-"<<it->second<<endl;

    // erase 
    // removes all the elments with the key mentioned 
    int count = mlmap.erase(1);

    cout<<"no. of el removed: "<<count<<endl<<"multimap: \n";
    for(auto it = mlmap.begin(); it != mlmap.end(); it++ )
        cout<<it->first<<"-"<<it->second<<endl;

    // find
    cout<<"find 3: \n";
    auto it = mlmap.find(3);                // it -> iterator to the first removed key with the value 3 
    if(it != mlmap.end())
        cout<<it->first<<"-"<<it->second<<endl;

    
    map<string,float> weekly_temp;
    weekly_temp["monday"] = 41.5;
    weekly_temp["tuesday"] = 42;
    weekly_temp["wednesday"] = 35.1;
    weekly_temp["thursday"] = 39;
    weekly_temp["friday"] = 37.5;
    weekly_temp["saturday"] = 32.5;
    weekly_temp["sunday"] = 40.5;

    cout<<"\n weekly temperatures: \n";
    for(auto it = weekly_temp.begin(); it != weekly_temp.end(); it++ )
    {
        //it->first = "today";                    --eroor , cant change a key 
        cout<<it->first<<"-"<<it->second<<endl;
    }

    cout<<"\n weekly temperatures: \n";
    set<float> week_temp = { 40,25,37,38,39,41.5,31.2};
    for(auto it = week_temp.begin(); it != week_temp.end(); it++ )
    {
        //*it = 42;                   // --eroor , cant change a key (for a set , key is the value)
        cout<<*it<<" ";
    }
    cout<<endl;


    // initialising a pair with the iterator of map 
    auto iter = surname_to_name.begin();
    pair<string, string> Pair = {iter->first , iter->second};
    cout<<"pair: "<<Pair.second<<" "<<Pair.first<<endl;

    
    // copy algorithm , the destination could be the associative container.
    vector<string> svec{"d-rose" , "king" , "mamba" , "uncle drew", "maverick" };
    set<string> sset;

    cout<<"sset : "<<endl;
    copy( svec.begin() , svec.end() , inserter(sset , sset.end()) );
    for(auto it = sset.begin(); it != sset.end(); it++ )
        cout<<*it<<endl;

    
    // operations on maps and sets
    multimap<int,string> Map = { {1,"joy"} ,{3,"revenge"}, {3,"gloom"} , {5,"anger"} , {7,"jealousy"} ,{9, "gluttony"}};
    for(auto itert = Map.begin(); itert != Map.end(); itert++ )
        cout<<itert->first<<" "<<itert->second<<endl;

    cout<<"count of key 3: "<<Map.count(3)<<endl;
    
    // returns iteraor to the same key of the next greater then the passes key 
    auto itert = Map.lower_bound(5);
    cout<<"lower_bound(5): "<<itert->first<<"-"<<itert->second<<endl;

    // imp- always , returns the iterator to the key just larger 
    itert = Map.upper_bound(5);
    cout<<"upper_bound(5): "<<itert->first<<"-"<<itert->second<<endl;

    map<int, int> Imap = {{1,10},{2,20},{3,30},{4,40}};
    cout<<Imap[1];

}