// Lab_05_2.cpp
// Бірбан Денис
// Лабораторна робота № 5.2
// Обчислення суми ряду Тейлора за допомогою функцій.
// Варіант 3

#include <iostream>
#include <iomanip>
#include <string>
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

    const int wx = 8, wf = 12, ws = 12, wn = 5; // ширини колонок таблиці
    const string line = "+" + string(wx + 2, '-') + "+"
                            + string(wf + 2, '-') + "+"
                            + string(ws + 2, '-') + "+"
                            + string(wn + 2, '-') + "+";

    cout << fixed;
    cout << line << endl;
    cout << "| " << setw(wx) << "x" << " | " << setw(wf) << "exp(x^2)"
         << " | " << setw(ws) << "S" << " | " << setw(wn) << "n" << " |"
         << endl;
    cout << line << endl;

    x = xp;
    while (x <= xk)
    {
        S(x, eps, n, s);

        cout << "| " << setw(wx) << setprecision(2) << x
             << " | " << setw(wf) << setprecision(5) << exp(x * x)
             << " | " << setw(ws) << setprecision(5) << s
             << " | " << setw(wn) << n << " |" << endl;

        x += dx;
    }
    cout << line << endl;

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