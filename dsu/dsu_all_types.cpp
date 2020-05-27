#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e5+10;
pair<int, int> parent[mxN];
int Rank[mxN];
bool bipartite[mxN];

// normal make_set

// void make_set(int v) {
//         parent[v] = v;
// }

// normal find

// int find_set(int v) {
//     if (v == parent[v])
//         return v;
//     return find_set(parent[v]);
// }




// path compression

// int find_set(int v) {
//         if(v == parent[v]) {
//                 return v;
//         }
//         return parent[v] = find_set(parent[v]);
// }

// by Sizee

// void make_set(int v) {
//         parent[v] = v;
//         Size[v] = 1;
// }
// void union_sets(int a, int b) {
//         a = find_set(a);
//         b = find_set(b);
//         if(a != b) {
//                 if(Size[a] < Size[b]) {
//                         swap(a, b);
//                 }
//                 parent[b] = a;
//                 Size[a] += Size[b];
//         }
// }  

// by Rank

// void make_set(int v) {
//         parent[v] = v;
//         Rank[v] = 0;
// }
// void union_sets(int a, int b) {
//         a = find_set(a);
//         b = find_set(b);
//         if(a != b) {
//                 if(Rank[a] < Rank[b]) {
//                         swap(a, b);
//                 }
//                 parent[b] = a;
//                 if(Rank[a] == Rank[b]) {
//                      Rank[a]++;
//                  }
//         }
// }



// saving distances to the leader of the set

// void make_set(int v) {
//         parent[v] = make_pair(v, 0);
//         Rank[v] = 0;
// }

// // returns the leader and the distance to it
// pair<int, int> find_set(int v) {
//         if (v != parent[v].first) {
//                 int len = parent[v].second;
//                 parent[v] = find_set(parent[v].first);
//                 parent[v].second += len;
//         }
//         return parent[v];
// }

// void union_sets(int a, int b) {
//         a = find_set(a).first;
//         b = find_set(b).first;
//         if(a != b) {
//                 if(Rank[a] < Rank[b]) {
//                         swap(a, b);
//                 }
//                 parent[b] = make_pair(a, 1);
//                 if(Rank[a] == Rank[b]) {
//                         Rank[a]++;
//                 }
//         }
// }


// answering queries of type
// is the connected component containing this vertex bipartite?
// in O(1) average
// also vertex could be added to this component - on line queries 

// void make_set(int v) {
//         parent[v] = make_pair(v, 0);
//         Rank[v] = 0;
//         bipartite[v] = true;
// }

// pair<int, int> find_set(int v) {
//         if(v != parent[v].first) {
//                 int parity = parent[v].second;
//                 parent[v] = find_set(parent[v].first);
//                 parent[v].second ^= parity;
//         }
// }

// void add_edge(int a, int b) {
//         pair<int, int> pa = find_set(a);
//         a = pa.first;
//         int x = pa.second;

//         pair<int, int> pb = find_set(b);
//         b = pb.first;
//         int y = pb.second;

//         if(a == b) {
//                 if(x == y) {    // cycle of add length (bipartedness lost)
//                         bipartite[a] = false;
//                 }
//         } else {
//                 if(Rank[a] < Rank[b]) {
//                         swap(a, b);
//                 }
//                 parent[b] = make_pair(a, x^y^1);        
//                 bipartite[a] &= bipartite[b];
//                 if(Rank[a] == Rank[b]) {
//                         ++Rank[a];
//                 }
//         }
// }

// bool is_bipartite(int v) {
//         return bipartite[find_set(v).first];
// }



// storing sets as vectors 
// Thus the sum over all vertices gives O(nlogn) plus O(1) for each request.

// vector<int> lst[mxN];
// int parent[mxN];

// void make_set(int v) {
//     lst[v] = vector<int>(1, v);
//     parent[v] = v;
// }

// int find_set(int v) {
//     return parent[v];
// }

// void union_sets(int a, int b) {
//     a = find_set(a);
//     b = find_set(b);
//     if (a != b) {
//         if (lst[a].size() < lst[b].size())
//             swap(a, b);
//         while (!lst[b].empty()) {
//             int v = lst[b].back();
//             lst[b].pop_back();
//             parent[v] = a;
//             lst[a].push_back (v);
//         }
//     }
// }

