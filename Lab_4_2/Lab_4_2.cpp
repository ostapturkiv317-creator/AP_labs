// Lab_4_2.cpp
// Турків Остап Миколайович, група КН-2630б
// Лабораторна робота № 4.2
// Табуляція функції, заданої формулою: функція однієї змінної.
// Варіант 33
//
//                  | 2x^4 + x^6 - x^8,              x < 4
// y = x + 1 +      | arctg((x+2)/3) + 8x,           4 <= x < 7
//                  | lg(x^2 + e^(x^2+2)),           x >= 7

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double x, xp, xk, dx; // аргумент, початок, кінець, крок
    double A, B, y;       // стала частина, змінна частина, результат

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;

    cout << fixed;
    cout << "-----------------------------------" << endl;
    cout << "|" << setw(10) << "x" << " |"
         << setw(20) << "y" << " |" << endl;
    cout << "-----------------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        A = x + 1;
        if (x < 4)
            B = 2 * pow(x, 4) + pow(x, 6) - pow(x, 8);
        else
            if (x < 7)
                B = atan((x + 2) / 3) + 8 * x;
            else
                B = log10(x * x + exp(x * x + 2));
        y = A + B;

        cout << "|" << setw(10) << setprecision(2) << x
             << " |" << setw(20) << setprecision(4) << y
             << " |" << endl;
        x += dx;
    }
    cout << "-----------------------------------" << endl;

    return 0;
}
