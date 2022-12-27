#include "Employee.h"

Employee::Employee(std::string name, std::string position, int age)
{
    this->name = name;
    this->position = position;
    this->age = age;
}

std::ostream& operator<<(std::ostream& s, const Employee& employee)
{
    s << employee.name;
    s << " (" << employee.position << ")";
    s << " (" << employee.age << " yo)";
    return s;
}
