#include <iostream>
#include <string>
using namespace std;

class Person{
public:
    string name;
    int age;
    Person(){
        cout << "Person class constructor" << endl;
    }
};

class Student: public Person{
public:
    double cgpa;
    Student(){
        cout << "Student class constructor" << endl;
    }
    void getInfo(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "CGPA: " << cgpa << endl;
    }
};

int main(){
    Student s1;
    s1.name = "Manik";
    s1.age = 20;
    s1.cgpa = 8.98;
    s1.getInfo();
    return 0;
}