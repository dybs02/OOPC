#include "Matrix.h"
#include <fstream>

void testAssignments();
void testAddition();
void testSubtraction();
void testMultiplication();
void testComparison();

int main()
{
    testAssignments();
//    testAddition();
//    testSubtraction();
//    testMultiplication();
//    testComparison();

    Matrix m1;
    ifstream fileIn("m1.txt");
    fileIn >> m1;
    cout << m1;

    return 0;
}

void testAssignments()
{
    Matrix m1 = Matrix(2, 3);
    m1.assignSameValues(1);
    Matrix m2 = m1;

    cout << "m1 :" << endl;
    cout << m1 << endl;

    cout << "m2 :" << endl;
    cout << m2 << endl;

    cout << "m1.assignRandomValues()" << endl << endl;
    m1.assignRandomValues();

    cout << "m1 :" << endl;
    cout << m1 << endl;

    cout << "m2 :" << endl;
    cout << m2 << endl;
}

void testAddition()
{
    cout << "-----------------------------" << endl;
    cout << "Testing addition" << endl;

    Matrix m1 = Matrix(2, 3);
    Matrix m2 = Matrix(2, 3);
    Matrix m3 = Matrix(2, 3);
    m1.assignRandomValues();
    m2.assignRandomValues();

    cout << "m1 :" << endl;
    cout << m1 << endl;

    cout << "m2 :" << endl;
    cout << m2 << endl;

    cout << "m3 = m1 + m2 :" << endl;
    m3 = m1 + m2;
    cout << m3 << endl;

    cout << "m3 += m1 :" << endl;
    m3 += m1;
    cout << m3 << endl;
}

void testSubtraction()
{
    cout << "-----------------------------" << endl;
    cout << "Testing subtraction" << endl;

    Matrix m1 = Matrix(2, 3);
    Matrix m2 = Matrix(2, 3);
    Matrix m3 = Matrix(2, 3);
    m1.assignRandomValues();
    m2.assignRandomValues();

    cout << "m1 :" << endl;
    cout << m1 << endl;

    cout << "m2 :" << endl;
    cout << m2 << endl;

    cout << "-m1 :" << endl;
    cout << -m1 << endl;

    cout << "m3 = m1 - m2 :" << endl;
    m3 = m1 - m2;
    cout << m3 << endl;

    cout << "m3 -= m1 :" << endl;
    m3 -= m1;
    cout << m3 << endl;
}

void testMultiplication()
{
    cout << "-----------------------------" << endl;
    cout << "Testing multiplication" << endl;

    Matrix m1 = Matrix(2, 3);
    Matrix m2 = Matrix(3, 4);
    Matrix m3 = Matrix(4, 2);
    m1.assignRandomValues();
    m2.assignRandomValues();

    cout << "m1 :" << endl;
    cout << m1 << endl;

    cout << "m2 :" << endl;
    cout << m2 << endl;

    cout << "m3 = m1 * m2 :" << endl;
    m3 = m1 * m2;
    cout << m3 << endl;

    cout << "m3 *= m1 :" << endl;
    m3 *= m1;
    cout << m3 << endl;
}

void testComparison()
{
    cout << "-----------------------------" << endl;
    cout << "Testing comparison" << endl;

    Matrix m1 = Matrix(2, 3);
    Matrix m2 = Matrix(3, 4);
    m1.assignRandomValues();
    m2.assignRandomValues();

    cout << "m1 :" << endl;
    cout << m1 << endl;

    cout << "m2 :" << endl;
    cout << m2 << endl;

    cout << "m1 == m2 : " << (m1 == m2) << endl;
    cout << "m1 != m2 : " << (m1 != m2) << endl;
    cout << "m1 == m1 : " << (m1 == m1) << endl;
}