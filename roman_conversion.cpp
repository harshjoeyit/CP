#include <bits/stdc++.h> 
using namespace std; 

int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};             
string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"}; 

void printRoman(int number)  { 
    int i = sizeof(num)/sizeof(num[0]);     // 12

    while(number > 0) { 
        if(number/num[i] != 0) {
            int div = number/num[i]; 
            number = number % num[i]; 
            while(div--) { 
              cout << sym[i]; 
            } 
        }
        i--; 
    } 
    cout << endl;
} 

// return decimal value for a roman char 
int romanToDec(char c) {
    if(c == 'I')        return 1;
    else if(c == 'V')    return 5;
    else if(c == 'X')    return 10;
    else if(c == 'L')    return 50;
    else if(c == 'C')    return 100;
    else if(c == 'D')    return 500;
    else if(c == 'M')    return 1000;
}
/*
    Roman to decimal 
    Observation - In any roman string there cannot be more than two consecutive increasing letters
    Ex - IX, IV (only 2 consecutive increasing letters)
*/
int romanToDecimal(string &str) {
    int i = str.length()-1;
    int ans = 0;
    while(i >= 0) {
        if(i > 0 && romanToDec(str[i-1]) < romanToDec(str[i])) {
            // for cases like IX, IV, CM
            ans += romanToDec(str[i]) - romanToDec(str[i-1]);
            i -= 2;
            continue;
        }
        ans += romanToDec(str[i]);
        i--;
    } 
    return ans;
}
  
//Driver program 
int main() 
{ 
    int number;
    cin >> number;
    printRoman(number); 
  
    return 0; 
} 