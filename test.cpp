class Solution {
public:
    ;
    vector<int> parent, Rank;
    
    void makeSet(int n) {
        parent.assign(n, 0);
        Rank.assign(0);
        for(int i=0; i<n; i++) {
            parent[i] = i;
        }
    }
    
    int findSet(int a) {
        if(a == parent[a])  return a;
        return parent[a] = findSet(parent[a]);
    }
    
    void unionSets(int a, int b) {
        a = findSet(a);
        a = findSet(b);
        if(a != b) {
            if(Rank[a] < Rank[b]) {
                swap(a, b);
            }
            parent[b] = a;
            if(Rank[a] == Rank[b]) {
                Rank[a]++;
            }
        }
    }
    
    vector<bool> distanceLimitedPathsExist(
        int n, 
        vector<vector<int>>& el, 
        vector<vector<int>>& ql) {
        
        makeSet(n);
        vector<bool> ans(n, false);
        
        auto comp = [](const vector<int> &a, const vector<int> &b) {
            return a[2] < b[2];
        };
        
        for(int i=0; i<ql.size(); i++) {
            ql[i].push_back(i);
        }
        
        sort(el.begin(), el.end(), comp);
        sort(ql.begin(), ql.end(), comp);
        
        int st = 0;
        
        for(int i=0; i<ql.size(); i++) {
            int limit = ql[2];
            int j = ql[3];
            
            while(st < el.size() && el[st] < limit) {
                // union 
                unionSet(el[0], el[1]);
            }
            
            if(findSet(ql[0]) == findSet(ql[1])) {
                ans[j] = true;
            }
        }
        
        return ans;
    }
    
};