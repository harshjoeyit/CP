#include <bits/stdc++.h> 
using namespace std; 
  
void reverseWords(string str) { 
    stringstream s(str);
    string word; 
    stack<string> st;

    while (s >> word) {
        st.push(word);
    }
    string ans = "";
    while(!st.empty()) {
        word = st.top();
        st.pop();
        ans.insert(ans.length(), word);
        ans.push_back('.');
    }
    ans.pop_back();
    cout << ans << endl;
} 

void reverseUsingSS(string s){
    string s;
    getline(cin, s);
    reverse(s.begin(), s.end());
    stringstream ss;
    ss << s;
    string ans = "", word;
    while (ss >> word) {
        reverse(word.begin(), word.end());
        ans += word + " ";
    }
    cout << ans << endl;
}

void solve() {
    string s;
    cin >> s;
    for(int i=0; i<s.length(); i++)
        if(s[i] == '.')
            s[i] = ' ';
    
    reverseWords(s);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
} 
