
/*
youtube.com/watch?v=Uvlu1I1bfYo&list=PLfBJlB6T2eOtMXgK3FLUTawHjzpIEySHF&index=5

Each kind of monster has its own unique vocabulary: a list of V different words consisting only of lowercase English letters. 
When a monster speaks, it first forms a sentence of words in its vocabulary; 
the same word may appear multiple times in a sentence. 
Then, it turns the sentence into an enciphered string, as follows:

1. Randomly shuffle each word in the sentence.
2. Remove all spaces.
3. Understanding the monsters can bring you huge advantages,
    so you are building a tool to do that. As the first step, 
    you want to be able to take an enciphered string and determine 
    how many possible original sentences could have generated that enciphered string. 
    For example, if a monster's vocabulary is ["this", "is", "a", "monster", "retsnom"], 
    and it speaks the enciphered string 
            "ishtsiarestmon", 
    there are four possible original sentences:

            "is this a monster"
            "is this a retsnom"
            "this is a monster"
            "this is a retsnom"

You have S enciphered strings from the same monster. For each one, can you figure out the number of possible original sentences?

*/



#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 1e9+7;
const int mxN = 5e5;
int dp[mxN];
set<string> pool;
map<string, int> cnt;
string s;
int LIM, len;

string f(string a) {                        // sort string 
    sort(a.begin(), a.end());
    return a;
}

int go(int pos) {
    int i;
    if(pos == len) {                                        // if pos == 1, then at least one comb occurs previously before index len 
        return 1;
    }
    string cur = "";

    int &ans = dp[pos];
    if(ans != -1) {
        return ans;
    }
    
    ans = 0;
    int to = pos+LIM+1;
    to = min(to, len);                                      // ending index should not exceed word length
    
    for(int i=pos; i<to; i++) {                             // for each index starting from pos - form substrings
        cur += s[i];    
        sort(cur.begin(), cur.end());                       // sort for seaching int the dictionary

        if(cnt[cur]) {                                      // if word is found then
            ans += (cnt[cur] * go(i+1)) % mod;              // (no of combinations with this substring) * (combinations after (this) index i)
            if(ans >= mod) {
                ans -= mod;
            }
        }
    }

    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t, q;
    int ans;
    int mx = 0;
    string word;

    cin >> t;
    for(int z=1; z<=t; z++) {
        cout<<"Case #"<<z<<": ";
        cin >> n >> q;                          // n - words in the dictionary, q queries

        cnt.clear();                            // dictionary
        pool.clear();                           // 
        LIM = 0;

        for(int i=0; i<n; i++) {
            cin >> word;                                // each word of the dictionary
            LIM = max(LIM, (int)word.length());         // largest length of the word
            
            if(pool.find(word) == pool.end()) {
                pool.insert(word);                      // insert as given
                cnt[f(word)]++;                         // sort the word and insert as there may be more than 
                                                        // one words that are permutations of each other in dictionary- "yoj", "ojy" 
            }
        }

        while(q--) {
            cin >> s;
            len = s.size();                             // Cipher
            for(int i=0; i<len+1; i++) {
                dp[i] = -1;
            }
            cout << go(0) << " ";                       // call with 0 index 
        }
        cout << endl;
    }   
}