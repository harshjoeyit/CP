#include<iostream>
#include<string>
#include<cctype>
using namespace std;

void process(string *sfptr)
{

}

void output(string *sftpr)
{

}

int main()
{
    string str[] = {"harshit","arpit","rachit", "sumit", "ankit"};
    string *sptr=str;                                                 // pointer to an array may be initialized in this manner

    cout<<"string array: "<<endl;
    for (int i=0; i<4; i++)
    {
        cout<<*sptr<<endl;
        sptr++;
    }

    for(int i=0; i<4; i++)
    {
        int len= str[i].length();
        for(int j=0; j<len; j++)
        {
            if (islower(str[i][j]))
            {
                str[i][j]=toupper(str[i][j]);
                cout<<str[i][j];
            }
        }
        cout<<endl;
    }

//IMPORTANT IMPOARTANT ........

    int a[2]={0,1};
    auto b(a);                             // b is initialized as pointer variable
    cout<<b[0]<<" "<<b[1]<<endl;           // but its value can be printed like an array without '*'
    b[0]=5;
    b[1]=6;                               // if value b i.e. pointer to array changes the corresponding elements also changes
    cout<<b[0]<<" "<<b[1]<<endl;          // changed value prints
    cout<<a[0]<<" "<<a[1]<<endl;          // changed value

    cout<<endl;

    int arr[]={10,20,30,40,50};     // IMPO-->another way to print array
    int *p=&arr[5];                 // index more than or next to defined such as [6] in arr[5] exist and can be used
                                      // but this is error prone
    for(int *i=arr; i!=p; i++)
    {
        cout<<*i<<" at: "<<i<<endl;
    }

    int arr1[]={10,20,30,40,50,60,70,80,90,100,110};
    int *bega= begin(arr1);
    int *enda= end(arr1);


    cout<<"\noutput: ";
    while(bega<enda)               // advantage : we don't have to count the elements to run a loop
    {
        cout<<"alternate value : "<<*bega<<endl;
        cout<<"difference between the position of the pointers : "<<(enda-bega)<<endl;   // just like the iterators
        bega=bega+2;  // skips position like iterator
    }

    cout<<endl;
// ITERESSTING:...............................................
    const int n=10;
    constexpr size_t si=n;
    int arr2[si]={1,2,3,4,5,6,7,8,9,100};
    int *ptr3= arr2 +2;
    int *ptr2 = arr2 + si;       // do not dereference
    cout<<*ptr3<<"<--at index 2 "<<endl;                   // prints the value at the index 0+s;

        int arryy[]={10,20,30,40,50,60};

    int *pp1=&arryy[1];
    int *pp2=&arryy[5];

    cout<<*pp1<<" "<<*pp2<<endl;
    pp1 += pp2 - pp1;
    // since we can not use the '+' so we use this
    cout<<*pp1<<" "<<*pp2;        // simply means that p1=p2;


return 0;
}
