#include<bits/stdc++.h>
using namespace std;

vector<int> G[300000];
bool vis[300000];

void DFS(int u)
{
    for(int &v: G[u])
        if(!vis[v])
        {
            vis[v] = 1;
            DFS(v);
        }
}

int components(int nodes)
{
    int k = 0;
    for(int i = 1; i <= nodes; i++)
    {
        if((G[i].size() > 0) && !vis[i])
        {
            vis[i] = 1;
            DFS(i);
            ++k;
        }
    }
    return k;
}

int main()
{
    int n, k = 0;
    cin >> n;
    
    map<char, int> m;
    for(int i = 1; i <= 26; i++)
        m[(char)(i-1 + 'a')] = i;

    string s;
    for(int i = 27; i < n+27; i++)
    {
        cin >> s;
        int v, u = i;
        for(char &c: s)
        {
            v = m[c];
            G[u].push_back(v);
            G[v].push_back(u);
        }
    }

    cout << components(n+26) << endl;
}

// solution using sets




// int n;
// 	cin>>n;
// 	for(int i=1;i<=n;++i){
// 		string s;
// 		cin>>s;
// 		for(char c:s){
// 			x[c-'a']=i;
// 		}
// 	}
// 	set<int>s;
// 	for(int i=0;i<26;++i){
// 		if(x[i]!=0){
// 			s.insert(x[i]);
// 		}
// 	}
// 	cout<<s.size();




// using DSU




// #include<bits/stdc++.h>
 
// const int N=200005;
 
// int n,f[N],id[30];
// char str[55];
 
// int find(int x)
// {
// 	return f[x]==x?x:f[x]=find(f[x]);
// }
 
// int main()
// {
// 	scanf("%d",&n);
// 	for (int i=1;i<=n;i++)
// 	{
// 		f[i]=i;
// 		scanf("%s",str);
// 		int k=strlen(str);
// 		for (int j=0;j<k;j++)
// 		{
// 			int t=str[j]-'a';
// 			if (!id[t]) id[t]=i;
// 			else f[find(i)]=find(id[t]);
// 		}
// 	}
// 	int ans=0;
// 	for (int i=1;i<=n;i++) ans+=f[i]==i;
// 	printf("%d\n",ans);
// 	return 0;
// }