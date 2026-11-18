// Unit-тест до Лабораторної роботи № 5.4 (варіант 3)
// Компіляція та запуск:
//   g++ -std=c++17 -o test_lab_05_4 test_lab_05_4.cpp && ./test_lab_05_4

#define UNIT_TEST                  // вимикає main() у lab_05_4.cpp
#include "lab_05_4.cpp"

#include <string>

static int total = 0, failed = 0;

// Перевірка збігу двох дійсних чисел з точністю eps
static void checkNear(const string& name, double expected, double actual,
                      double eps = 1e-9)
{
    total++;
    bool ok = fabs(expected - actual) <= eps;
    if (!ok) failed++;
    cout << (ok ? "[  OK  ] " : "[ FAIL ] ") << name
         << "  expected = " << expected << ", actual = " << actual << endl;
}

int main()
{
    cout << setprecision(12);

    // Еталонні значення обчислені незалежно (Python, math.fsum)
    const double e1  = 2.306932828523934;    // N = 1
    const double e5  = 8.59134064938673;     // N = 5
    const double e10 = 15.098489471170891;   // N = 10
    const double e50 = 65.3456288309194;     // N = 50

    // --- Функція S0 (ітераційна) ---
    checkNear("S0(N=1)",  e1,  S0(1));
    checkNear("S0(N=5)",  e5,  S0(5));
    checkNear("S0(N=10)", e10, S0(10));
    checkNear("S0(N=0) = 0 (порожня сума)", 0, S0(0));

    // --- Рекурсивні функції порівнюємо з еталоном ---
    for (int N : {1, 5, 10})
    {
        double e = (N == 1) ? e1 : (N == 5) ? e5 : e10;
        string n = "N=" + to_string(N);
        checkNear("S1(" + n + ") спуск, i спадає",   e, S1(N, 0));
        checkNear("S2(" + n + ") спуск, i зростає",  e, S2(N, 1, 0));
        checkNear("S3(" + n + ") підйом, i спадає",  e, S3(N));
        checkNear("S4(" + n + ") підйом, i зростає", e, S4(N, 1));
    }

    // --- Усі п'ять способів мають збігатися з еталоном (N = 50) ---
    const int N = 50;
    checkNear("S0(N=50)", e50, S0(N));
    checkNear("S1(N=50)", e50, S1(N, 0));
    checkNear("S2(N=50)", e50, S2(N, 1, 0));
    checkNear("S3(N=50)", e50, S3(N));
    checkNear("S4(N=50)", e50, S4(N, 1));

    // --- Порожня сума (N = 0) ---
    checkNear("S1(N=0) = 0", 0, S1(0, 0));
    checkNear("S2(N=0) = 0", 0, S2(0, 1, 0));
    checkNear("S3(N=0) = 0", 0, S3(0));
    checkNear("S4(N=0) = 0", 0, S4(0, 1));

    cout << "-----------------------------------------\n"
         << "Tests run: " << total << ", passed: " << total - failed
         << ", failed: " << failed << endl;
    return failed == 0 ? 0 : 1;
}