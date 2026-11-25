// Lab_5_5.cpp
// Турків Остап Миколайович, група КН-2630б
// Лабораторна робота № 5.5
// Рекурсивні функції.
// Варіант 33
//
//         | n % 10,     якщо n % 10 > 0
// f(n) =  | 0,          якщо n == 0
//         | f(n / 10),  в іншому випадку
//
// S(p, q) = sum_{i=p}^{q} f(i)
// Визначити глибину та рівень рекурсії.

#include <iostream>

using namespace std;

// f(n) - остання ненульова цифра числа n
// level - поточний рівень рекурсії, depth - глибина (максимальний рівень)
int f(const int n, const int level, int &depth)
{
    if (level > depth)
        depth = level;

    if (n % 10 > 0)
        return n % 10;
    else
        if (n == 0)
            return 0;
        else
            return f(n / 10, level + 1, depth);
}

// S(p, q) - сума f(i) для i від p до q (також рекурсивно)
int S(const int p, const int q, const int level, int &depth)
{
    if (p > q)
        return 0;

    int d = 0; // глибина рекурсії для f(p)
    int value = f(p, 1, d);
    cout << "  f(" << p << ") = " << value << ",  depth of f = " << d << endl;
    if (level > depth)
        depth = level;

    return value + S(p + 1, q, level + 1, depth);
}

int main()
{
    int p, q;
    cout << "p = "; cin >> p;
    cout << "q = "; cin >> q;

    int depthS = 0;
    int result = S(p, q, 1, depthS);

    cout << endl;
    cout << "S(" << p << ", " << q << ") = " << result << endl;
    cout << "depth of S = " << depthS << endl;

    return 0;
}
