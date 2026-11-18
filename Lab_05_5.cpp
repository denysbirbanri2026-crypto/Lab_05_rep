// Лабораторна робота № 5.5
// Рекурсивні функції
// Варіант 3
// Виконав: Бірбан Денис
//
// Біноміальний коефіцієнт C(n, k) = n! / (k! * (n-k)!)
// за рекурентним співвідношенням:
//          | C(n-1, k-1) + C(n-1, k),  якщо n > 0
// C(n,k) = |
//          | 1,                         якщо k = n або k = 0
//
// Визначається рівень та глибина рекурсії.

#include <iostream>
#include <string>

using namespace std;

// Рекурсивна функція обчислення біноміального коефіцієнта.
//   n, k   - параметри коефіцієнта C(n, k)
//   level  - поточний рівень рекурсії (параметр-значення; перший виклик: 1)
//   depth  - глибина рекурсії (параметр-посилання; початкове значення: 0)
long long C(const int n, const int k, const int level, int& depth)
{
    if (level > depth)                      // оновлюємо глибину рекурсії
        depth = level;

    // вивід поточного рівня рекурсії (з відступом для наочності)
    cout << string(2 * (level - 1), ' ')
         << "level = " << level << "   C(" << n << ", " << k << ")" << endl;

    if (k == n || k == 0)       // базова задача, вихід з рекурсії
        return 1;
    else                        // n > 0: рекурентне співвідношення
        return C(n - 1, k - 1, level + 1, depth)
             + C(n - 1, k,     level + 1, depth);
}

#ifndef UNIT_TEST   // при компіляції unit-тесту функція main() не потрібна
int main()
{
    int n, k;
    cout << "n = "; cin >> n;
    cout << "k = "; cin >> k;

    // рекурентне співвідношення визначене лише при 0 <= k <= n
    if (n < 0 || k < 0 || k > n)
    {
        cout << "Помилка: потрібно, щоб 0 <= k <= n" << endl;
        return 1;
    }

    int depth = 0;                          // початкове значення глибини
    long long result = C(n, k, 1, depth);   // 1 - початкове значення level

    cout << endl;
    cout << "C(" << n << ", " << k << ") = " << result << endl;
    cout << "depth = " << depth << endl;

    return 0;
}
#endif