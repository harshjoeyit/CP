#include<iostream>
using namespace std;

void tda(int (*matrix)[4],int rows)
// *matrix is array of pointers which represents all the elements in an array
{
    for(int row=0; row<rows; row++)
    {
        cout<<endl;
        for(int col=0; col<4; col++)
            cout<<matrix[row][col]<<"\t";
    }
    cout<<endl<<endl;
    // printing via pointer:
    for(int row=0; row<rows; row++)
    {
        cout<<endl;
        for(int col=0; col<4; col++)
            cout<<*(matrix)[0]<<"\t";  //whole row prints
        matrix++; // switching to next row:
    }

}

int main()
{
    int matrix[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};

    for(int i=0; i<3; i++)
     {
         cout<<endl;
         for(int j=0; j<4; j++)
             cout<<matrix[i][j]<<"\t";
     }
     cout<<endl;

     tda(matrix,3);
    return 0;
}
