#include<bits/stdc++.h>
using namespace std;

void pointerprint(pair<int,int> *p1,pair<int,int> *p2)
{
    cout<<"using a pointer\n";
    cout<<"Index\tValue"<<endl;
    while(p1<=p2)
    {
        cout<<"  "<<p1->first<<"\t"<<p1->second<<endl;  // arrow operator needed to be used since actual
         ++p1;                                               // it was coming out to be (*p.)first
                                                         // which is correct as p->first
    }
}

void input(pair<int,int> Pair[],int a[])
{
    for(int i=0; i<5; i++)
    {
        Pair[i].first=i;
        Pair[i].second=a[i];
    }
}

void change(pair<int,int> Pair[])  // values passed with reference in pairs
{
    for(int i=0; i<5; i++)
    {
        Pair[i].first=i*Pair[i].first;
        Pair[i].second =2*Pair[i].second ;
    }
}

void printpair(pair<int,int> Pair[])
{
    cout<<"Index\tValue"<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<"  "<<Pair[i].first<<"\t"<<Pair[i].second<<endl;
    }
}


// returning a pair
pair<int,string> f1( int x = 0, string s = "error")
{
    if(x == 0)
        return {x , s};   // returning via initializer list  
    else
        return pair<int,string>( 404 , "poage not found");// function for creating a pair 
}


main()
{
    pair<int,int> Pair[5];
    int a[]={10,21,52,46,78};

    input(Pair,a);
    printpair(Pair);
    change(Pair);
    printpair(Pair);

    pair<int,int> *prpt1= &Pair[0],*prpt2= &Pair[4];

    pointerprint(prpt1,prpt2);

    //similar to vectors

    pair<int,char> g1;         //default
    pair<int,char> g2(1, 'a');  //initialized,  different data type
    pair<int,char> g3(g2);    //copy of g3 made in g4

    pair<int,string> sup(1,"captain america");
    cout<<endl<<sup.first<<". "<<sup.second<<endl;

    pair<int, int>pair1 = make_pair(1, 12);
    pair<int, int>pair2 = make_pair(9, 12);


    cout << (pair1 == pair2) <<" "; //0
    cout << (pair1 != pair2) << " "; //1
    cout << (pair1 >= pair2) <<" "; //0  /*  following 4 operators compare
    cout << (pair1 <= pair2) <<" "; //1     only
    cout << (pair1 > pair2) <<" "; //0      pair_name.first
    cout << (pair1 < pair2) <<" ";  //1         values        */

    cout<<endl<<pair1.first<<","<<pair1.second<<endl;
    pair1.swap(pair2) ;
    cout<<"swapped"<<endl<<pair1.first<<","<<pair1.second<<endl;

    pair<float, pair<int,int> > edge;  // pair is pair of float and pair
    edge.first=2.345;
    edge.second.first = 1;
    edge.second.second = 2;



    // default initialized to zero , or empty in case of string
    pair<int,float> ifl;
    cout<<"pair: "<<ifl.first<<" "<<ifl.second<<endl;

    auto p1 = make_pair(1,"die");
    auto p2 = make_pair(1,"kill");
    cout<<"pair1: "<<p1.first<<"-"<<p1.second<<endl;
    cout<<"pair2: "<<p2.first<<"-"<<p2.second<<endl;
    
    // comparison is made inthe basis of 1st element first
    // if unequal , the one with the greater value is the greater pair
    // if equal then the comparison is made on the basis of 2nd element
    // similarly
    if(p1>p2)
        cout<<"p1>p2"<<endl;
    else
        cout<<"p2>p1"<<endl;

    // returning values and initializing a pair
    auto pr = f1();          // since two values are returned , 
                            // pr is a pair
    cout<<"error "<<pr.first<<"-"<<pr.second<<endl;   

    // returning a pair 
    auto P = f1(404);
    cout<<"pair: "<<P.first<<"-"<<P.second<<endl;


}
