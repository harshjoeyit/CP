#include<bits/stdc++.h>
using namespace std;
const int N = 2e3+5;
bool a[N][N];
int n , m , sx , sy , x , y , r=0;
char tc;
struct no
{
	int xc , yc , xx , yy;
};
int main()
{
	cin >> n >> m >> sx >> sy >> x >> y;
	for(int i =1 ; i <=n ; i++)
		for(int j = 1 ; j<=m ; j++)
		{
			cin >> tc;
			if(tc!='.')a[i][j]=1;
		}
	deque<no> q;
	q.push_back(no{sx,sy,0,0});
	while(!q.empty())
	{
		no t = q.front();
		q.pop_front();
		if(a[t.xc][t.yc] || t.xc<1|| t.yc<1 || t.xc>n || t.yc>m || t.xx>x || t.yy>y) continue;
		a[t.xc][t.yc] = 1;
		r++;
		q.push_front(no{t.xc+1,t.yc,t.xx,t.yy});
		q.push_front(no{t.xc-1,t.yc,t.xx,t.yy});
		q.push_back(no{t.xc,t.yc-1,t.xx+1,t.yy});
		q.push_back(no{t.xc,t.yc+1,t.xx,t.yy+1});
	}
	cout << r;
}