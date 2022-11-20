#include "Poly.h"

Poly::Poly()
{

}

Poly::Poly(double d)
{
    this->coef[0] = d;
}

Poly::Poly(const Poly& p)
{
    this->coef = p.coef;
}

double& Poly::operator[](size_t pos)
{
    return this->coef[pos];
}

Poly Poly::operator+(const Poly& p) const
{
    Poly result = Poly(*this);

    for (auto pair = p.coef.begin(); pair != p.coef.end(); pair++) {
        int key = pair->first;
        double val = pair->second;

        if (result.coef.count(key)) {
            result.coef[key] += val;
        }else {
            result.coef[key] = val;
        }
    }

    return result;
}

std::ostream& operator<<(ostream& s, const Poly& p)
{
    for (auto pair = p.coef.crbegin(); pair != p.coef.crend(); pair++) {
        char buffer[50];
        sprintf(buffer, "%+.8g", pair->second);
        s << buffer << "x^" << pair->first << " ";
    }
    s << endl;
    return s;
}