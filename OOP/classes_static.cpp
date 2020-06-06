#include<bits/stdc++.h>
using namespace std;

// always declare the static variable outside the class , 
// uninitialized static class members give an error 

class student {
      string name;
      static string college;
      // for value initialization - must be const 
      const static int semeseter = 2;

public: 
      static string hostel;
      // hostel is a non static data member - cannot be 
      // inititalized in the initializer list of a constructor 
      student(string Name="none"): name(Name) {
      }      
      void change_hostel(string new_hostel) {
            this->hostel = new_hostel;
      }
      void change_college() {
            college = "NIT-A";
      }
      void print() {
            cout << this->name << endl;
            cout << this->college << endl;
            cout << semeseter << endl;
            cout << hostel << endl;
            cout << endl;
      }
};
// static member value initialization - 
// doesnt matter if it is private , also type must be mentioned when defining 
string student::college = "MNNIT";
string student::hostel = "M.M.Malviaya";
// gives the redefination error 
// string student::college = "NIT-A";   




class Account {
private:
      string owner;
      double amount;
      static double Irate;
      // constexpr variable definened inside the class
      static constexpr int period = 30;       
      // must inclass initializers for constexpr 
      static const int IFSCcode = 987456;
      double daily_tbl[period];           
      // array size is defined using period
public:
    static double initRate();
      void calculate() {
            amount += amount * Irate;
      }
      static double getrate() { 
            return Irate; 
      }
      static void change_rate( double );
};

// define and initialize static data member 
double Account::Irate = initRate();

double Account::initRate() {
    return 9;
}

void Account::change_rate( double newRate ) {
    Irate = newRate;
}





// use of static 
class employee {
public:
    employee() = default;
    employee( string n ) : name(n) , id( ++empcount ) { }
    void print() {
        cout << id << " "<< name << endl;
    }
private:
    static int empcount; 
    int id;
    string name = "noname" ;
};

// assigning ids using a static member - perfect use of static member 
// empcount cannot be redefind utill there is a public function to do so
int employee::empcount = 0;








int main() {
    auto ptr1 = new student();
    ptr1->print();
    auto ptr2 = new student("Rajeev");
    // static member changed
    ptr2->change_hostel("S.V.Patel");
    ptr2->change_college();
    ptr2->print();
    auto ptr3 = new student("Sahil");
    ptr3->print();
    // static member changed
    student::hostel = "Tondon";
    // private - cannot be accessed and changed 
    // student::college = "NIT-A";  
    auto ptr4 = new student("Kenny");
    ptr4->print();
    // printing 1st after static value changed
    ptr1->print();


    // use -
    Account Ac1;

    employee e1("ramesh") , e2("suresh");
    e1.print();
    e2.print();
}

