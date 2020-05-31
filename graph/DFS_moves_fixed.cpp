#include <bits/stdc++.h>
using namespace std;

// using DFS when the moves are limited

/*
The mobile application store has a new game called "Subway Roller".

The protagonist of the game Philip is located in one end of the tunnel and wants to get out of the other one. The tunnel is a rectangular field consisting of three rows and n columns. At the beginning of the game the hero is in some cell of the leftmost column. Some number of trains rides towards the hero. Each train consists of two or more neighbouring cells in some row of the field.

All trains are moving from right to left at a speed of two cells per second, and the hero runs from left to right at the speed of one cell per second. For simplicity, the game is implemented so that the hero and the trains move in turns. First, the hero moves one cell to the right, then one square up or down, or stays idle. Then all the trains move twice simultaneously one cell to the left. Thus, in one move, Philip definitely makes a move to the right and can move up or down. If at any point, Philip is in the same cell with a train, he loses. If the train reaches the left column, it continues to move as before, leaving the tunnel.

Your task is to answer the question whether there is a sequence of movements of Philip, such that he would be able to get to the rightmost column.

input
2
16 4
...AAAAA........
s.BBB......CCCCC
........DDDDD...
16 4
...AAAAA........
s.BBB....CCCCC..
.......DDDDD....

output
YES
NO


2
10 4
s.ZZ......
.....AAABB
.YYYYYY...
10 4
s.ZZ......
....AAAABB
.YYYYYY...

YES
NO




logic - stop the train and man can have folowing set of moves only 
{R -right, u - up, d- down}

RURR
RRR
RDRR

*/

int n,k,vis[3][200],f;
string s[3];

void dfs(int x, int y)
{
	if(s[x][y] != '.') 
        return;
	if(y >= n-1) 
        f=1;
	if(y >= n-1 || vis[x][y]) 
        return;
	vis[x][y] = 1;

	if(x && s[x][y+1] == '.' && s[x-1][y+1] == '.' && s[x-1][y+2] == '.' && s[x-1][y+3] == '.') 
        dfs(x-1,y+3);
	
    if(s[x][y+1] == '.' && s[x][y+2] == '.' && s[x][y+3] == '.') 
        dfs(x,y+3);
	
    if(x<2 && s[x][y+1] == '.' && s[x+1][y+1] == '.' && s[x+1][y+2] == '.' && s[x+1][y+3] == '.') 
        dfs(x+1,y+3);
}


int main()
{
	ios_base::sync_with_stdio(0); cin.clear();

	int t;
	cin >> t;

	while(t--){
		cin >> n >> k;
		int x = 0;
		for(int i=0;i<3;i++){
			cin >> s[i];
			if(s[i][0] == 's'){
				x=i; s[i][0] = '.';
			}
			s[i] += "...";
		}
		f = 0; memset(vis,0,sizeof vis);
		dfs(x,0);
		cout << (f?"YES\n":"NO\n");
	}
}