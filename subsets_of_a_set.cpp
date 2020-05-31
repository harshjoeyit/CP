#include<bits/stdc++.h>
using namespace std;


int main()
{
    char Set[] = {'a', 'b', 'c'};
    int n = sizeof(Set)/sizeof(char);
    int s = 1 << n;
    cout << s << endl;
    for(int i = 0; i < s; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == 0 )
            {
                cout << "{} ";
                break;
            }
            else if( (i & (1 << j)) != 0)
                cout << "{" << Set[j] << "}, ";
        }
        cout << endl;
    }
}