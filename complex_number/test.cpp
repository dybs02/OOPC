#include "complex.h"

using namespace std;

int main()
{
    Complex a = Complex(12.8, 3.2);
    Complex b = Complex(-5, 0.3);
    Complex c = Complex(6.1, -7.4);

    a += b += c;
    (a += b) += c;
    a *= b *= c;
    (a *= b) *= c;
    a + 7;
    b = 7 + a;
    b * 5;
    5 * b;

    cout << (c == 3.5) << endl;
    cout << (3.5 == c) << endl;
    cout << a << b << c << endl;

    const Complex d = Complex(6.1, -7.4);

    a = d + c;
    b = -d;
    d == a;
    cout << d.getPhase() << endl;
    cout << d.getAmplitude() << endl;
    cout << a.getPhase() << endl;
    cout << a.getAmplitude() << endl;

    return 0;
}