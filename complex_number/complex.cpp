#include "complex.h"


Complex::Complex() {
    this->real = 0;
    this->imag = 0;
}

Complex::Complex(double real, double imag) {
    this->real = real;
    this->imag = imag;
}

Complex& Complex::operator=(double co)
{
    this->real = co;
    this->imag = 0;
    return *this;
}

Complex& Complex::operator=(const Complex& s)
{
    this->real = s.real;
    this->imag = s.imag;
    return *this;
}

std::ostream& operator<<(std::ostream& s, const Complex& c)
{
    s << "(" << c.real << ", " << c.imag << ")";
    return s;
}