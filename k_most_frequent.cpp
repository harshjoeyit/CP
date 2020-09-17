#include<bits/stdc++.h>
using namespace std;
#define int long long int


/*
      find k most frequent elements 
*/

vector<int> topKFrequent(vector<int>& nums, int k) {
      vector<int> res;
      if (!nums.size()) {
          return res;
      }

      unordered_map<int, int> cnt;
      for (auto num : nums) {
          cnt[num]++;
      }

      // maximum buckets can be size since 
      // every element can be unique 
      vector<vector<int>> bucket(nums.size() + 1);

      for (auto p : cnt) {
          // store the elements with same frequencies in the same bucket 
          bucket[p.second].push_back(p.first);
      }
      
      // bucket size is the frequency 
      // start from the largest bucket size
      // since these are the elements with largest frequencies 
      for (int i = bucket.size() - 1; i >= 0; --i) {
          for (int j = 0; j < bucket[i].size(); ++j){
              // fill the elements from the bucket utill size is equal to k
              res.push_back(bucket[i][j]);
              if (res.size() == k) return res;
          }
      }
      return res;
}


vector<string> topKFrequent(vector<string>& words, int k) {
      unordered_map<string, int> freq;
      // store the frequencies of words 
      for(auto w : words){
            freq[w]++;
      }

      auto comp = [&](const pair<string,int>& a, const pair<string,int>& b) {
            // return a.second > b.second || (a.second == b.second && a.first < b.first);
            // compare by frequency 
            if(a.second == b.second) {                      
                  return (a.first < b.first);
            }       
            // if frequency equal compare normally                      
            return (a.second > b.second);                   
      };
      typedef priority_queue< pair<string,int>, vector<pair<string,int>>, decltype(comp) > custompq;
      custompq pq(comp);
      
      // inserting only k elements with hightest frequencies 
      for(auto w : freq ){
            pq.emplace(w.first, w.second);
            if(pq.size() > k) pq.pop();                     
      }
      
      vector<string> output;
      while(!pq.empty()){
            output.push_back(pq.top().first);
            pq.pop();
      }
      
      return output;
}


// using buckets 

vector<string> topKFrequent(vector<string>& words, int k) {
      unordered_map<string, int> cnt;
      for(auto word: words) {
            cnt[word] += 1;
      }

      int n = words.size();
      vector<vector<string>> bucket(n + 1, vector<string>());

      for(auto p: cnt) {
            bucket[p.second].push_back(p.first);
      }

      vector<string> ans;
      for (int i = n; i >= 0; i--) {
            for(auto s: bucket[i]) {
                  ans.push_back(s);
                  if(ans.size() == k) {
                        return ans;
                  }
            }
      }

      return ans;
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
}