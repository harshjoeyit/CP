#include <bits/stdc++.h>
using namespace std;

int dir[5] = {0, 1, 0, -1, 0};
int rows, cols;

bool exist(vector<vector<char>> &board, string word) {
      if (word.empty()) {
            return true;
      }
      if (board.empty() || board[0].empty()) {
            return false;
      }

      rows = board.size();
      cols = board[0].size();
      for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                  if (dfsSearch(board, word, 0, i, j)) {
                        return true;
                  }
            }
      }
      return false;
}

bool dfsSearch(vector<vector<char>> &board, string &word, int idx, int i, int j) {
      if (i < 0 || i >= rows || j < 0 || j >= cols || word[idx] != board[i][j]) {
            return false;
      }
      if (idx == word.length() - 1) {
            return true;
      } 

      char cur = board[i][j];
      board[i][j] = '*'; // used
      bool search_next = false;
      for(int k=0; k<4; k++) {
            if(dfsSearch(board, word, idx+1, i+dir[k], j+dir[k+1])) {
                  search_next = true;
                  break;
            }
      }
      board[i][j] = cur; // reset
      return search_next;
}

int main()
{
      vector<vector<char>> board =
          {
              {'a', 'b'},
              {'c', 'd'}};

      cout << exist(board, "cdba");
}