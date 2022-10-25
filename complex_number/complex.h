#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <iostream>
#include <ostream>

class Complex {
  public:
    double real;
    double imag;
    Complex();
    Complex(double real, double imag);
    Complex& operator=(double co);
    Complex& operator=(const Complex& s);
    friend std::ostream& operator<<(std::ostream& s, const Complex& c);
private:



};



#endif