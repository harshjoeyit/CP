#include<bits/stdc++.h>
using namespace std;
int b[10][10];
void printsoln(int b[][10],int n)
{
    cout<<'[';
    for(int j=0;j<n;j++)
    for(int i=0;i<n;i++)
    if(b[i][j]==1) cout<<i+1<<" ";
    cout<<']'<<" ";
}
bool issafe(int b[][10],int row,int col,int n)
{
    for(int i=0;i<col;i++)
    {
        if(b[row][i]==1) return false;
    }
    int i=row,j=col;
    while(i>=0&&j>=0)
    {
        if(b[i][j]==1) return false;
        i--;
        j--;
    }
    i=row;
    j=col;
    while(i<n&&j>=0)
    {
        if(b[i][j]==1) return false;
        i++;
        j--;
    }
    return true;
}
bool solve(int b[][10],int col,int n)
{
    if(col==n)
    {
        printsoln(b,n);
        return true;
    }
    bool res=false;
    for(int i=0;i<n;i++)
    {
        if(issafe(b,i,col,n))
        {
            b[i][col]=1;
            res=solve(b,col+1,n)||res;
            b[i][col]=0;
        }
    }
    return res;
}
void solvenq(int n)
{
    memset(b,0,sizeof(b));
    if(solve(b,0,n)==false)
    {
        cout<<"-1";
    }
    return;
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	int n;
	cin>>n;
	solvenq(n);
	cout<<endl;
	}
	return 0;
}