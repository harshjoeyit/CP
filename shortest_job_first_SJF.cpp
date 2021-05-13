
/*
    O(nlog(n))
*/

#include<bits/stdc++.h>
using namespace std;

struct job {
    int i, arr, burst;
    int turnAr, wait;   // turn around time and waiting time
};

// Order by burst time (if burst time same, order by arrival time)
// NOTE: Comparisons are reversed because of priority_queue
struct ByBurst {
    bool operator() (const job &a, const job &b) const {
        return (a.burst == b.burst)? (a.arr > b.arr): (a.burst > b.burst);
    }
};

void print(job &exec, int timer) {
    int completionTime = timer + exec.burst;
    int turnAroundTime = completionTime - exec.arr;
    int waitTime = turnAroundTime - exec.burst;
    cout << exec.i << "\t" << exec.arr << "\t" << exec.burst << "\t" << turnAroundTime << "\t" << waitTime << endl;
}

void SJF(vector<job> &jobs) {
    // sort jobs on the basis of arrival times
    auto byArr = [](const job &a, const job &b) {
        return (a.arr == b.arr)? (a.i < b.i): (a.arr < b.arr);
    };
    sort(jobs.begin(), jobs.end(), byArr);

    /*
    Since we always pick the job with shortest burst time from queue
    we need need to order them by burst time in queue (if burst time is same, 
    we pick the one that arrived first)
    */
    priority_queue<job, vector<job>, ByBurst> pq;
    
    int n = jobs.size();
    int timer = 0, finished = 0, i = 0;

    cout << "S.no\tArr\tBurst\tTurn A\tWait\n";
    while(finished < n) {
        // push all jobs into queue that have already arrived
        while(i < n && jobs[i].arr <= timer) {
            pq.push(jobs[i]);
            i++;
        }
        // if no job arrived (CPU will be idle untill next job arrives)
        if(pq.empty()) {
            // idle time [timer..........jobs[i]]
            timer = jobs[i].arr;
            pq.push(jobs[i]);
            i++;
        }

        // CPU executes topmost job from queue (shortest)
        auto exec = pq.top();   pq.pop();
        print(exec, timer);
        timer += exec.burst;
        finished++;
        /*
        IMP: after execution of each job, check if more jobs have arrived (loop back)
        that is why we do not execute all arrived jobs at once in a loop
        */
    }
}

int main() {
    // vector<job> jobs = {{2,4,3},{3,4,2},{1,2,4},{0,0,5}};
    // {i, arr, burst}
    vector<job> jobs = {{1,2,3},{2,0,4},{3,4,2},{4,5,4}};
    SJF(jobs);
}