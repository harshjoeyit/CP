#include<bits/stdc++.h>
using namespace std;
#define int long long int

class Nums {
    public: 
    int val;
    Nums(int val = 0) {
        this->val = val;
    }
    int getBit(int i) {
        i = 39-i;
        return ((val >> i) & 1);
    }
    void setBit(int i, int state) {
        i = 39-i;
        val |= (1 << i);
        if(state == 0) {
            val ^= (1 << i);
        }
    }
    int operator & (Nums const &n) { 
		return (n.val)&(this->val);
	} 
};
Nums x, y, L, R;

int F(Nums x, Nums y, Nums z) {
    return ((x&z)*(z&y));
}


void solve() {
    cin >> x.val >> y. val >> L.val >> R.val;

    int k = 0;
    while(k < 40 && L.getBit(k) == R.getBit(k)) {
        ++k;
    }
    
    // k is the first diff bit from the right side 
    // cout << k << endl;
    int ans = 0;
    Nums ans_z(L);
    Nums z1(L), z2(R);

    // cout << z1.val <<" " << z2.val << endl;

    for(int l=k+1; l<40; l++) {
        if(L.getBit(l) == 0) {
            z1.setBit(l, 1);
        }

        for(int i=l+1; i<40; i++) {
            if(x.getBit(i) == 0 && y.getBit(i) == 0) {
                z1.setBit(i, 0);
            } else {
                z1.setBit(i, 1);
            }
        }

        int temp_ans = F(x, y, z1);
        if(temp_ans > ans) {
            ans = temp_ans;
            ans_z = z1;
        }
        // cout << "z1: " << z1.val << endl;
    }

    for(int l=k+1; l<=40; l++) {
        if(R.getBit(l) == 1) {
            z2.setBit(l, 0);
        }
        
        for(int i=l+1; i<40; i++) {
            z2.setBit(i, 0); 
        }

        int temp_ans = F(x, y, z2);
        if(temp_ans > ans) {
            ans = temp_ans;
            ans_z = z2;
        }
        // cout << "z2: " << z2.val << endl;
    }
    if(F(x, y, R) > ans) {
        ans_z = R;
    }

    cout << ans_z.val << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}