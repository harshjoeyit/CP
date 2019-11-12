#include<bits/stdc++.h>
using namespace std;

struct abc
{
    int a;
    int b;
};

// ..............coMPARATORS..................

bool comp(int x,int y)  // compares two int according to
{
    if(x<y)        // this condition if x<y it remains the way it is
        return true;     // because x is preceding element in the array
    else
        return false;
}

bool comp2(int x,int y)
{
    if(x>y)        // this condition if x>y it remains the way it is
        return true;     // because x is preceding element in the array
    else
        return false;
}

bool comp3(int x,int y)
{
    if(x%10 > y%10)
        return true;
    else
        return false;
}

bool comp4(abc x,abc y)
{
    if(x.a > y.a)
        return true;

    else
    if(x.a == y.a)
    {
        if(x.b>y.b)
            return true;
        else
            return false;
    }
    else
        return true;  // following is more elegant code does similar task

   /* if(x.a != y.a)
        return (x.a<y.a);
    else   // (x.b == y.b)
        return (x.b<y.b);*/
}

bool comp5(pair<int,int> x,pair<int,int> y)
{
    if(x.second > y.second)
        return true;
    else
        return false;
}

        //...............PRINT...............

// for strings
void print1(vector<string> vec)
{
    for(auto it=vec.begin(); it!=vec.end(); it++)
    {
        cout<<*it<<" ";
    }
}
// for vec int
void print(vector<int> vec)
{
    for(auto it=vec.begin(); it!=vec.end(); it++)
    {
        cout<<*it<<" ";
    }
}
// for arr int
void print2(int a[],int s)
{
    for(int i=0; i<s; i++)
    {
        cout<<a[i]<<" ";
    }
}

void printpair(pair<int,int> Pair[])
{
    cout<<endl<<"Index\tValue"<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<"  "<<Pair[i].first<<"\t"<<Pair[i].second<<endl;
    }
}


// ....................  MAIN        ........................


int main()
{
    int a[]={43,12,56,72,20,65,31};
    vector<int> vec = {12,33,54,50,18,26,49};
    vector<string> vec1 = {"harsh","gan","raj","ramu","junior"};
    vector<string> vec2 = {"11","111","10","12","2","21"};

    sort(begin(a)+2,end(a)-2); // sorts 2 less from start and end
    print2(a,7);
    cout<<endl;

    // for array
    sort(begin(a),end(a)); // sorts all
    print2(a,7);
    cout<<endl;

    // default ascending
    sort(vec.begin(),vec.end());
    print(vec);
    cout<<endl;
    // descending
    sort(vec.begin(),vec.end(),greater<int>());
    print(vec);
    cout<<endl;
    // ascending
    sort(vec.begin(),vec.end(),comp);  // comp passes a pointer to the function here
    print(vec);
    cout<<endl;
    // descending
    sort(vec.begin(),vec.end(),comp2);
    print(vec);
    cout<<endl;
    // sorting according to digit at ones place
    sort(vec.begin(),vec.end(),comp3);
    print(vec);
    cout<<endl;
    //vec1
    //  sorting lexicographically  : like dictionary
    sort(vec1.begin(),vec1.end());
    print1(vec1);
    cout<<endl;
    // numbers can also be sorted like words
    sort(vec2.begin(),vec2.end());
    print1(vec2);
    cout<<endl;


    // PAIR

    pair<int,int> Pair[10];
    int arr[]={65,10,46,21,52};

    for(int i=0; i<10; i++)
    {
        Pair[i].first=i;
        Pair[i].second=arr[i];
    }

    pair<int,int> *prpt1= &Pair[0],*prpt2= &Pair[5];  // +1 index of the actual index filled in prpt2..should be logically [4]
    sort(prpt1,prpt2,comp5);
    printpair(Pair);  // Pair[i] reshuffle according to the values in the sorted pair array

    // structure
    int n1,n2;
    abc obj[4];
    cout<<"\narray of structures\nint a,int b\n";
    for(int i=0; i<4; i++)
    {
        cin>>n1>>n2;
        obj[i].a = n1;
        obj[i].b = n2;
    }

    abc *p1,*p2;
    p1=&obj[0];
    p2=&obj[4];

    sort(p1,p2,comp4);
    cout<<"sorted as ex - (a,b) (c,d)  a>b,if a=b, b>d"<<endl;   // (a,b) (c,d)  a>b,if a=b, b>d
    for(int i=0; i<4; i++)
    {
        cout<<"("<<obj[i].a<<","<<obj[i].b<<") , ";
    }


    return 0;
}
