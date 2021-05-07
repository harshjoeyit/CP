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
char getMaxCountChar(vector<int>& count, int maxCount) {
    for (int i = 0; i < 26; ++i)
        if (count[i] == maxCount)
        return 'a' + i;
    throw;
}


// O(n*A) Approach
string reorganizeString(string S) {
    const int n = S.length();

    vector<int> count(26);
    for (const char c : S)
      ++count[c - 'a'];

    const int maxCount = *max_element(begin(count), end(count));
    if (maxCount > (n + 1) / 2) return "";

    string ans(n, ' ');
    const bool shouldFillEvenIndices = maxCount == (n + 1) / 2;

    // fill in 0, 2, 4, ... positions with the maxCount char
    if (shouldFillEvenIndices) {
      const int c = getMaxCountChar(count, maxCount);
      for (int i = 0; i < n; i += 2)
        ans[i] = c;
      count[c - 'a'] = 0;
    }

    // start index of remaining chars should be 0 or 1
    int i = shouldFillEvenIndices;
    for (char c = 'a'; c <= 'z'; ++c)
    while (count[c - 'a']-- > 0) {
        ans[i] = c;
        i += 2;
        if (i >= n)  // out-of-bound, reset the index to 1
            i = 1;
    }

    return ans;
}


int main() {    
    cout << reorganizeString("aabbcc") << "\n";
}
