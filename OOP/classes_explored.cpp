#include<iostream>
using namespace std;

class Node {
      friend class Queue;     
private:
      int data;
      Node *Next;
      void print() {
            cout << data << endl;
      }
public:
      Node(int d = 0, Node *n = NULL) : data(d), Next(n) {
      }
      void init(int d , Node *n ) {
            data = d;
            Next = n;
      }
      void display() {
            cout << data << endl;
      }
};

class Queue {
private: 
      Node *Front;
      Node *Rear;
public: 
      Queue(Node *f = NULL, Node *r = NULL) : Front(f),  Rear(r) {
      }
      void init(Node *f, Node *r) {
            Front = f;
            // can access private data 
            Front->data += 1;
            Rear = r;
            Rear->data += 2;
      }
      void printQueue() {
            Node *temp = Front;
            while(temp != NULL) {
                  // can access private print 
                  temp->print();
                  temp = temp->Next;
            }
      }
};

// ......................................................

int a = 120, d = 56;
class arbit {
      int a, b, c;
public: 
      arbit() {
            a = 5;
            b = 1;
            c = 3;
      }
      void show(int c) {
            int b = 10;
            // Lookup for a variable starts like 
            // 1. in the function
            // 2. in the class 
            // 3. then global 
            cout << a << " " << b << " " << c << " " << d << endl;
            
            int a = 50;
            cout << a << " " << b << " " << c << endl;

            // class vars 
            cout << arbit::a << " " << arbit::b << " " << arbit::c << endl;
            arbit::a = 97;
            cout << this->a << " " << this->b << " " << this->c << endl;
            
            // global object
            cout << ::a << endl;
      }
};



// typenames
typedef string Type;
/*string*/ 
Type initVal(); 
class Exercise { 
    public:    
    typedef double Type;    
    //double     double
    Type setVal(Type); 
    //double   
    Type initVal(); 
    private: 
        int val; 
}; 


int main() {
    Node *Node1 = new Node();
    Node *Node2 = new Node();
    Node *Node3 = new Node();    
    Node1->init(10, Node2);
    Node2->init(20, Node3);
    Node3->init(30, NULL);
    Queue *Q = new Queue();
    Q->init(Node1, Node3);
    Q->printQueue();

    arbit A;
    A.show(65);
}

