
/*
find if a set is subset of the another set
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        unordered_map<string, int> m;
        int id = 1;
        for (const auto fc : favoriteCompanies) {
                for (const auto c : fc) {
                        if (m.count(c) > 0) continue;
                        // giving a unique id to every company
                        m[c] = id++;
                }
        }

        vector<bitset<501>> vec;
        for (const auto fc : favoriteCompanies) {
                bitset<501> b;
                // in b all those bit is set if the company is in persons list 
                for (const auto c : fc) {
                        // set bit correspoding to id of the company
                        b[m[c]] = 1;
                }
                vec.push_back(b);
        }

        vector<int> res;
        for (int i = 0; i < vec.size(); ++i) {
                bool flag = true;
                for (int j = 0; j < vec.size() and flag; ++j) {
                        // set is subset of itself 
                        if (i == j) 
                                continue;   
                        // if subset exist
                        if ((vec[i] & vec[j]) == vec[i]) 
                                flag = false;
                }
                if (flag) res.push_back(i);
        }
        return res;
}