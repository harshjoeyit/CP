#include<bits/stdc++.h>
using namespace std;

main()
{
    set<int> set1,set2;

    // insert elements in random order
    set1.insert(50);
    set1.insert(90);
    set1.insert(80);
    set1.insert(30);
    set1.insert(40);// added only once
    set1.insert(20);
    set1.insert(10);
    set1.insert(8);
    set1.insert(4);
    set1.insert(5);

    // values accessed by the iterators
    cout<<"set1: ";
    for(auto it=set1.begin(); it != set1.end(); it++)
        cout<<*it<<" ";   // all values are sorted and then stored in the set

    //finding an element
    auto findit = set1.find(50);
    if(findit != set1.end())
        cout<<endl<<"found: "<<*findit<<endl;
    else
        cout<<endl<<"not found"<<endl;

    cout<<"set1: ";
    set1.erase(set1.begin(), set1.find(10));
    for (auto itr = set1.begin(); itr != set1.end(); ++itr)
        cout <<" "<< *itr;

    cout<<endl<<"set1: ";  //reverse printing
    for (auto itr = set1.rbegin(); itr != set1.rend(); ++itr)
        cout <<" "<< *itr;

    cout<<endl<<set1.size();  // no. of elements in the container
    cout<<endl<<sizeof(set<int>);  // set has  a constant size for all data types

    if(! set1.empty())
        cout<<endl<<"not empty: ";  //checks if empty

    auto iter = set1.insert(set1.begin(),100);
    iter = set1.insert(iter,110);
    iter = set1.insert(iter,120);
    iter = set1.insert(iter,130);

    cout<<endl<<"set1: ";
    for(auto it=set1.begin(); it != set1.end(); it++)
        cout<<*it<<" ";

        // SET 2
        //lower_bound and upper_bound return the same iterator, then the given key is not in the container.

    set2.insert(set1.find(90), set1.end());

    cout<<endl<<"set2: ";
    for(auto it=set2.begin(); it != set2.end(); it++)
        cout<<*it<<" ";

    auto itlb = set2.lower_bound(89);  // returns iterator to same key if found else  to next greater
    cout<<endl<<*itlb;

    auto itlu = set2.upper_bound(89);  // returns iterator next greater key if found else to end()
    cout<<endl<<*itlu;

    swap(set1,set2);  ///swapped set

    cout<<endl<<"set1: ";
    for(auto it=set2.begin(); it != set2.end(); it++)
        cout<<*it<<" ";
    cout<<endl<<"set2: ";
    for(auto it=set1.begin(); it != set1.end(); it++)
        cout<<*it<<" ";

    set<int> set3(set2);  // copied
    cout<<endl<<"set3: ";
    for(auto it=set3.begin(); it != set3.end(); it++)
        cout<<*it<<" ";

    set<int> set4 = set1; // copied
    cout<<endl<<"set4: ";
    for(auto it=set4.begin(); it != set4.end(); it++)
        cout<<*it<<" ";

    cout<<"updated set 4: "<<endl<<"set4:";
    auto id = set4.erase(90);
    for(auto it=set4.begin(); it != set4.end(); it++)
        cout<<*it<<" ";

    // returns size_tyoe indicating the number of items removed
    cout<<"removed Items: "<<endl<<id<<endl;


}
