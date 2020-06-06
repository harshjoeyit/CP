#include<iostream>
using namespace std;

int main()
{
int a[3][4] = {0,1,2,3,4,5,6,7,8};

for(size_t i=0; i<3; i++)
{
    for(size_t j=0; j<4; j++)
    {
        cout<<a[i][j]<<" at :  "<<&a[i][j]<<" \t";
    }
    cout<<endl;
}
cout<<endl;
// better form of the above loop
size_t cnt =0;
for(auto &row : a)           // reference required
    for(auto &col: row)
    cout<<col<<" ";
cout<<endl;

// pointer method to print the access the array

for( auto p=a; p!=a+3; ++p)  // initially p points to the first row of the array and later to the other rows
{                                   // use auto or int *  // we can replace p[0] by *p
    for( auto q=p[0]; q!=p[0]+4; ++q)   //q points points to the  element  of the each row
        cout<<*q<<",";              // ( p[0] ) is the firs element of each row
    cout<<endl;
}
// we can also write the above loop by using the begin() and end()

cout<<endl;
// IMP: reference arrays to each row of the 3d array , can be accessed now
int (&row1)[4]=a[0];
int (&row2)[4]=a[1];
int (&row3)[4]=a[2];

for(size_t i=0; i<4; i++)
{
    cout<<row1[i]<<" "<<row2[i]<<" "<<row3[i];
    cout<<endl;
}
cout<<endl;

int (*p)[4]=a;  // parenthesis necessary since it is a pointer to an array

for(int i=1; i<4; i++)
{
    cout<<"values --> "<<(*p)[i]<<",";  // parenthesis necessary and index too as it prints unnecessary addresses if not put
}



return 0;
}
