// using iterators of string and vectors

#include<vector>
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main()
{
// initializing technique
    vector<int> vec={10,20,3,40,50,60};
    string str("harshit gangwar");
// will be defined later  string::iterator sit;

    vector<string> vstr={"sam is","a good boy.","","and also smart"};
// running the loop until line break 0r(empty string is obtained)
    for (auto svit=vstr.begin();  !svit->empty();   ++svit)   // if vstr.cbigin is used then the iterator becomes a constant iterator
    {                                                           // and its value can not be changed to uppercase
        for(int i=0; i< (*svit).size(); i++)                    // here *svit is a string , so we can use index
           (*svit)[i]= toupper((*svit)[i]);                     // using INDEX
           cout<<*svit<<endl;
    }

    cout<<endl;

    for (auto svit=vstr.begin();  !svit->empty();   ++svit)     // using iterator and another variable string
    {
        string str1(*svit);
        for(auto sit=str1.begin(); sit< str1.end() ; sit++)
            *sit= toupper(*sit);
            cout<<str1<<endl;
    }

     cout<<endl;
                                                                  // using iterator only for string
    for (auto svit=vstr.begin();  !svit->empty();   ++svit)
    {
        for(auto sit= (*svit).begin(); sit<(*svit).end() ; sit++)
            *sit= toupper(*sit);
            cout<<*svit<<endl;
    }




return 0;
}
