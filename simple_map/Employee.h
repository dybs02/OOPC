#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include <string>

using namespace std;

class Employee {
  public:
    string name;
    string position;
    int age;
    Employee(string name = "", string position = "", int age = 0);
  private:

};

#endif