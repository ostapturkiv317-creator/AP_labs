// Lab_4_6.cpp
// Турків Остап Миколайович, група КН-2630б
// Лабораторна робота № 4.6
// Вкладені цикли.
// Варіант 33
//
//        10   1 + cos( sum_{k=1}^{n} sin k )
// P =   SUM   ------------------------------
//       n=1    ( 1 + sum_{k=1}^{n} sin k )^2

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double P; // зовнішня сума
    double S; // внутрішня сума S_n = sum sin k
    int n, k; // параметри циклів

    // 1) while ... while
    P = 0;
    n = 1;
    while (n <= 10)
    {
        S = 0;
        k = 1;
        while (k <= n)
        {
            S += sin(1. * k);
            k++;
        }
        P += (1 + cos(S)) / ((1 + S) * (1 + S));
        n++;
    }
    cout << "1) while      P = " << P << endl;

    // 2) do ... while
    P = 0;
    n = 1;
    do {
        S = 0;
        k = 1;
        do {
            S += sin(1. * k);
            k++;
        } while (k <= n);
        P += (1 + cos(S)) / ((1 + S) * (1 + S));
        n++;
    } while (n <= 10);
    cout << "2) do..while  P = " << P << endl;

    // 3) for (n++) ... for (k++)
    P = 0;
    for (n = 1; n <= 10; n++)
    {
        S = 0;
        for (k = 1; k <= n; k++)
            S += sin(1. * k);
        P += (1 + cos(S)) / ((1 + S) * (1 + S));
    }
    cout << "3) for ++     P = " << P << endl;

    // 4) for (n--) ... for (k--)
    P = 0;
    for (n = 10; n >= 1; n--)
    {
        S = 0;
        for (k = n; k >= 1; k--)
            S += sin(1. * k);
        P += (1 + cos(S)) / ((1 + S) * (1 + S));
    }
    cout << "4) for --     P = " << P << endl;

    return 0;
}
