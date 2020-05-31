#include<bits/stdc++.h>
using namespace std;

template <typename T1, typename T2>
void print(vector<pair<T1, T2>> v)
{
    for(auto x: v)
        cout << "("<< x.first << "," << x.second <<"), ";
    cout << endl;
}
bool comp(pair<string, float> p1, pair<string, float> p2) {
    return (p1.second > p2.second);
}

void groupSplit(vector<pair<string, float>> a) {
    float total = 0;
    float mean;
    for(auto x: a) {
        total += x.second;
    }
    mean = total / a.size();
    // cout << total << endl;
    // cout << mean << endl;
    vector<pair<string, float>> lenders;
    vector<pair<string, float>> borrowers;
    vector<pair<pair<string, string>, int>> transactions;

    for(auto x: a) {
        if(x.second == mean) {
            // neither a lender nor a borrower 
            continue;   
        } else if(x.second > mean){
            x.second -= mean;
            lenders.push_back(x);
        } else {
            x.second -= mean;
            x.second = abs(x.second);
            borrowers.push_back(x);
        }
    }

    sort(lenders.begin(), lenders.end(), comp);
    sort(borrowers.begin(), borrowers.end(), comp);
    cout << mean << "\n";

    int amount;
    for(auto borrower: borrowers) {
        for(auto &lender: lenders) {
            if(lender.second == 0) {
                continue;
            } else if(borrower.second > 0) {
                amount = min(lender.second, borrower.second);
                lender.second -= amount;
                borrower.second -= amount;
                transactions.push_back({{borrower.first, lender.first}, amount});
            } else {
                break;
            }
        }
    }

    for(auto trans: transactions) {
        cout << trans.first.first << " --" << trans.second << "--> "<< trans.first.second << "\n";
    }
}

int main() {
    int n;
    cin >> n;
    vector<pair<string, float>> a;
    for(int i=0; i<n; i++) {
        string name;
        float val;
        cin >> name >> val;
        a.push_back({name, val});
    }
    // a.push_back({"a", 60});
    // a.push_back({"b", 120});
    // a.push_back({"c", 30});
    // a.push_back({"d", 20});
    // a.push_back({"e", 10});
    // a.push_back({"f", 0});
    
    groupSplit(a);
}