#include<bits/stdc++.h>
using namespace std;
#define int long long int


vector<string> topKFrequent(vector<string>& words, int k) {
      unordered_map<string, int> freq;
      for(auto w : words){
            freq[w]++;
      }

      auto comp = [&](const pair<string,int>& a, const pair<string,int>& b) {
            // return a.second > b.second || (a.second == b.second && a.first < b.first);
            if(a.second == b.second) {                      // compare by frequency 
                  return (a.first < b.first);
            }                             
            return (a.second > b.second);                   // if frequency equal compare normally
      };
      typedef priority_queue< pair<string,int>, vector<pair<string,int>>, decltype(comp) > my_priority_queue_t;
      my_priority_queue_t  pq(comp);
      
      for(auto w : freq ){
            pq.emplace(w.first, w.second);
            if(pq.size() > k) pq.pop();                 // inserting only k elements with hightest frequencies 
      }
      
      vector<string> output;
      while(!pq.empty()){
            output.push_back(pq.top().first);
            pq.pop();
      }
      
      return output;
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
}