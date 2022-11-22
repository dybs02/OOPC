#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>
#include <map>
#include <cmath>

using namespace std;

class Poly {
  public:
    Poly();
    Poly(double d);
    Poly(const Poly& p);
    double operator()(double x) const;
    double& operator[](size_t pos);
    Poly operator+(const Poly& p) const;
    Poly operator-(const Poly& p) const;
    Poly operator-() const;
    Poly operator*(const Poly& p) const;
//    double operator[](size_t pos) const;
  private:
    map<int, double> coef;
    friend Poly operator+(const double& d, const Poly& p);
    friend Poly operator-(const double& d, const Poly& p);
    friend Poly operator*(const double& d, const Poly& p);
    friend std::ostream& operator<<(std::ostream& s, const Poly& p);
};

#endif
