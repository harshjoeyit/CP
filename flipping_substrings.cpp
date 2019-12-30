#include<bits/stdc++.h>
using namespace std;

// fliping the 0 and 1s in the substring and counting pairs where s[i] == s[i+1]
// approach

// case 1: 0010
// Here are all possible u we can have for all [L,R]
// 1010 - 0   A
// 1110 - 2   B
// 1100 - 2   C
// 1101 - 1   D
// 0110 - 1   E
// 0100 - 1   F
// 0101 - 0   G
// 0000 - 3   H
// 0001 - 2   I
// 0011 - 2   J
//        = 14
// ‘00’ this duplicate pair will remain duplicate if this range entirely gets flipped to ‘11’ or didn’t get flipped at all and remain ‘00’ which is happening B, C, D, H, I, J. i.e. 6 times so in final ans it will correspond to += 6.
// Lets generalise this number 6. Total number of ranges we have is (n*(n+1))/2 since ranges of size n is 1, n-1 is 2, n-2 is 3 and so on till n so summing them up we get it. Now from all range we want to subtract the ones which are partially flipping our ‘00’ duplicate pair. Visualising it is easier that there will be n such pairs one from. So making it overall ans += (n*(n+1))/2 - n

// In case the values are not same so ‘01’ then if there’s a partial flip then it can change our value to duplicates ‘00’ ‘11’ and we already calculated how many partial overlaps can be there it is n. So in this case ans += n. In this example B, E, H, I corresponds to it.
#define int long long int

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size(), ans = 0;
        for (int i = 1; i < n; ++i)
        {
            if (s[i] == s[i-1]) ans += ((n*(n+1))/2 - n);
            else ans += n;
        }
        cout << ans << '\n';
    }
}