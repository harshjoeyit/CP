/*All submissions for this problem are available.Vishal loves running. He often visits his favourite Nehru Park and runs for very long distances. On one such visit he found that the number of girls in the park was unusually high. Now he wants to use this as an opportunity to impress a large number of girls with his awesome speed.
The track on which he runs is an
N
N
kilometres long straight path. There are
a
i
ai
girls standing within the
ith
ith
kilometre of this path. A girl will be impressed only if Vishal is running at his maximum speed when he passes by her. But he can run at his best speed only for a single continuous stretch of
K
K
kilometres. Now Vishal wants to know what is the maximum number of girls that he can impress.
Input
First line of the input contains the number of testcases
T
T
.
For each test case,
First line contains two space-separated integers
N
N
and
K
K
, the length of the track and the maximum distance he can run at his best speed.
Second line contains N space-separated integers, the number of girls within each kilometre of the track.
Output
For each test case print one line containing an integer, denoting the maximum number of girls Vishal can impress.
Constraints
1≤T≤10
1≤T≤10
1≤K≤N≤100
1≤K≤N≤100
1≤
a
i
≤100
1≤ai≤100
Sample Input
1
7 2
2 4 8 1 2 1 8
Sample Output
12
Explanation
He can impress 4+8=12 girls if he runs at his best speed between the 2nd and the 3rd kilometre, inclusive */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cout<<"test case T: ";
    cin>>T;

    while(T--)
    {
        int N,K,girls[101]={},maxx=-999;
        cout<<"path km N,K\n";
        cin>>N>>K;
        cout<<"girls/km: ";
        for(int i=0 ;i<N; i++)
            cin>>girls[i];

        for(int i=0; i<=N-K; i++)
        {
            int s=0;
            for(int j=i; j<K+i; j++)
            {
                s = s+girls[j];
            }
            if(s>maxx)
                maxx=s;
        }
        cout<<maxx<<endl;
    }

    return 0;
}
