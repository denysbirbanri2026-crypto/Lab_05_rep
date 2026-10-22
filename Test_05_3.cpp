// Test_05_3.cpp
// Unit-тест функції h() з проекту Lab_05_3.cpp

#include <iostream>
#include <cmath>

#define main program_main
#include "Lab_05_3.cpp"
#undef main

int passed = 0, failed = 0;

void AreEqual(const char *name, double actual, double expected)
{
    if (fabs(actual - expected) < 1e-9)
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
    AreEqual("h(0) = 1", h(0), 1);
    AreEqual("h(0.5) = cosh(0.5) / cos(0.5)", h(0.5), cosh(0.5) / cos(0.5));
    AreEqual("h(1) = (cos 1 + 1) / (cos^2 1 + 1)", h(1),
             (cos(1.) + 1) / (cos(1.) * cos(1.) + 1));
    AreEqual("h(-2) = (cos 2 + 1) / (cos^2 2 + 1)", h(-2),
             (cos(2.) + 1) / (cos(2.) * cos(2.) + 1));

    cout << endl << "Пройдено: " << passed
         << ", не пройдено: " << failed << endl;
    return failed;
}