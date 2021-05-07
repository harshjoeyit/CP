#include<bits/stdc++.h>
using namespace std;

/*
    Find minimum adjacent swaps to make brackets balanced
    https://www.geeksforgeeks.org/minimum-swaps-bracket-balancing/

    We can solve this problem by using greedy strategies. 
    If the first X characters form a balanced string, we can neglect these characters and continue on. 
    If we encounter a ‘]’ before the required ‘[‘, then we must start swapping elements to balance the string.

    Naive Approach 
    Initialize sum = 0 where sum stores result. Go through the string maintaining a count of the 
    number of ‘[‘ brackets encountered. Reduce this count when we encounter a ‘]’ character. If 
    the count hits negative, then we must start balancing the string. 
    Let index ‘i’ represents the position we are at. We now move forward to the next ‘[‘ at index j. 
    Increase sum by j – i. Move the ‘[‘ at position j, to position i, and shift all other characters 
    to the right. Set the count back to 0 and continue traversing the string. In the end, ‘sum’ will 
    have the required value.

    Time Complexity = O(N^2) 
    Extra Space = O(1)

    Optimized approach to do the same

    Sol - minimum swaps occur when and unbalanced ] is balanced by closest [ to its right
    Ex - ]][][][[  - adj swap 0,1,2
         []]][][[  - adj swap 2,3,4
         [][]]][[  - adj swap 4,5,6
         [][][]][  - adj swap 7, 8
         [][][][]   - ans
    Time O(n), Space O(1)
*/
int minimumNumberOfSwaps(string s) {
    int swaps = 0, cntLeft = 0, cntRight = 0, imbalance = 0;
    for(auto c: s) {
        if(c == '[') {
            cntLeft++;
            if(imbalance > 0) {
                swaps += imbalance;
                imbalance--;
            }
        } else if(c == ']') {
            cntRight++;
            imbalance = cntRight - cntLeft;
        }
    }
    return swaps;
}

/*
    Count minimum reversals to make string balanced
    https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1
    

      we need to count the unbalanced brackets of each type, 
      NOTE: if string length is odd then it is IMPOSSIBLE to pair them 

      now we have count of unbalanced brackets of both type
      if we remove the balanced substrings, what remains is like }}}}...{{
      
      now to balance N EVEN number of unbalanced brancket of any SINGLE type we need N/2 reversals 
      For ex-  }}}}, we need 2 reversals to make {}{}
      For ex = {{, we need 1 reversal to make {}

      when brackets of any type are ODD, 1 remains and rest are paired 
      For ex - {{{, we need 1 reversal to make {}{
      
      Ex => }{{}}}}{}{{{{{
      remove the balanced portion {{}} & {}
      remains - }}}{{{{{
      
      reversals for open brackets - 1, transformed to {}}
      reversals for close brakcets - 2, transformed to {{}{} 

      now the string is - {}}{{}{}
      only two brackets remain unbalanced, both need to be reversed 
      final reversals = 2

      final string = {}{}{}{}
      */

int countRev (string s) {
      int ubOpen = 0, ubClose = 0;
      // ubOpen = unbalanced open brackets 
      // ubClose = unbalanced close brackets 
      if(s.length() % 2 == 1) {
            return -1;
      }
      for(auto c: s) {
            if(c == '{') {
                  ubOpen++;
            } else if(c == '}') {
                  if(ubOpen > 0) {
                        // balance
                        ubOpen--;
                  } else {
                        // unbalanced, no unbalanced bracket found before it
                        ubClose++;
                  }
            }
      }
      
      int revOpen = ubOpen/2;
      int revClose = ubClose/2;
      int revFinal = ubOpen%2 + ubClose%2;

      return  revOpen + revClose + revFinal;
}

int main() {

}