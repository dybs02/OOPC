#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <iostream>
#include <ostream>
#include <cmath>
#include <complex>

class Complex {
  public:
    double real;
    double imag;
    Complex();
    Complex(double real);
    Complex(double real, double imag);
    Complex& operator=(const Complex& c);
    Complex operator+(const Complex& c) const;
    Complex operator-(const Complex& c) const;
    Complex operator-() const;
    Complex operator*(const Complex& c) const;
    Complex operator/(const Complex& c) const;
    Complex& operator+=(const Complex& c);
    Complex& operator-=(const Complex& c);
    Complex& operator*=(const Complex& c);
    Complex& operator/=(const Complex& c);
    bool operator==(const Complex& c) const;
    bool operator!=(const Complex& c) const;
    double getAmplitude() const;
    double getPhase() const;
    friend std::ostream& operator<<(std::ostream& s, const Complex& c);
    friend Complex operator+(const double& d, const Complex& c);
    friend Complex operator-(const double& d, const Complex& c);
    friend Complex operator*(const double& d, const Complex& c);
    friend Complex operator/(const double& d, const Complex& c);
    friend bool operator==(const double& d, const Complex& c);
    friend bool operator!=(const double& d, const Complex& c);
};

#endif