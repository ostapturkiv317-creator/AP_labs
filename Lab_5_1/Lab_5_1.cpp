// Lab_5_1.cpp
// Турків Остап Миколайович, група КН-2630б
// Лабораторна робота № 5.1
// Функції, що містять арифметичний вираз.
// Варіант 33
//
// Дано дійсне s. Обчислити
//      5 f(s) + 3 f^2(1 + s) + 1
//   -------------------------------- ,
//    1 + sqrt( 1 + f^2(1 + s^2) )
// де
//   f(x) = sin( (1 + x^2 + x^4) / (1 + x^2) )

#include <iostream>
#include <cmath>

using namespace std;

double f(const double x); // прототип

int main()
{
    double s; // вхідне дійсне число

    cout << "s = "; cin >> s;

    double f1 = f(1 + s);
    double f2 = f(1 + s * s);
    double c = (5 * f(s) + 3 * f1 * f1 + 1) / (1 + sqrt(1 + f2 * f2));

    cout << "c = " << c << endl;

    return 0;
}

// визначення допоміжної функції
double f(const double x)
{
    return sin((1 + x * x + x * x * x * x) / (1 + x * x));
}
