
/*
check if the graph contains hamiltonian path 
*/

#include<bits/stdc++.h>
using namespace std;
  
// in O(N.N!)

bool checkHamiltonian(vector<int> G[], vector<int> nodes) {   
    
    do {
        // check if it possible that there exists a
        // hamiltonian path starts at st and ends at en 
        auto st = nodes.begin();                
        auto en = nodes.end() - 1;              
        int p = nodes.size() - 1, u;

        vector<int> path;
        path.push_back(*st);                    

        for(auto it = st; it != en; it++) {
            u = *it;
            // check if path exists to the next vertex in the permutation 
            bool path_present = false;

            for(int &v : G[u]) {
                if(v == *(it+1)) {
                    path_present = true;
                    path.push_back(v);
                    --p;
                    break;
                }
            }
            if(! path_present)
                break;
        }

        if(p == 0) {
            // all nodes we consumed and there exists a path from st ---> en
            for(auto &i: path) {
                cout << i << " ";
            }
            cout << endl;
            return true;
        }

    } while (next_permutation(nodes.begin(), nodes.end()));
    
    return false;
}


int main()
{
    int n, m, x, y;
    
    cin >> n >> m;
    vector<int> G[n+1];

    for(int i = 0; i < m; i++)
    {
        cin >> x >> y;
        G[x].push_back(y);
       // G[y].push_back(x);
    }

    vector<int> nodes(n);
    for(int i = 0; i < n; i++)
        nodes[i] = i;

    if(checkHamiltonian(G, nodes))
        cout << "path exists\n";
    else
        cout << "does not exist\n";
}