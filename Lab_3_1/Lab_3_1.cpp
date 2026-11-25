// Lab_3_1.cpp
// Турків Остап Миколайович, група КН-2630б
// Лабораторна робота № 3.1
// Розгалуження, задане формулою: функція однієї змінної.
// Варіант 33
//
//                  | 2x^4 + x^6 - x^8,              x < 4
// y = x + 1 +      | arctg((x+2)/3) + 8x,           4 <= x < 7
//                  | lg(x^2 + e^(x^2+2)),           x >= 7

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x; // вхідний аргумент
    double y; // результат обчислення виразу
    double A; // функціонально стала частина виразу
    double B; // функціонально змінна частина виразу

    cout << "x = "; cin >> x;

    A = x + 1;

    // спосіб 1: розгалуження в скороченій формі
    if (x < 4)
        B = 2 * pow(x, 4) + pow(x, 6) - pow(x, 8);
    if (4 <= x && x < 7)
        B = atan((x + 2) / 3) + 8 * x;
    if (x >= 7)
        B = log10(x * x + exp(x * x + 2));

    y = A + B;

    cout << endl;
    cout << "1) y = " << y << endl;

    // спосіб 2: розгалуження в повній формі
    if (x < 4)
        B = 2 * pow(x, 4) + pow(x, 6) - pow(x, 8);
    else
        if (x < 7)
            B = atan((x + 2) / 3) + 8 * x;
        else
            B = log10(x * x + exp(x * x + 2));

    y = A + B;

    cout << "2) y = " << y << endl;

    cin.get();
    return 0;
}
