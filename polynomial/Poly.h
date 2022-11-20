#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>
#include <map>

using namespace std;

class Poly {
  public:
    Poly();
    Poly(double d);
    Poly(const Poly& p);
    double& operator[](size_t pos);
    Poly operator+(const Poly& p) const;
//    double operator[](size_t pos) const;
  private:
    map<int, double> coef;
    friend std::ostream& operator<<(std::ostream& s, const Poly& p);
};

#endif
