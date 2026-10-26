// Lab_05_3.cpp
// Бірбан Денис
// Лабораторна робота № 5.3
// Функції, що містять розгалуження та цикли з рекурентними співвідношеннями.
// Варіант 3

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double h(const double x); // прототип допоміжної функції

int main()
{
    double qp; // початок інтервалу
    double qk; // кінець інтервалу
    int n;     // кількість відрізків розбиття інтервалу
    double q;  // аргумент
    double z;  // значення виразу

    cout << "qp = "; cin >> qp;
    cout << "qk = "; cin >> qk;
    cout << "n = "; cin >> n;

    double dq = (qk - qp) / n; // крок

    cout << fixed;
    cout << "-----------------------------" << endl;
    cout << "|" << setw(7) << "q" << "   |"
         << setw(14) << "z" << "   |" << endl;
    cout << "-----------------------------" << endl;

    for (int i = 0; i <= n; i++)
    {
        q = qp + i * dq;
        z = h(q + 1) + h(q * q + 1) + pow(h(q * q), 2);

        cout << "|" << setw(8) << setprecision(3) << q << "  |"
             << setw(15) << setprecision(6) << z << "  |" << endl;
    }
    cout << "-----------------------------" << endl;

    return 0;
}

// Допоміжна функція h(x):
//   |x| >= 1:  (cos x + 1) / (cos^2 x + 1)
//   |x| < 1:   (1 / cos x) * сума(i = 0..6) x^(2i) / (2i)!
double h(const double x)
{
    if (fabs(x) >= 1)
        return (cos(x) + 1) / (cos(x) * cos(x) + 1);
    else
    {
        double a = 1; // перший доданок суми
        double s = a;
        for (int i = 1; i <= 6; i++)
        {
            a *= x * x / ((2 * i - 1) * (2 * i)); // рекурентне співвідношення
            s += a;
        }
        return s / cos(x);
    }
}