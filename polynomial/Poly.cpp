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
        int key = pair->first;
        double val = pair->second;

        result += pow(x, key) * val;
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

Poly Poly::operator-(const Poly& p) const
{
    return *this + (-p);
}

Poly Poly::operator-() const
{
    Poly result = Poly();

    for (auto pair = this->coef.begin(); pair != this->coef.end(); pair++) {
        int key = pair->first;
        double val = pair->second;

        result.coef[key] = -val;
    }

    return result;
}

Poly Poly::operator*(const Poly& p) const
{
    Poly result = Poly();

    for (auto pair1 = p.coef.begin(); pair1 != p.coef.end(); pair1++) {
        int key1 = pair1->first;
        double val1 = pair1->second;
        Poly temp = Poly();

        for (auto pair2 = this->coef.begin(); pair2 != this->coef.end(); pair2++) {
            int key2 = pair2->first;
            double val2 = pair2->second;

            if (temp.coef.count(key1 + key2)) {
                temp[key1 + key2] += val1 * val2;
            }else {
                temp[key1 + key2] = val1 * val2;
            }
        }

        result = result + temp;
    }

    return result;
}

std::ostream& operator<<(ostream& s, const Poly& p)
{
    bool isZero = true;

    for (auto pair = p.coef.crbegin(); pair != p.coef.crend(); pair++) {
        int key = pair->first;
        double val = pair->second;

        if (val != 0) {
            if (pair != p.coef.crbegin()) {
                s << (val >= 0 ? " + " : " - ");
            }

            if (key == 0) {
                s << abs(val);
            } else {
                s << abs(val) << "x^" << key;
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