/*

Chef is fan of pairs and he likes all things that come in pairs. He even has a doll collection in which all dolls have paired.One day while going through his collection he found that there are odd number of dolls. Someone had stolen a doll!!!
Help chef find which type of doll is missing..
Input
The first line contains the number of test cases.
Second line of the input contains the number of elements in the array.
The next n lines are the types of each doll that is left.
Output
Find the type of doll that doesn't have a pair
Constraints
1<=T<=10
1<=N<=100000 (10^5)
1<=ti<=100000
Input:
1
3
1
2
1


Output:
2


Input:
1
5
1
1
2
2
3
Output:
3
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    short int T;
    cin>>T;

    while(T--)
    {
        pair<int,int> dolls[100001]={};  // constraints
        int N,index=1,dolltype1,dolltype2;
        cin>>N;

        cin>>dolltype1;  //for filling up first element of pair array

        dolls[0].first=dolltype1;
        dolls[0].second=1;

        for(int i=0; i<N-1; i++)
        {
            cin>>dolltype2;

            if(dolltype2 == dolltype1)   // checking if next input is same
                dolls[index-1].second += 1;  // incrementing count

            else
            {
                int c=1;

                for(int i=0; i<index; i++)
                {
                    if(dolltype2 == dolls[i].first)
                    {
                        dolls[i].second += 1;  // if the value of type is already present in the pair array then increment it
                        c = 0;
                    }
                }

                if(c)  // if the value of the type is not present the pair array then add it to the next index
                {
                    dolls[index].first = dolltype2;
                    dolls[index++].second = 1;
                    dolltype1 = dolltype2;
                }
            }

        }
                                // printing the value that is unpaired or that is odd
         for(int i=0; i<index; i++)
            if(dolls[i].second % 2 != 0)
                cout<<dolls[i].first<<endl;

    }


    return 0;
}
