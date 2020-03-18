#include<bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    getline(cin, S);

    string word = "hero";
    string word2("xyz");
    
    cout<<"hero first at: "<<S.find(word)<<endl;
    //rfind searches the string from right to left
    cout<<"hero last: "<<S.rfind(word)<<endl;

    cout<<" first at: "<<S.find_first_of(word2)<<endl;
    // 
    cout<<" last at: "<<S.find_last_of(word2)<<endl;
    // first char  that is not any of the characters of the string word 
    cout<<"hero at: "<<S.find_first_not_of(word2)<<endl;
    // only difference in these two functions is that below operates from right to left 
    cout<<"hero at: "<<S.find_last_not_of(word2)<<endl;
    // returns last unmmatched char of word in S 


    // looping thriugh the whole string ti find all the occurances 
    string :: size_type pos = 0;
    string numbers = "0123456789";
    // pos is an additional arguement passed to cheek the start position of the search 
    cout<<"numbers occuring are:  "<<endl;    
    while( (pos = S.find_first_of(numbers,pos)) != string::npos )
    {
        cout<<S[pos]<<" "<<endl;
        ++pos;// move to next char , search start again from there 
    }

    
    
    string line = "iceland + scotland , england , germany";
    auto comma = find(line.cbegin(), line.cend() , ',');
    // imp: to print a sub string , pass the iterators:
    cout<<string(line.cbegin() , comma )<<endl;

}