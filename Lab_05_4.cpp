// Лабораторна робота № 5.4
// Обчислення сум та добутків за допомогою рекурсії
// Варіант 3
// Виконав: Бірбан Денис
//
//        N
//   S =  Σ ( 1/i + sqrt(1 + sin²(i)) )
//       i=1

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Один доданок суми: 1/i + sqrt(1 + sin^2(i))
double term(const int i)
{
    return 1.0 / i + sqrt(1 + sin(1.0 * i) * sin(1.0 * i));
}

// 5) Ітераційний спосіб (для контролю правильності рекурсивних способів)
double S0(const int N)
{
    double s = 0;
    for (int i = 1; i <= N; i++)
        s += term(i);
    return s;
}

// 1) Обчислення на рекурсивному СПУСКУ, параметр i СПАДАЄ (N -> 1).
//    t - накопичена сума; перший виклик: S1(N, 0)
double S1(const int i, double t)
{
    if (i < 1)                  // умова припинення рекурсії (базова задача)
        return t;
    t = t + term(i);            // дія на спуску: додаємо доданок до суми
    return S1(i - 1, t);        // рекурсивний виклик
}

// 2) Обчислення на рекурсивному СПУСКУ, параметр i ЗРОСТАЄ (1 -> N).
//    Перший виклик: S2(N, 1, 0)
double S2(const int N, const int i, double t)
{
    if (i > N)
        return t;
    t = t + term(i);            // дія на спуску
    return S2(N, i + 1, t);
}

// 3) Обчислення на рекурсивному ПІДЙОМІ, параметр i СПАДАЄ (N -> 1).
//    Перший виклик: S3(N)
double S3(const int i)
{
    if (i < 1)
        return 0;
    // додавання виконується при поверненні з рекурсії (на підйомі)
    return term(i) + S3(i - 1);
}

// 4) Обчислення на рекурсивному ПІДЙОМІ, параметр i ЗРОСТАЄ (1 -> N).
//    Перший виклик: S4(N, 1)
double S4(const int N, const int i)
{
    if (i > N)
        return 0;
    // додавання виконується при поверненні з рекурсії (на підйомі)
    return term(i) + S4(N, i + 1);
}

#ifndef UNIT_TEST   // при компіляції unit-тесту функція main() не потрібна
int main()
{
    int N;
    cout << "N = "; cin >> N;

    cout << fixed << setprecision(10);
    cout << "(iter)         S0 = " << S0(N)         << endl;
    cout << "(down, --)     S1 = " << S1(N, 0)      << endl;
    cout << "(down, ++)     S2 = " << S2(N, 1, 0)   << endl;
    cout << "(up,   --)     S3 = " << S3(N)         << endl;
    cout << "(up,   ++)     S4 = " << S4(N, 1)      << endl;

    return 0;
}
#endif