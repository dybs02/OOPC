#include "Poly.h"

Poly::Poly()
{

}

Poly::Poly(const Poly& p)
{
    this->coefficients = p.coefficients;
}

double& Poly::operator[](size_t pos)
{
    return this->coefficients[pos];

}

std::ostream& operator<<(ostream& s, const Poly& p)
{
    // TODO reverse order
    for (auto const& x : p.coefficients)
    {
        s << x.second << "x^" << x.first << "  ";
    }
    s << endl;
    return s;
}