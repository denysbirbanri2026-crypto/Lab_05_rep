// Unit-тест до Лабораторної роботи № 5.5 (варіант 3)
// Компіляція та запуск:
//   g++ -std=c++17 -o test_lab_05_5 test_lab_05_5.cpp && ./test_lab_05_5

#define UNIT_TEST                  // вимикає main() у lab_05_5.cpp
#include "lab_05_5.cpp"

#include <sstream>

static int total = 0, failed = 0;

static void check(const string& name, long long expected, long long actual)
{
    total++;
    bool ok = (expected == actual);
    if (!ok) failed++;
    cout << (ok ? "[  OK  ] " : "[ FAIL ] ") << name
         << "  expected = " << expected << ", actual = " << actual << endl;
}

// Еталон: C(n,k) = n! / (k! (n-k)!) за формулою із завдання
static long long fact(int m) { return m <= 1 ? 1 : m * fact(m - 1); }
static long long formula(int n, int k)
{
    return fact(n) / (fact(k) * fact(n - k));
}

// Виклик C() з "тихим" виводом (рівні рекурсії у тестах не потрібні)
static long long quietC(int n, int k, int& depth)
{
    ostringstream sink;
    streambuf* old = cout.rdbuf(sink.rdbuf());
    depth = 0;
    long long r = C(n, k, 1, depth);
    cout.rdbuf(old);
    return r;
}

int main()
{
    int d;

    // --- Відомі значення ---
    check("C(5,2)",   10,  quietC(5, 2, d));
    check("C(10,3)",  120, quietC(10, 3, d));
    check("C(10,5)",  252, quietC(10, 5, d));
    check("C(20,10)", 184756, quietC(20, 10, d));

    // --- Базові випадки: k = 0 та k = n ---
    check("C(7,0)", 1, quietC(7, 0, d));
    check("C(7,7)", 1, quietC(7, 7, d));
    check("C(0,0)", 1, quietC(0, 0, d));

    // --- Глибина рекурсії ---
    quietC(7, 0, d);  check("depth C(7,0)  [базовий випадок]", 1, d);
    quietC(7, 7, d);  check("depth C(7,7)  [базовий випадок]", 1, d);
    quietC(5, 2, d);  check("depth C(5,2)  = n", 5, d);
    quietC(10, 3, d); check("depth C(10,3) = n", 10, d);
    quietC(2, 1, d);  check("depth C(2,1)  = n", 2, d);

    // --- Порівняння з формулою n!/(k!(n-k)!) для всіх 0<=k<=n<=12 ---
    bool all = true;
    for (int n = 0; n <= 12; n++)
        for (int k = 0; k <= n; k++)
            if (quietC(n, k, d) != formula(n, k)) all = false;
    check("C(n,k) == n!/(k!(n-k)!) для всіх 0<=k<=n<=12", 1, all);

    // --- Симетрія C(n,k) = C(n,n-k) ---
    bool sym = true;
    for (int n = 0; n <= 12; n++)
        for (int k = 0; k <= n; k++)
            if (quietC(n, k, d) != quietC(n, n - k, d)) sym = false;
    check("C(n,k) == C(n,n-k) для всіх 0<=k<=n<=12", 1, sym);

    cout << "-----------------------------------------\n"
         << "Tests run: " << total << ", passed: " << total - failed
         << ", failed: " << failed << endl;
    return failed == 0 ? 0 : 1;
}