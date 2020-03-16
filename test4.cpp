#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define P 998244353
#define N 1000000

int fact[N];
void factorial()
{
    fact[0] = 1;
	fact[1] = 1;
    for(int i = 2; i < N; i++)
        fact[i] = (i * fact[i-1]) % P;
}


int modExp(int x, int n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return modExp((x*x) % P, n/2);
    else
        return (x*modExp( (x*x) % P, (n-1)/2)) % P;
}

int nCr_modP(int n, int r)
{
    if(r == 0)
        return 1;

    int a = fact[n];
    int b = (fact[n-r] * fact[r]) % P;
    return (a * modExp(b, P-2)) % P;
}

int calc(unordered_map<int, int> temp)
{
	int Xor = 0, ans = 0, val, rem;
	auto beg = temp.begin();
	auto en = temp.end();

	for(auto it = beg; it != en; it++)
		Xor = Xor ^ it->second;
	
	if(Xor == 0)
		return 0;
	
	for(auto it = beg; it != en; it++)
	{
		val = it->second;
		if((Xor ^ val) < val)
		{
			rem = val - (Xor ^ val);
			ans += nCr_modP(val, rem);
		}
	}
	return ans;
}

signed main(){
	int t;
	cin >> t;
    factorial();
	while(t--){
		int n, q, x, l, r;
		cin >> n;
	
		vector<unordered_map<int, int>> vmap(n+1);

		for(int i = 1; i <= n; i++)
		{
			cin >> x;
			vmap[i] = vmap[i-1];
			++vmap[i][x];
		}

		cin >> q;
		while(q--)
		{
			cin >> l >> r;
			unordered_map<int, int> temp;
			for(auto it = vmap[r].begin(); it != vmap[r].end(); it++)
			{
				int el = it->first;
				int val = it->second;
				if(vmap[l-1].count(el) == 0)
					temp[el] = val;
				else if((val - vmap[l-1][el]) > 0)
					temp[el] = val - vmap[l-1][el];
			}

			cout << calc(temp) << endl;
		}
	}
}