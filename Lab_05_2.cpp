// Lab_05_2.cpp
// Бірбан Денис
// Лабораторна робота № 5.2
// Обчислення суми ряду Тейлора за допомогою функцій.
// Варіант 3

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void S(const double x, const double eps, int &n, double &s); // сума ряду
void A(const double x, const int n, double &a);               // доданок ряду

int main()
{
    double xp;      // початок інтервалу
    double xk;      // кінець інтервалу
    double dx;      // крок табуляції
    double eps;     // точність
    double x;       // аргумент
    double s = 0;   // сума ряду
    int n = 0;      // кількість порахованих доданків

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(5) << "x" << "      |"
         << setw(10) << "exp(x^2)" << "   |"
         << setw(7) << "S" << "       |"
         << setw(5) << "n" << "   |" << endl;
    cout << "-------------------------------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        S(x, eps, n, s);

        cout << "|" << setw(7) << setprecision(2) << x << "   |"
             << setw(10) << setprecision(5) << exp(x * x) << "   |"
             << setw(10) << setprecision(5) << s << "   |"
             << setw(5) << n << "   |" << endl;

        x += dx;
    }
    cout << "-------------------------------------------------" << endl;

    return 0;
}

// Сума ряду: e^(x^2) = 1 + x^2 + x^4/2! + x^6/3! + ...
void S(const double x, const double eps, int &n, double &s)
{
    n = 0;
    double a = 1; // перший доданок ряду
    s = a;
    do
    {
        n++;
        A(x, n, a);
        s += a;
    } while (fabs(a) >= eps);
}

// Доданок ряду: a(n) = a(n-1) * x^2 / n
void A(const double x, const int n, double &a)
{
    double R = x * x / n; // рекурентний множник
    a *= R;
}