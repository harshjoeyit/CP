/*
    https://leetcode.com/problems/reorganize-string/
*/

#include<bits/stdc++.h>
using namespace std;

/*
    Using Heap(Priority Queue) - O(nlog(A)) 
    here A is max number of unique chars 
*/
string reorganizeString(string s) {
    int maxf = 0;
    unordered_map<char, int> cnt;
    for(auto c: s) {
        cnt[c]++;
    }

    priority_queue<pair<int, char>> pq;
    for(auto p: cnt) {
        pq.push({p.second, p.first});
        maxf = max(maxf, p.second);
    }
    if(maxf > (s.length() + 1)/2) {
        return "";
    }
    
    string ans = "";
    
    while(!pq.empty()) {
        if(pq.size() > 1) {
            // find top two 
            auto p = pq.top();  pq.pop();
            auto q = pq.top();  pq.pop();
            
            ans.push_back(p.second);
            ans.push_back(q.second);
            
            if(p.first > 1) {
                p.first -= 1;
                pq.push(p);
            }
            if(q.first > 1) {
                q.first -= 1;
                pq.push(q);
            }
        } else {
            // this is the last char remaining
            ans.push_back(pq.top().second);
            pq.pop();
        }
    }
    return ans;
}

// returns most frequent char 
char getMaxCountChar(const vector<int>& count) {
	int maxCnt = 0;
	char ch;
	for (int i = 0; i < 26; i++) {
		if (count[i] > maxCnt) {
			maxCnt = count[i];
			ch = 'a' + i;
		}
	}
	return ch;
}


// O(n*A) Approach
string reorganizeString(string S) {
    int n = S.size();
	if (!n) {
        return "";
    }

	vector<int> count(26, 0);
	for (auto ch : S) {
        count[ch - 'a']++;
    }

	char chMax = getMaxCountChar(count);
	int maxCount = count[chMax - 'a'];

	// check if the result is possible or not
	if (maxCount > (n + 1) / 2) {
        return "";
    }

	string res(n, ' ');
	int ind = 0;

	// filling the most frequently occuring char in the even indices
	while (maxCount) {
		res[ind] = chMax;
		ind = ind + 2;
		maxCount--;
	}
	count[chMax - 'a'] = 0;

	// now filling the other Chars, first filling the even (if remaining)
	// positions and then the odd positions
	for (int i = 0; i < 26; i++) {
		while (count[i] > 0) {
			if(ind > n) {
                // all even pos are filled
                ind = 1;
            }
			res[ind] = 'a' + i;
			ind += 2;
			count[i]--;
		}
	}
	return res;
}


int main() {    
    cout << reorganizeString("aabbcc") << "\n";
}
