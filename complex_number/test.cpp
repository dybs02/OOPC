#include "complex.h"

using namespace std;

int main() {
    Complex a = Complex(12, 0.8);
    cout << a << endl;

    a = 5.0;
    cout << a << endl;

    a = Complex(-1, -6);
    cout << a << endl;

    return 0;
}




//int main() {
//
//    Complex a = Complex();
//    Complex b = Complex();
//    Complex c = Complex();
//
//    a += b += c;
//    cout << a << b << c << endl;
//
//    (a += b) += c;
//    cout << a << b << c << endl;
//
//    a *= b *= c;
//    cout << a << b << c << endl;
//
//    (a *= b) *= c;
//    cout << a << b << c << endl;
//
//    a + 7;
//    cout << a << b << c << endl;
//
//    7 + a;
//    cout << a << b << c << endl;
//
//    b * 5;
//    cout << a << b << c << endl;
//
//    5 * b;
//    cout << a << b << c << endl;
//
//    c == 3.5
//    3.5 == c
//
//    return 0;
//}