
/*
find max length even length substring that 
has left half sum == right half sum

queue approach 
there is also O(n2) loop aaproach
*/


#include <bits/stdc++.h>
using namespace std;

struct sub {
    int j, k, left, right;
};

int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        long long left=0,right=0;
        int i, n = s.length();

        for(i=0;i<=(n/2);i++)
            left+=(s[i]-'0');
    
        int mid=i-1;

        for(int j=i;j<n;j++)
            right+=(s[j]-'0');

        int m=1;

    	queue<sub> q;
	    q.push({0, n-1, left, right});
	    
        while(q.size()) {

	        auto p = q.front(); q.pop();
            left = p.left;
            right = p.right;
	        int d = p.k - p.j;

	        if(d <= 0 || left < 0 || right < 0)
	            continue;
	        if(d%2 != 0 && left == right) {                   // index differece is odd - means length is even 
	            m = 0;
	            cout<< d+1 <<endl;
	            break;
            }
	        
	        if(d%2 ==0) {                                   // index diff = even - means length is odd
                q.push({p.j+1 , p.k, 
                        p.left-s[p.j] + '0', p.right });
	            q.push({p.j, p.k-1,
                        p.left-s[mid]+'0', p.right-s[p.k] + s[mid]}); 
            
            } else {
	            q.push({p.j+1 , p.k, 
                        p.left-s[p.j]+s[mid] , p.right-s[mid]+'0'});
	            q.push({p.j , p.k-1, 
                        p.left , p.right-s[p.k]+'0'});
            }
	        
            mid = p.j + (p.j + p.k)/2;
	    }
	
        if(m)
	        cout<<0<<endl;
        }
}


// another approach 
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    
    int l = 0;
    for(int i=0; i<n; i++) {
        int s1 = 0, s2 = 0;
        for(int j=i, k=i+1; j>=0 && k<n; --j, ++k) {
            s1 += (int)(s[j]-'0');
            s2 += (int)(s[k]-'0');
            if(s1 == s2) {
                l = max(l, k-j+1);
            }
        }
    }
    cout << l << endl;
}