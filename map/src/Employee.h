#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include <iostream>
#include <string>

class Employee {
public:
    std::string name;
    std::string position;
    int age;
    Employee(std::string name = "", std::string position = "", int age = 0);
private:
    friend std::ostream& operator<<(std::ostream& s, const Employee& employee);
};

#endif