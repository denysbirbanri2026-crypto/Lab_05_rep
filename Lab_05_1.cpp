// Lab_05_1.cpp
// Бірбан Денис
// Лабораторна робота № 5.1
// Функції, що містять арифметичний вираз.
// Варіант 3

#include <iostream>
#include <cmath>

using namespace std;

double k(const double x, const double y); // прототип допоміжної функції

int main()
{
    double p; // вхідний параметр
    double q; // вхідний параметр

    cout << "p = "; cin >> p;
    cout << "q = "; cin >> q;

    double c = (k(1 + p * p, 1 - q * q) - pow(k(1, p * q), 2))
               / (1 + k(p * q, 1));

    cout << "c = " << c << endl;

    return 0;
}

// Допоміжна функція: k(x, y) = sin x / (x^2 + y^2) + cos y / (1 + |x*y|)
double k(const double x, const double y)
{
    return sin(x) / (x * x + y * y) + cos(y) / (1 + fabs(x * y));
}