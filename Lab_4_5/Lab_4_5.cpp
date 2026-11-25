// Lab_4_5.cpp
// Турків Остап Миколайович, група КН-2630б
// Лабораторна робота № 4.5
// «Попадання» у плоску фігуру.
// Варіант 33
//
// Область:
//  A: x <= 0, y >= 0, x^2 + y^2 <= R2^2
//  B: x >= 0, y <= 0, R2^2 <= x^2 + y^2 <= R1^2
// 2 спосіб: інтервал x, y належать [-R1; R1]

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    double x, y;   // координати пострілу
    double R1, R2; // радіуси кіл

    cout << "R1 = "; cin >> R1;
    cout << "R2 = "; cin >> R2;

    srand((unsigned)time(NULL));

    // 1 спосіб: 10 пострілів, координати вводяться з клавіатури
    for (int i = 0; i < 10; i++)
    {
        cout << "x = "; cin >> x;
        cout << "y = "; cin >> y;

        double d = x * x + y * y;
        if ((x <= 0 && y >= 0 && d <= R2 * R2) ||
            (x >= 0 && y <= 0 && d >= R2 * R2 && d <= R1 * R1))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    cout << endl << fixed;

    // 2 спосіб: 10 випадкових пострілів з інтервалу [-R1; R1]
    for (int i = 0; i < 10; i++)
    {
        x = -R1 + 2.0 * R1 * rand() / RAND_MAX;
        y = -R1 + 2.0 * R1 * rand() / RAND_MAX;

        double d = x * x + y * y;
        cout << setw(8) << setprecision(4) << x << "  "
             << setw(8) << setprecision(4) << y << "  ";
        if ((x <= 0 && y >= 0 && d <= R2 * R2) ||
            (x >= 0 && y <= 0 && d >= R2 * R2 && d <= R1 * R1))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}
