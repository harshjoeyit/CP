/*
A battle is going to begin in the kingdom of Airland. There are
N
N
soldiers in the kingdom, numbered
1
1
through
N
N
and standing in a circle in such a way that for each valid
i
i
, the soldier directly to the right of the
i
i
-th soldier is soldier
i+1
i+1
, and the soldier directly to the right of the
N
N
-th soldier is soldier
1
1
.
Each soldier holds a sword and a shield. The sword is used to attack other soldiers and the shield is used to defend from attacks. Let's denote the attack value of the
i
i
-th soldier's sword by
a
i
ai
and the defense value of the
i
i
-th soldier's shield by
d
i
di
.
In the battle, each soldier picks one of the soldiers standing to his left and right, and attacks that soldier. The choices of the soldiers are completely independent, so each soldier can be attacked by the soldier to his left, by the soldier to his right (the power of such an attack is the attack value of the attacking soldier's sword), by both of them (then, the power of the resulting attack is the sum of the attack values of these soldiers' swords) or by nobody. A soldier remains alive if the defense value of his shield is strictly greater than the power with which he is attacked. Everyone attacks simultaneously and there is only one round of attacks. Each soldier that remains alive at the end is awarded a laurel.
The king of Airland likes these fights, so the host of the battle promised the king that he can pick one soldier and if the soldier he picks survives the battle, the king receives the shield of that soldier.
Chef is the deputy of the king and you want to help him pick a soldier for the king in such a way that the king receives the best shield (with the greatest defense value). However, if Chef picks a soldier and that soldier does not survive, Chef will be thrown in a snake pit. Therefore, it should be guaranteed that the chosen soldier will survive regardless of the decisions of the other soldiers.
Can you help Chef make the best choice and tell him the defense value of the shield which the king gets, or decide that he can be thrown in the snake pit no matter which soldier he picks?
Input
The first line of the input contains a single integer
T
T
denoting the number of test cases. The description of
T
T
test cases follows.
The first line of each test case contains a single integer
N
N
.
The second line contains
N
N
space-separated integers
a
1
,
a
2
,…,
a
N
a1,a2,…,aN
.
The third line contains
N
N
space-separated integers
d
1
,
d
2
,…,
d
N
d1,d2,…,dN
.
Output
For each test case, print a single line containing one integer ― the best defense value of the shield the king gets, or
−1
−1
if Chef can be thrown in the snake pit.
Constraints
1≤T≤100
1≤T≤100
3≤N≤100
3≤N≤100
1≤
a
i
,
d
i
≤
10
4
1≤ai,di≤104
for each valid
i
i
Subtasks
Subtask #1 (100 points): original constraints
Example Input
2
4
1 1 4 1
3 4 2 1
7
5 4 5 4 5 4 5
3 2 4 7 2 5 9
Example Output
3
-1
Explanation
Example case 1: Soldier
1
1
can be attacked by soldier
2
2
and/or soldier
4
4
. If only soldier
2
2
attacks him, the power of the attack is
1
1
. If only soldier
4
4
attacks him, the power of the attack is
1
1
again. If they attack together, the power of the attack is
2
2
. In each of these cases, soldier
1
1
will live.
Soldier
2
2
can be attacked by soldier
3
3
, with attack power
4
4
. His shield has defense value
4
4
, which is not enough, so in this case, soldier
2
2
would die. The best safe choice is soldier
1
1
, with defense value
3
3
.
Example case 2: No soldier is guaranteed to survive the battle, so the answer is
−1
−1
.
*/

#include<bits/stdc++.h>
using namespace std;

int maxd(int a[101],int d[101],int N)
{
    int maxx=-1;

    if( d[0] > (a[1]+ a[N-1]))
    {
        if(d[0]>maxx)
            maxx=d[0];
    }

    if( d[N-1] > (a[N-2]+a[0]))
    {
        if(d[N-1]>maxx)
            maxx=d[N-1];
    }

    for(int i=1; i<=N-2; i++)
    {
        if( d[i] > (a[i+1]+a[i-1])  )
        {
            if(d[i]>maxx)
                maxx=d[i];
        }
    }
    return maxx;
}

int main()
{
    int T,N,a[101],d[101];
    int ans[101],s=0;
  //  cout<<"input test cases: ";
    cin>>T;

    while(T--)
    {
 //       cout<<"N:";
        cin>>N;

        for(int i=0; i<N; i++)
            cin>>a[i];
        for(int i=0; i<N; i++)
            cin>>d[i];

        ans[s++]=maxd(a,d,N);

    }

  //  cout<<"results\n";
    for(int i=0 ; i<s; i++)
        cout<<ans[i]<<endl;

    return 0;
}
