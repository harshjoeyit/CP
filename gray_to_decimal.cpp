#include<bits/stdc++.h>
using namespace std;

//sample case gray - 15 (1111)
//          decimal- 10 (1010) 

int main()
{
    int gray, decimal = 0;
    cin >> gray;

    while(gray)
    {
        decimal = decimal ^ gray;
        gray = gray / 2; 
    }
    cout << decimal << endl;
}