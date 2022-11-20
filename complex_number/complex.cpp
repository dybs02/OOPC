#include "complex.h"


Complex::Complex()
{
    this->real = 0;
    this->imag = 0;
}

Complex::Complex(double real)
{
    this->real = real;
    this->imag = 0;
}

Complex::Complex(double real, double imag)
{
    this->real = real;
    this->imag = imag;
}

Complex& Complex::operator=(const Complex& c)
{
    this->real = c.real;
    this->imag = c.imag;
    return *this;
}

Complex Complex::operator+(const Complex& c) const
{
    return  Complex(
            this->real + c.real,
            this->imag + c.imag
            );
}

Complex Complex::operator-(const Complex& c) const
{
    return  Complex(
            this->real - c.real,
            this->imag - c.imag
    );
}

Complex Complex::operator-() const
{
    return Complex(-this->real, -this->imag);
}

Complex Complex::operator*(const Complex& c) const
{
    return  Complex(
            this->real*c.real - this->imag*c.imag,
            this->real*c.imag - this->imag*c.real
    );
}

Complex Complex::operator/(const Complex& c) const
{
    double sum_sqr = pow(c.real, 2) + pow(c.imag, 2);
    return  Complex(
            (this->real*c.real + this->imag*c.imag) / sum_sqr,
            (this->imag*c.real - this->real*c.imag) / sum_sqr
    );
}

Complex& Complex::operator+=(const Complex& c)
{
    this->real += c.real;
    this->imag += c.imag;
    return *this;
}

Complex& Complex::operator-=(const Complex& c)
{
    this->real -= c.real;
    this->imag -= c.imag;
    return *this;
}

Complex& Complex::operator*=(const Complex& c)
{
    *this = (*this) * c;
    return *this;
}

Complex& Complex::operator/=(const Complex& c)
{
    *this = (*this) / c;
    return *this;
}

bool Complex::operator==(const Complex& c) const
{
    return (this->real == c.real && this->imag == c.imag);
}

bool Complex::operator!=(const Complex& c) const
{
    return !(this->real == c.real && this->imag == c.imag);
}

double Complex::getAmplitude() const
{
    std::complex<double> z(this->real, this->imag);
    return std::abs(z);
}

double Complex::getPhase() const
{
    std::complex<double> z(this->real, this->imag);
    return std::arg(z);
}

// friend member functions:

std::ostream& operator<<(std::ostream& s, const Complex& c)
{
    s << "(" << c.real << ", " << c.imag << ")";
    return s;
}

Complex operator+(const double& d, const Complex& c)
{
    Complex o = d;
    return o += c;
}

Complex operator-(const double& d, const Complex& c)
{
    Complex o = d;
    return o -= c;
}

Complex operator*(const double& d, const Complex& c)
{
    Complex o = d;
    return o *= c;
}

Complex operator/(const double& d, const Complex& c)
{
    Complex o = d;
    return o /= c;
}

bool operator==(const double& d, const Complex& c)
{
    return Complex(d) == c;
}

bool operator!=(const double& d, const Complex& c)
{
    return Complex(d) != c;
}