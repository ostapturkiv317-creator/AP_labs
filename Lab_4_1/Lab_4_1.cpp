// Lab_4_1.cpp
// Турків Остап Миколайович, група КН-2630б
// Лабораторна робота № 4.1
// Цикли.
// Варіант 33
//
// S = sum_{k=1}^{N} 1 / (2k + 1)^2

#include <iostream>

using namespace std;

int main()
{
    int N;    // верхня межа суми
    int k;    // параметр циклу
    double S; // сума

    cout << "N = "; cin >> N;

    // 1) while
    S = 0;
    k = 1;
    while (k <= N)
    {
        S += 1.0 / ((2 * k + 1) * (2 * k + 1));
        k++;
    }
    cout << "1) while       S = " << S << endl;

    // 2) do ... while
    S = 0;
    k = 1;
    do {
        S += 1.0 / ((2 * k + 1) * (2 * k + 1));
        k++;
    } while (k <= N);
    cout << "2) do...while  S = " << S << endl;

    // 3) for (k++)
    S = 0;
    for (k = 1; k <= N; k++)
    {
        S += 1.0 / ((2 * k + 1) * (2 * k + 1));
    }
    cout << "3) for k++     S = " << S << endl;

    // 4) for (k--)
    S = 0;
    for (k = N; k >= 1; k--)
    {
        S += 1.0 / ((2 * k + 1) * (2 * k + 1));
    }
    cout << "4) for k--     S = " << S << endl;

    return 0;
}
