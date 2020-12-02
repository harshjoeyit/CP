#include<bits/stdc++.h>
using namespace std;

class Student {
    public:
        string firstName;
        string lastName;
        string rollNo;

        Student(string f, string l, string no) {
            firstName = f;
            lastName = l;
            rollNo = no;
        }
        
        bool operator==(const Student &s) const{
            return rollNo == s.rollNo ? true : false;
        }
};

class HashFn {
    public:
        size_t operator()(const Student &s) const{
            return s.firstName.length() + s.lastName.length();
        }
};
signed main() {

    unordered_map<Student, int, HashFn> studentMap;

    Student s1("Prateek", "Narang", "010");
    Student s2("Rahul", "Kumar", "023");
    Student s3("Aman", "Tibrewal", "064");
    Student s4("Rahul", "Kumar", "123");

    // Add student - marks to hashMap

    studentMap[s1] = 100;
    studentMap[s2] = 50;
    studentMap[s3] = 40;
    studentMap[s4] = 90;

    for(auto s : studentMap) {
        cout << s.first.firstName << " " << s.first.rollNo << endl;
        cout << "Marks " << s.second << endl;
    }
}