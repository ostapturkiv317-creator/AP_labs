// Lab_4_3.cpp
// Турків Остап Миколайович, група КН-2630б
// Лабораторна робота № 4.3
// Табуляція функції, заданої формулою: функція з параметрами.
// Варіант 33
//
//      | a*x^2 + b,    при x - 1 < 0 і b - x != 0
// F =  | (x - a) / x,  при x - 1 > 0 і b + x == 0
//      | x / c,        в інших випадках

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double a, b, c;       // параметри
    double x, xp, xk, dx; // аргумент, початок, кінець, крок
    double F;             // результат

    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "c = "; cin >> c;
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;

    cout << fixed;
    cout << "-----------------------------" << endl;
    cout << "|" << setw(10) << "x" << " |"
         << setw(14) << "F" << " |" << endl;
    cout << "-----------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        if (x - 1 < 0 && b - x != 0)
            F = a * x * x + b;
        else
            if (x - 1 > 0 && b + x == 0)
                F = (x - a) / x;
            else
                F = x / c;

        cout << "|" << setw(10) << setprecision(2) << x
             << " |" << setw(14) << setprecision(4) << F
             << " |" << endl;
        x += dx;
    }
    cout << "-----------------------------" << endl;

    return 0;
}
