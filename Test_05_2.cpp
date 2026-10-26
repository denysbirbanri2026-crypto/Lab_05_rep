// Test_05_2.cpp
// Unit-тест функцій S() та A() з проекту Lab_05_2.cpp

#include <iostream>
#include <cmath>

#define main program_main
#include "Lab_05_2.cpp"
#undef main

int passed = 0, failed = 0;

void AreEqual(const char *name, double actual, double expected, double tol)
{
    if (fabs(actual - expected) < tol)
    {
        passed++;
        cout << "[ OK     ] " << name << endl;
    }
    else
    {
        failed++;
        cout << "[ FAILED ] " << name << ": очікувалось "
             << expected << ", отримано " << actual << endl;
    }
}

int main()
{
    double a = 1;
    A(2, 2, a);                       // a = 1 * 2^2 / 2 = 2
    AreEqual("A(2, 2, 1) = 2", a, 2, 1e-12);

    double s;
    int n;
    S(1, 1e-9, n, s);                 // e^(1^2) = e
    AreEqual("S(1, 1e-9) = exp(1)", s, exp(1.), 1e-8);
    S(0, 1e-9, n, s);                 // e^0 = 1
    AreEqual("S(0, 1e-9) = 1", s, 1, 1e-12);
    S(-1.5, 1e-9, n, s);              // e^(2.25)
    AreEqual("S(-1.5, 1e-9) = exp(2.25)", s, exp(2.25), 1e-7);

    cout << endl << "Пройдено: " << passed
         << ", не пройдено: " << failed << endl;
    return failed;
}