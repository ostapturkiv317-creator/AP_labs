// Lab_4_7.cpp
// Турків Остап Миколайович, група КН-2630б
// Лабораторна робота № 4.7
// Обчислення суми ряду Тейлора за допомогою ітераційних циклів
// та рекурентних співвідношень.
// Варіант 33
//
// e^(-x^2) = sum_{n=0}^{inf} (-1)^n x^(2n) / n! = 1 - x^2 + x^4/2! - x^6/3! + ...
//
// Перший доданок:          a0 = 1
// Коефіцієнт рекурентності: R = a_n / a_(n-1) = -x^2 / n

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double xp, xk, x, dx, eps; // інтервал, крок, точність
    double a = 0, R = 0, S = 0; // доданок, коефіцієнт, сума
    int n = 0;                 // номер доданку

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << endl << "Taylor series for exp(-x^2)" << endl;
    cout << fixed;
    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
         << setw(12) << "exp(-x^2)" << " |"
         << setw(12) << "S" << " |"
         << setw(5) << "n" << " |" << endl;
    cout << "-------------------------------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        n = 0;
        a = 1;
        S = a;
        do {
            n++;
            R = -x * x / n;
            a *= R;
            S += a;
        } while (abs(a) >= eps);

        cout << "|" << setw(7) << setprecision(2) << x << " |"
             << setw(12) << setprecision(6) << exp(-x * x) << " |"
             << setw(12) << setprecision(6) << S << " |"
             << setw(5) << n << " |" << endl;
        x += dx;
    }
    cout << "-------------------------------------------------" << endl;

    return 0;
}
