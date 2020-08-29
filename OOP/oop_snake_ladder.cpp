
#include<bits/stdc++.h>
using namespace std;

// Snake Ladder game

class Player {
      string name;
      int position;
public:
      Player(string _name) : name(_name){
            // initially at zero 
            position = 1;
      }
      string getName() {
            return name;
      }
      int getPosition() {
            return position;
      }
      void setPosition(int newPosition) {
            position = newPosition;
      }
};

class SnakeLadderGame {
      // position of player 2 on the
      Player *a, *b;
      // if chance is odd a rolls dice, else b rolls 
      int chance;
      unordered_map<int, int> snakes;
      unordered_map<int, int> ladders;

public:
      SnakeLadderGame(string name1, string name2) {
            a = new Player(name1);
            b = new Player(name2);
            chance = 1;
      }

      void rollDice() {
            int move, sixCnt = 0;
            while ((move = rand() % 6 + 1) == 6) {
                  sixCnt += 1;
            }
            move += sixCnt * 6;
            if(chance % 2 == 0) {
                  movePlayer(a, move);
            } else {
                  movePlayer(b, move);
            }
      }

      void movePlayer(Player *p, int move) {
            // check ladder
            // check snake 
            // if p poistion >= 100 
            // declare winner 
      }

      bool checkLadder(Player *p, move) {
            // check if ladder occur 
            // move p to new position 
            // return true
      }

      void checkSnake(Player *p, int move) {
            // check if snake occurs 
            // move p to new position 
            // return true
      }

      string DeclareWinner(Player *p) {
            if(p == a) {
                  return a->getName() + " wins!";
            } else {
                  return b->getName() + " wins!";
            }
      }
}