/*Write a function that takes a forward_list<string> and two additional string arguments. The function should find the first string and insert the second immediately following the first. If the first string is not found, then insert the second string at the end of the list.*/
#include<bits/stdc++.h>
using namespace std;

void INSERT(forward_list<string> &fl, string first, string second)
{
    forward_list<string>::iterator it,it1;

    int found=0;

    for(it = fl.begin(); it != fl.end(); it1=it , it++ )  // it1 tracks the last element
        if( *it == second)
        {
            found = 1;
        }
    if( found == 1 )
        fl.emplace_after(it,first);
    else
        fl.emplace_after(it1,first);

}

int main()
{
    forward_list<string> fl = {"captain",
                                "hulk",
                                "thanos",
                                "iron_man",
                                "ronin" };
                        
    cout<<endl;

    for(auto it = fl.begin(); it != fl.end(); it++)
        cout<<*it<<endl;

    cout<<endl;

    INSERT(fl,"groot","hulk"); // change second argument (string)

    for(auto it = fl.begin(); it != fl.end(); it++)
        cout<<*it<<endl;

    return 0;
}