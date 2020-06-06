// to input and check the duplicate the

#include<iostream>
#include<vector>
#include<cctype>
#include<string>
using namespace std;


int maximum(int A[50],int s)
{
    int maxim=-999;
    for(int i=0; i<s; i++)
    {
        if(A[i]>maxim)
            maxim=A[i];
    }
    return maxim;
}


int main()
{
    vector<string> anm;
    string animals;

    while(cin>>animals)  //you could use a (ctrl+z) to stop the loop
    {
        anm.push_back(animals);
    }

    string str1,str2;

    int cnt=1,rep=0,a[30],s=0;  //initializing the count to be 1 as every value present will be at least be at one time
    for(auto it1=anm.begin(); it1 != anm.end(); it1++)
    {
        str1=*it1;
        str2=*(it1+1);  // may not chose string works well with iterators

// IMPORATNT:  BUT IF WE ARE WORKING ON A CHARACTER LECVEL THEN STRING IS REQUIRED

        if(str1==str2)  // comparing it to the next variable
        {
            ++rep; // fro repetition
            ++cnt;  //increment  for total no. of occurrences
        }
        else
        {
            a[s]=rep;
             ++s;
            cout<<"count of "<<*it1<<" : "<<cnt<<": repeat = "<<rep<<endl;
            cnt=1;  // changing value to start new counting as the value at i is not equal to i+1
            rep=0;
        }
    }

    cout<<endl<<"max_repeat: "<<maximum(a,s);  // using the function to access the maximum value in the array

}
