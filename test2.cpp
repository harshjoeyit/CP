#include<bits/stdc++.h>
using namespace std;

class Circle {
public: 
      // constructor 
      Circle(int _x = 0, int _y = 0, int _radius = 0)
            : x(_x), y(_y), radius(_radius) { }

      // overloading << 
      ostream &operator << ( ostream &os ) {        
            os << "\n";
            os << "The Radius is "<< this->radius << ",\n";
            os << "X-coordinate is " << this->x << ",\n";
            os << "Y-coordiante is " << this->y << "\n\n";
            return os;
      }

      // overloading >> 
      istream &operator >> ( istream &input ) {
            cout << "\nCreating new Circle\n";
            cout << "Enter radius: ";
            input >> this->radius;
            cout << "Enter X-coordinate: ";
            input >> this->x;
            cout << "Enter Y-coordinate: ";
            input >> this->y;
            cout << "New Circle created \n\n";

            return input;
      }

      // overlaoding + 
      Circle operator + (const Circle &rhs) {
            Circle c;
            c.radius = this->radius + rhs.radius;
            c.x = this->x + rhs.x;
            c.y = this->y + rhs.y;
            return c;
      }

      bool operator < (const Circle &rhs) {
            // true if first radius < second radius 
            // else false
            return this->radius < rhs.radius;
      }

private: 
      int x, y, radius;
};


int main() {
      Circle c1(2, 3, 10);
      // printing 1st circle 
      c1 << cout;

      Circle c2;
      c2 >> cin;
      // printing 2nd circle 
      c2 << cout;

      // using + operator 
      // corresponding fields added 
      Circle c3 = c1 + c2;
      c3 << cout;

      // using < 
      if(c1 < c2) {
            cout << "Circle c1 is smaller than c2\n";
      } else {
            cout << "Circle c1 is not smalles than c2\n";
      }

      
}