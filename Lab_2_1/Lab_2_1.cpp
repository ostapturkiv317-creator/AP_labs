// Lab_2_1.cpp
// Турків Остап Миколайович, група КН-2630б
// Лабораторна робота № 2.1
// Лінійні програми.
// Варіант 33

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double alpha; // вхідний параметр (кут альфа, радіани)
    double beta;  // вхідний параметр (кут бета, радіани)
    double z1;    // результат обчислення 1-го виразу
    double z2;    // результат обчислення 2-го виразу

    cout << "alpha = "; cin >> alpha;
    cout << "beta  = "; cin >> beta;

    // z1 = (sin a + cos(2b - a)) / (cos a - sin(2b - a))
    z1 = (sin(alpha) + cos(2 * beta - alpha)) / (cos(alpha) - sin(2 * beta - alpha));

    // z2 = (1 + sin 2b) / cos 2b
    z2 = (1 + sin(2 * beta)) / cos(2 * beta);

    cout << endl;
    cout << "z1 = " << z1 << endl;
    cout << "z2 = " << z2 << endl;

    cin.get();
    return 0;
}
