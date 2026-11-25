// Lab_5_3.cpp
// Турків Остап Миколайович, група КН-2630б
// Лабораторна робота № 5.3
// Функції, що містять розгалуження та цикли з рекурентними співвідношеннями.
// Варіант 33
//
// Обчислити  s(sqrt(r) + 1) - s^2(sqrt(r) - 1) + 1,  де
//
//         | (1 + x^2 + sqrt|sin x|) / (sin^2(2x^2) + 1),      |x| >= 1
// s(x) =  |
//         | sum_{i=0}^{5} x^i / i!  +  sum_{k=1}^{6} x^k / k!, |x| < 1
//
// Рекурентні співвідношення:
//   1-а сума: a0 = 1, R = x / i
//   2-а сума: a1 = x, R = x / k

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double s(const double x);

int main()
{
    double rp, rk, z; // початок, кінець інтервалу, значення виразу
    int n;            // кількість відрізків розбиття

    cout << "rp = "; cin >> rp;
    cout << "rk = "; cin >> rk;
    cout << "n = "; cin >> n;

    double dr = (rk - rp) / n;

    cout << endl << "Table of the expression (variant 33)" << endl;
    cout << fixed;
    cout << "-----------------------------" << endl;
    cout << "|" << setw(10) << "r" << " |" << setw(14) << "z" << " |" << endl;
    cout << "-----------------------------" << endl;

    double r = rp;
    while (r <= rk + dr / 2) // + dr/2 - щоб не втратити останню точку через похибку
    {
        if (r < 0)
        {
            cout << "|" << setw(10) << setprecision(3) << r
                 << " |" << setw(14) << "undefined" << " |" << endl;
        }
        else
        {
            double t = s(sqrt(r) - 1);
            z = s(sqrt(r) + 1) - t * t + 1;
            cout << "|" << setw(10) << setprecision(3) << r
                 << " |" << setw(14) << setprecision(5) << z << " |" << endl;
        }
        r += dr;
    }
    cout << "-----------------------------" << endl;

    return 0;
}

double s(const double x)
{
    if (abs(x) >= 1)
        return (1 + x * x + sqrt(abs(sin(x)))) / (sin(2 * x * x) * sin(2 * x * x) + 1);
    else
    {
        // сума x^i / i!, i = 0..5
        double S1 = 0;
        double a = 1;  // a0
        S1 = a;
        int i = 0;
        do {
            i++;
            a *= x / i; // R = x / i
            S1 += a;
        } while (i < 5);

        // сума x^k / k!, k = 1..6
        double S2 = 0;
        int k = 1;
        a = x;         // a1
        S2 = a;
        do {
            k++;
            a *= x / k; // R = x / k
            S2 += a;
        } while (k < 6);

        return S1 + S2;
    }
}
