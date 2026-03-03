#include <iostream>
#include <string>
using namespace std;

class Teacher{
private:
    double salary;

public:
    string name;
    string dept;

    // non-parameterized constructor
    Teacher(){
        dept = "CSE";
    }

    // parameterized constructor
    Teacher(string dept){
        this->dept = dept;
    }

    // copy constructor
    Teacher(Teacher &orgObj){
        this->name = orgObj.name;
        this->dept = orgObj.dept;
        this->salary = orgObj.salary;
    }
    
    // setter
    void setSalary(int newSalary){
        salary = newSalary;
    }

    // getter
    double getSalary(){
        return salary;
    }
};

int main() {
    Teacher t1;
    t1.name = "Manik";
    t1.setSalary(25000);
    
    cout << t1.name << endl;
    cout << t1.dept << endl;
    cout << t1.getSalary() << endl;

    Teacher t2(t1);
    cout << t2.name << endl;
    return 0;
}