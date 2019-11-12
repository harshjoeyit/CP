#include<bits/stdc++.h>
#include<map>
using namespace std;

int main()
{
    map<int, string> phonemap;

    // 4 ways to insert In a map s
    phonemap.insert({6,"victor"}); 
    phonemap.insert(make_pair( 7 , "sam")); 
    phonemap.insert(pair<int , string>( 4, "natalie")); 
    phonemap.insert(map<int , string >::value_type(3 , "latham"));
    
    // does not insert with repeated key
    phonemap.insert({2,"robert"}); // value already inserted at 2
    phonemap.insert({13,"jhonny"});

    // note that : the pair with alredy existing key is not inserted 
    // for alredy inserted pair
    // we cannot change the key
    // but we can assign a new value to a key 
    // below are a few instances 
    phonemap[1]="tom";
    phonemap[2]="jerry";
    phonemap[3]="Cook";  
    phonemap[8]="gadot";
    phonemap[10]="ethan";
    phonemap[9]="vince";
    // if key value pair did not exit , they are created during the assignment 4
    
    

    cout<<phonemap[8]<<endl;
    // accessing the values in the map

    // valid use of pointer and .
    for(map<int, string>::iterator it= phonemap.begin(); it!=phonemap.end(); it++)
        cout<<(*it).first<<" = > "<<(*it).second<<endl;

    cout<<"size of the map: "<<phonemap.size()<<endl;
    cout<<"clearing map "<<endl;

    // 3.other way to insert in a map
    phonemap.insert(pair<int, string>(10,"Ross"));  // we could have entered it at any key
    cout<<phonemap[10]<<endl;
    // searching in a map associated to a key

    cout<<"in bytes "<<sizeof(phonemap)<<endl;
    // all maps a have a constant size of 24 bytes

// assigning the elements from  one map to other
    map<int, string> ph2(phonemap.find(7), phonemap.end());
// better to use iterator to access as the can be any number and we can not use index
     for(map<int, string>::iterator it= ph2.begin(); it!=ph2.end(); it++)
        cout<<it->first<<" = > "<<it->second<<endl;

     // lower bound and upper bound for map
    cout << "ph2.lower_bound() : "
         << "\tKEY = ";
    cout << phonemap.lower_bound(2)->first << '\t';
    cout << "\tELEMENT = "
         << phonemap.lower_bound(2)->second << endl;

        cout << "ph2.upper_bound() : "
         << "\tKEY = ";
    cout << phonemap.upper_bound(2)->first << '\t';
    cout << "\tELEMENT = "
         << phonemap.upper_bound(2)->second << endl;

             phonemap.clear();
    cout<<"size of the phonebook now : "<<phonemap.size()<<endl;



    // finding elements with the same key 
    multimap<int,float> Multimap = { {1,32} ,{3,49}, {3,98} , {3,45} , {5,56} ,{9, 14}};
    for(auto itert = Multimap.begin(); itert != Multimap.end(); itert++ )
        cout<<itert->first<<" "<<itert->second<<endl;
    
     // using iterator on same keys return a range 
    auto range_begin = Multimap.lower_bound(3); // ->it to first key 3
    cout<<"lower_bound(5): "<<range_begin->first<<"-"<<range_begin->second<<endl; 
    auto range_end = Multimap.upper_bound(3); ///->it to key 5
    cout<<"upper_bound(5): "<<range_end->first<<"-"<<range_end->second<<endl;

    cout<<"printing all values for key 3:\n";
    for(auto itert = range_begin; itert != range_end; itert++ )
        cout<<itert->second<<" ";
    cout<<endl;

    // use count to count no of elements , find to find iterator to first element with a given key
    // use a while loop for count no of times to iterate through the values

return 0;
}
