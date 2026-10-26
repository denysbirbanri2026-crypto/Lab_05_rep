// Test_05_1.cpp
// Unit-тест функції k() з проекту Lab_05_1.cpp

#include <iostream>
#include <cmath>

#define main program_main   // щоб не було конфлікту двох main()
#include "Lab_05_1.cpp"
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
    AreEqual("k(0, 1) = cos(1)", k(0, 1), cos(1.));
    AreEqual("k(1, 0) = sin(1) + 1", k(1, 0), sin(1.) + 1);
    AreEqual("k(1, 1) = (sin 1 + cos 1) / 2", k(1, 1),
             (sin(1.) + cos(1.)) / 2);

    cout << endl << "Пройдено: " << passed
         << ", не пройдено: " << failed << endl;
    return failed;
}