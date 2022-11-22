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

double Poly::operator()(double x) const
{
    double result = 0;

    for (auto pair = this->coef.begin(); pair != this->coef.end(); pair++) {
        int exp = pair->first;
        double val = pair->second;

        result += pow(x, exp) * val;
    }

    return result;
}

double& Poly::operator[](size_t pos)
{
    return this->coef[pos];
}

Poly Poly::operator+(const Poly& p) const
{
    Poly result = Poly(*this);

    for (auto pair = p.coef.begin(); pair != p.coef.end(); pair++) {
        int exp = pair->first;
        double val = pair->second;

        if (result.coef.count(exp)) {
            result.coef[exp] += val;
        }else {
            result.coef[exp] = val;
        }
    }

    return result;
}

Poly Poly::operator-(const Poly& p) const
{
    return *this + (-p);
}

Poly Poly::operator-() const
{
    return *this * (-1);
}

Poly Poly::operator*(const Poly& p) const
{
    Poly result = Poly();

    for (auto pair1 = p.coef.begin(); pair1 != p.coef.end(); pair1++) {
        int exp1 = pair1->first;
        double val1 = pair1->second;
        Poly temp = Poly();

        for (auto pair2 = this->coef.begin(); pair2 != this->coef.end(); pair2++) {
            int exp2 = pair2->first;
            double val2 = pair2->second;

            if (temp.coef.count(exp1 + exp2)) {
                temp[exp1 + exp2] += val1 * val2;
            }else {
                temp[exp1 + exp2] = val1 * val2;
            }
        }

        result = result + temp;
    }

    return result;
}

Poly operator+(const double& d, const Poly& p)
{
    return p + d;
}

Poly operator-(const double& d, const Poly& p)
{
    return p - d;
}

Poly operator*(const double& d, const Poly& p)
{
    return p * d;
}

std::ostream& operator<<(ostream& s, const Poly& p)
{
    bool isZero = true;

    for (auto pair = p.coef.crbegin(); pair != p.coef.crend(); pair++) {
        int exp = pair->first;
        double val = pair->second;

        if (val != 0) {
            if (pair != p.coef.crbegin()) {
                s << (val >= 0 ? " + " : " - ");
            }

            if (exp == 0) {
                s << abs(val);
            } else {
                s << abs(val) << "x^" << exp;
            }

            isZero = false;
        }
    }
    if (isZero) {
        s << 0;
    }
    s << endl;
    return s;
}