#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>
#include <map>

using namespace std;

class Poly {
  public:
    Poly();
    Poly(const Poly& p);
    double& operator[](size_t pos);
//    double operator[](size_t pos) const;
  private:
    map<int, double> coefficients;
    friend std::ostream& operator<<(std::ostream& s, const Poly& p);
};

#endif
