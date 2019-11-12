#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n1,n2,n3, x;
    set<int> s1,s2,s3,s4;
    cin>>n1>>n2>>n3;

    for(int i=0; i<n1; i++)
    {
        cin>>x;
        s1.insert(x);
    }
    for(int i=0; i<n2; i++)
    {
        cin>>x;
        s2.insert(x);
    }
    for(int i=0; i<n3; i++)
    {
        cin>>x;
        s3.insert(x);
    }

    for( auto it = s1.begin(); it != s1.end(); it++ )
    {
        auto it1 = s2.find(*it);
        auto it2 = s3.find(*it);

        if( (it1 != s2.end())  ||  (it2 != s3.end()) )
            s4.insert( *it );
    }

    for( auto it = s2.begin(); it != s2.end(); it++ )
    {
        auto it1 = s3.find(*it);
        if( it1 != s3.end() )
            s4.insert( *it );
    }

    cout<<s4.size()<<endl;  // printing th no. of elements
    for(auto it = s4.begin(); it != s4.end(); it++)
        cout<<*it<<endl;

    return 0;
}

/* Q )
All submissions for this problem are available.
As you might remember, the collector of Siruseri had ordered a complete revision of the Voters List. He knew that constructing the list of voters is a difficult task, prone to errors. Some voters may have been away on vacation, others may have moved during the enrollment and so on. 
To be as accurate as possible, he entrusted the task to three different officials. Each of them was to independently record the list of voters and send it to the collector. In Siruseri, every one has a ID number and the list would only list the ID numbers of the voters and not their names. The officials were expected to arrange the ID numbers in ascending order in their lists. 
On receiving the lists, the Collector realised that there were discrepancies - the three lists were not identical. He decided to go with the majority. That is, he decided to construct the final list including only those ID numbers that appeared in at least 2 out of the 3 lists. For example if the three lists were
23  30  42  57  90
21  23  35  57  90  92
21  23  30  57  90 
then the final list compiled by the collector would be:
21  23  30  57  90
The ID numbers 35, 42 and 92 which appeared in only one list each do not figure in the final list.
Your task is to help the collector by writing a program that produces the final list from the three given lists.
Input format
The first line of the input contains 3 integers N1, N2 and N3. N1 is the number of voters in the first list, N2 is the number of voters in the second list and N3 is the number of voters in the third list. The next N1 lines (lines 2,...,N1+1) contain one positive integer each and describe the first list in ascending order. The following N2 lines (lines N1+2,...,N1+N2+1) describe the second list in ascending order and the final N3 lines (lines N1+N2+2,...,N1+N2+N3+1) describe the third list in ascending order.
Output format
The first line of the output should contain a single integer M indicating the number voters in the final list. The next M lines (lines 2,...,M+1) should contain one positive integer each, describing the list of voters in the final list, in ascending order.
Test data
You may assume that 1 ≤ N1,N2,N3 ≤ 50000.
*/