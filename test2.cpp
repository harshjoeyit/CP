#include<bits/stdc++.h>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);//Fast I/O for Competitive Programming
cin.tie(NULL);
int n;
cin>>n;
int A[n],B[n];
 
 
for(int i=0;i<n;i++)
cin>>A[i];
 
stack <int> s1;
 
 
for(int i=n-1;i>=0;i--)//VIM
{
 
	while(!s1.empty()&&A[s1.top()]<A[i])
	s1.pop();
 
	if(!s1.empty())
	{
		B[i]=A[i]^B[s1.top()];
	}
	else
	{
		B[i]=A[i];
	}
	s1.push(i);
}
 
int max=0;
for(int i=0;i<n;i++)
{
      cout << B[i] << " ";
if(max<B[i])
max=B[i];
}
cout << endl;
cout<<max;
return 0;
}
