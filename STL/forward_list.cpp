//Forward list in STL implements singly linked list. Introduced from C++11, forward list are useful than other containers in insertion, removal and moving operations (like sort) and allows time constant insertion and removal of elements.
//hat it cannot be iterated backwards.
// no random access

#include<bits/stdc++.h>
using namespace std;

void display(forward_list<int> fl)
{
    cout<<endl;
    for(auto it = fl.begin(); it != fl.end(); it++)
        cout<<*it<<" ";
}


int main()
{
    forward_list<int> fl{2,3,4,5,6,8},fl2{3,5,7,9,11};
    display(fl);

    fl.assign({10,20,300,40,5,0,60,111});
    display(fl);

    fl.push_front(23);// copy operation
    display(fl);
    // new eleement is created in the startin in the list
    // no copy operation
    fl.emplace_front(32); // no emplace _ back()
    display(fl);

    // insert after 

    forward_list<int>::iterator it ;
    
    it = fl.insert_after(fl.begin(),{1,2,3,}); // iterator at the end of the operation it is at 3

    display(fl);

    it = fl.emplace_after(it,55); // added after 3

    display(fl);

    it = fl.erase_after(it); // it is on 55 
    // removes one element after the position oof the iterator passed 

    display(fl);

    //removing a spwcific element from the list;
    fl.remove(55);
    cout<<endl;
    display(fl);

    // IMPORTANT:   ............................
    // remove all the elements that are greater than or equal to 20
    fl.remove_if([](int x){ return x >= 20;}); 

    
    display(fl);

    // adding one list to the other
 
    forward_list<int>   flist1 = {10, 20, 30}, 
                        flist2 = {40, 50, 60}; 
     
    // forward list 1 is added to the list 2 after the begin element after 1st position 
    flist2.splice_after(flist2.begin(),flist1); 

    display(flist2);

    // merge() :- This function is used to merge one forward list with other. If both the lists are sorted then the resulted list returned is also sorted.
    // mergin two lists

    fl2 = fl;  // operation works in all sequential conatainers
    fl.merge(fl2);

    display(fl);

    // sorting the list
    fl.sort();
    display(fl);

    //4. unique() :- This function deletes the multiple occurrences of a number and returns a forward list with unique elements.
    // The forward list should be sorted for this function to execute successfully.

    // deletes duplicate elements 
    fl.unique();
    display(fl);

    //reversing
    fl.reverse();
    display(fl);

    //swap
    //clear
    //empty()  //returns a bool
}