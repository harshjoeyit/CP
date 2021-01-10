

#include<bits/stdc++.h>
using namespace std;

/*
Problem similar to BFS approach of this problem:
    https://leetcode.com/problems/minimum-jumps-to-reach-home/submissions/
*/

/*
Using Extended Euclid Algorithm

The problem can be modeled by means of the Diophantine equation 
of the form mx + ny = d which is solvable if and only if gcd(m, n) 
divides d. Also, the solution x,y for which equation is satisfied 
can be given using the Extended Euclid algorithm for GCD.

For example, if we have a jug J1 of 5 liters (n = 5) and another 
jug J2 of 3 liters (m = 3) and we have to measure 1 liter of water 
using them. The associated equation will be 5n + 3m = 1. First of 
all this problem can be solved since gcd(3,5) = 1

sing the Extended Euclid algorithm, we get values of n and m for 
which the equation is satisfied which are n = 2 and m = -3. These 
values of n, m also have some meaning like here n = 2 and m = -3 
means that we have to fill J1 twice and empty J2 thrice.

Now to find the minimum no of operations to be performed we have 
to decide which jug should be filled first. Depending upon which 
jug is chosen to be filled and which to be emptied we have two 
different solutions and the minimum among them would be our answer.

Solution 1 (Always pour from m liter jug into n liter jug)

-> If empty fill the m litre jug and pour into n liter jug (untill m is empty or n fills).
-> If the m liter jug becomes empty fill it.
-> If the n liter jug becomes full empty it.
-> Repeat steps 1,2,3 till either n liter jug or the m liter jug contains d litres of water.

Solution 1 (Always pour from n liter jug into m liter jug)

Just replace n by m and rest is same

Our ans = min(ans from Solution 1, ans from Solution 2)
*/


// Utility function to return GCD of 'a' 
// and 'b'. 
int gcd(int a, int b) { 
	if (b==0) 
	return a; 
	return gcd(b, a%b); 
} 

/* 
fromCap -- Capacity of jug from which water is poured 
toCap   -- Capacity of jug to which water is poured 
d  -- Amount to be measured */
int pour(int fromCap, int toCap, int d) { 
	// Initialize current amount of water 
	// in source and destination jugs 
	int from = fromCap; 
	int to = 0; 

	// 1 step needed to fill up from jug
	int step = 1;

	// Break the loop when either of the two 
    // jugs has d litre water 
	while (from != d && to != d)  { 
		// Find the maximum amount that can be poured 
		int temp = min(from, toCap - to); 

		// Pour "temp" liters from "from" to "to" 
		to += temp; 
		from -= temp; 

		// Increment count of steps 
		step++; 

		if (from == d || to == d) {
            break; 
        }

		// If first jug becomes empty, fill it 
		if (from == 0) { 
			from = fromCap; 
			step++; 
		} 

		// If second jug becomes full, empty it 
		if (to == toCap) { 
			to = 0; 
			step++; 
		} 
	} 

	return step; 
} 

// Returns count of minimum steps needed to 
// measure d liter 
int minSteps(int m, int n, int d) { 
	// To make sure that m is smaller than n 
	if (m > n) 
		swap(m, n); 

	// For d > n we cant measure the water 
	// using the jugs 
	if (d > n) 
		return -1; 

	// If gcd of n and m does not divide d 
	// then solution is not possible 
	if ((d % gcd(n,m)) != 0) 
		return -1; 

	return min(pour(n,m,d), // n to m 
			pour(m,n,d)); // m to n 
} 






void print(vector<pair<int, int>> path) {
    for(auto p: path) {
        cout << p.first << " " << p.second << endl;
    }
}

// using BFS approach
// the number of items in the path vector, is not the shortest path 
// its just the states 
#define pi pair<int, int> 

void bfs(int a, int b, int target) {
    // to store the visited states 
    set<pi> vis;
    bool solvable = false;
    vector<pi> path;

    queue<pi> q;
    q.push({0, 0});

    while(!q.empty()) {
        auto u = q.front();
        q.pop();

        // doesn't met jug constraints 
        if ((u.first > a || u.second > b || u.first < 0 || u.second < 0)) {
            continue; 
        }

        if(vis.count(u)) {
            continue;
        }

        vis.insert(u);
        path.push_back(u);

        if(u.first == target || u.second == target) {
            solvable = true;
            if(u.first == target && u.second != 0) {
                path.push_back({u.first, 0});
            }
            else if(u.second == target && u.first != 0) {
                path.push_back({0, u.second});
            }
            print(path);
            break;
        }

        // final state not reached
        q.push({u.first, b});
        q.push({a, u.second});

        for (int ap = 0; ap <= max(a, b); ap++) { 
  
            // pour amount ap from Jug2 to Jug1 
            int c = u.first + ap; 
            int d = u.second - ap; 
            // check if this state is possible or not 
            if (c == a || d == 0) {
                q.push({ c, d });
            } 

            // Pour amount ap from Jug 1 to Jug2 
            c = u.first - ap; 
            d = u.second + ap;   
            // check if this state is possible or not 
            if (c == 0 || d == b) {
                q.push({ c, d }); 
            }   
        }

        // empty jug1, jug2
        q.push({u.first, 0});
        q.push({0, u.second}); 
    }

    if(!solvable) {
        cout << "-1\n";
    }
}

// the dfs solution here is for just printing 
// does not guarantee minimum steps, to get min steps, must be modified 
int vis[105][105];
int cap1, cap2, target;
int ans;

int go(int curr1, int curr2) {
    if((curr1 == 0 and curr2 == target) || (curr1 == target and curr2 == 0)) {
        cout << curr1 << " " << curr2 << endl;
        return 1;
    }

    if(vis[curr1][curr2] == 0) {
        cout << curr1 << " " << curr2 << endl;
        vis[curr1][curr2] = 1;
        int ans = 0;
        // empty 1 
        ans = ans | go(0, curr2);
        // empty 2
        ans = ans | go(curr1, 0);
        // fill 1
        ans = ans | go(cap1, curr2);
        // fill 2
        ans = ans | go(curr1, cap2);
        // transfer 2->1
        int postTrans = min(curr1 + curr2, cap1);
        int transferred = postTrans - curr1;
        ans = ans | go(postTrans, curr2 - transferred);
        return ans;
        // transfer 1->2
        postTrans = min(curr1 + curr2, cap2);
        transferred = postTrans - curr2;
        ans = ans | go(curr1 - transferred, postTrans);
        
    }
    else {
        return 0;
    }
}

int main() {
    cin >> cap1 >> cap2 >> target;
    ans = INT_MAX;
    // go(0, 0);
    bfs(cap1, cap2, target);
}