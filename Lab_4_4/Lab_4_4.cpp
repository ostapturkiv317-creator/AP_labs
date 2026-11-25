// Lab_4_4.cpp
// Турків Остап Миколайович, група КН-2630б
// Лабораторна робота № 4.4
// Табуляція функції, заданої графіком.
// Варіант 33
//
//      | x + R,             x <= -R
//  y = | sqrt(R^2 - x^2),   -R < x <= 0
//      | R - R*x/6,         0 < x <= 6
//      | x - 6,             x > 6

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double R;             // радіус
    double x, xp, xk, dx; // аргумент, початок, кінець, крок
    double y;             // результат

    cout << "R = "; cin >> R;
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;

    cout << endl << "Tabulation of the function given by the graph (variant 33)" << endl;
    cout << fixed;
    cout << "-----------------------------" << endl;
    cout << "|" << setw(10) << "x" << " |"
         << setw(14) << "y" << " |" << endl;
    cout << "-----------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        if (x <= -R)
            y = x + R;
        else
            if (x <= 0)
                y = sqrt(R * R - x * x);
            else
                if (x <= 6)
                    y = R - R * x / 6;
                else
                    y = x - 6;

        cout << "|" << setw(10) << setprecision(2) << x
             << " |" << setw(14) << setprecision(4) << y
             << " |" << endl;
        x += dx;
    }
    cout << "-----------------------------" << endl;

    return 0;
}
