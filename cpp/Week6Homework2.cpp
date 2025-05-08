// Xu Cao
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
using namespace std;

class Employee {
private:
    string name;
    int idNumber;
    string department;
    string position;
public:
    Employee();
    Employee(string empName, int idNum, string dept, string pos);
    Employee(string empName, int idNum);
    
    void setName(string);
    void setIDNumber(int);
    void setDepartment(string);
    void setPosition(string);
    
    string getName() const
    { return name; }
    int getIDNumber() const
    { return idNumber; }
    string getDept() const
    { return department; }
    string getPos() const
    { return position; }
};

Employee::Employee() {
    name = "";
    idNumber = 0;
    department = "";
    position = "";
}

Employee::Employee(string empName, int idNum, string dept, string pos) {
    name = empName;
    idNumber = idNum;
    department = dept;
    position = pos;
}

Employee::Employee(string empName, int idNum) {
    name = empName;
    idNumber = idNum;
    department = "";
    position = "";
}

int main() {
    
    string empName1 = "Susan Meyers";
    int empIdNum1 = 47899;
    string empDept1 = "Accounting";
    string empPos1 = "Vice President";
    
    string empName2 = "Mark Jones";
    int empIdNum2 = 39119;
    string empDept2 = "IT";
    string empPos2 = "Programmer";
    
    string empName3 = "Joy Rogers";
    int empIdNum3 = 81774;
    string empDept3 = "Manufactureing";
    string empPos3 = "Engineer";
    
    Employee emp1(empName1, empIdNum1, empDept1, empPos1);
    Employee emp2(empName2, empIdNum2, empDept2, empPos2);
    Employee emp3(empName3, empIdNum3, empDept3, empPos3);
    
    cout << setw(20) << left << "Name" << "ID Number    ";
    cout << setw(20) << left << "Department" << "Position" << endl;
    cout << setw(20) << left << emp1.getName() << emp1.getIDNumber() << "        ";
    cout << setw(20) << left << emp1.getDept() << emp1.getPos() << endl;
    cout << setw(20) << left << emp2.getName() << emp2.getIDNumber() << "        ";
    cout << setw(20) << left << emp2.getDept() << emp2.getPos() << endl;
    cout << setw(20) << left << emp3.getName() << emp3.getIDNumber() << "        ";
    cout << setw(20) << left << emp3.getDept() << emp3.getPos() << endl;
    
    return 0;
}
