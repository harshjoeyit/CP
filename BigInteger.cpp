#include<bits/stdc++.h>
using namespace std;

class BigInteger {
    string num;

    public:
    friend ostream& operator<<(ostream &os, const BigInteger &n) {
        os << n.num;
    }
    BigInteger(string n = "0") {
        num = n;
    }
    BigInteger operator+(BigInteger const &num1) {
        string a = num;
        string b = num1.num;
        string ans = ""; 

        if (a.length() > b.length()) 
            swap(a, b); 
    
        int n1 = a.length(), n2 = b.length(); 
        
        reverse(a.begin(), a.end()); 
        reverse(b.begin(), b.end()); 
    
        int carry = 0; 
        for (int i=0; i<n1; i++) { 

            int sum = ((a[i]-'0')+(b[i]-'0')+carry); 
            ans.push_back(sum%10 + '0'); 
            carry = sum/10; 
        } 
        for (int i=n1; i<n2; i++) { 
            int sum = ((b[i]-'0')+carry); 
            ans.push_back(sum%10 + '0'); 
            carry = sum/10; 
        } 
        if (carry) {
            ans.push_back(carry+'0'); 
        }

        reverse(ans.begin(), ans.end()); 
        BigInteger c = BigInteger(ans);
        return c;
    }

    BigInteger operator*(BigInteger const &num1) {
        string a = num;
        string b = num1.num;
        string ans = ""; 
        BigInteger c = BigInteger();

        int n1 = a.length(); 
        int n2 = b.length(); 
        vector<int> result(n1 + n2, 0); 
        int i_n1 = 0; 
        int i_n2 = 0; 

        for (int i=n1-1; i>=0; i--) { 
            int carry = 0; 
            int n1 = a[i] - '0'; 
            i_n2 = 0; 

            for (int j=n2-1; j>=0; j--) { 
                int n2 = b[j] - '0'; 
                int sum = n1*n2 + result[i_n1 + i_n2] + carry; 
                carry = sum/10; 
                result[i_n1 + i_n2] = sum % 10; 
                i_n2++; 
            } 
            if (carry > 0) 
                result[i_n1 + i_n2] += carry; 
            i_n1++; 
        } 

        int i = result.size() - 1; 
        while (i>=0 && result[i] == 0) 
        i--; 
    
        if (i == -1) 
            return c;

        while (i >= 0) {
            ans.push_back((char)(result[i--] + '0'));
        }
        
        c.num = ans;
        return c;
    }

};


int main() {
    BigInteger n = BigInteger("12345");
    cout << n << endl;

    BigInteger a = BigInteger("25");
    BigInteger b = BigInteger("25");

    cout << a+b << endl;
    cout << a*b << endl;
}