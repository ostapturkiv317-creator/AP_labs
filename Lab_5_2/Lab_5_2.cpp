// Lab_5_2.cpp
// Турків Остап Миколайович, група КН-2630б
// Лабораторна робота № 5.2
// Обчислення суми ряду Тейлора за допомогою функцій.
// Варіант 33
//
// e^(-x^2) = sum_{n=0}^{inf} (-1)^n x^(2n) / n!
// a0 = 1,  R = -x^2 / n

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void S(const double x, const double eps, int &n, double &s); // сума ряду
void A(const double x, const int n, double &a);              // наступний доданок

int main()
{
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;

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
        S(x, eps, n, s);

        cout << "|" << setw(7) << setprecision(2) << x << " |"
             << setw(12) << setprecision(6) << exp(-x * x) << " |"
             << setw(12) << setprecision(6) << s << " |"
             << setw(5) << n << " |" << endl;
        x += dx;
    }
    cout << "-------------------------------------------------" << endl;

    return 0;
}

// обчислює суму ряду s з точністю eps, n - кількість доданків
void S(const double x, const double eps, int &n, double &s)
{
    n = 0;
    double a = 1; // перший доданок
    s = a;
    do {
        n++;
        A(x, n, a);
        s += a;
    } while (abs(a) >= eps);
}

// обчислює n-й доданок через (n-1)-й за рекурентним співвідношенням
void A(const double x, const int n, double &a)
{
    double R = -x * x / n;
    a *= R;
}
