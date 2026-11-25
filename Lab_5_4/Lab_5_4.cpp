// Lab_5_4.cpp
// Турків Остап Миколайович, група КН-2630б
// Лабораторна робота № 5.4
// Обчислення сум та добутків за допомогою рекурсії.
// Варіант 33
//
// S = sum_{k=1}^{N} 1 / (2k + 1)^2

#include <iostream>

using namespace std;

// доданок суми
double term(const int k)
{
    return 1.0 / ((2 * k + 1) * (2 * k + 1));
}

// 5) ітераційний спосіб (контроль)
double S0(const int N)
{
    double s = 0;
    for (int k = 1; k <= N; k++)
        s += term(k);
    return s;
}

// обчислення на рекурсивному підйомі, параметр зростає
double S1(const int N, const int k)
{
    if (k > N)
        return 0;
    else
        return term(k) + S1(N, k + 1);
}

// обчислення на рекурсивному підйомі, параметр спадає
double S2(const int N, const int k)
{
    if (k < 1)
        return 0;
    else
        return term(k) + S2(N, k - 1);
}

// обчислення на рекурсивному спуску, параметр зростає
double S3(const int N, const int k, double t)
{
    t = t + term(k);
    if (k >= N)
        return t;
    else
        return S3(N, k + 1, t);
}

// обчислення на рекурсивному спуску, параметр спадає
double S4(const int N, const int k, double t)
{
    t = t + term(k);
    if (k <= 1)
        return t;
    else
        return S4(N, k - 1, t);
}

int main()
{
    int N;
    cout << "N = "; cin >> N;

    cout << "(iter)         S0 = " << S0(N)        << endl;
    cout << "(rec up ++)    S1 = " << S1(N, 1)     << endl;
    cout << "(rec up --)    S2 = " << S2(N, N)     << endl;
    cout << "(rec down ++)  S3 = " << S3(N, 1, 0)  << endl;
    cout << "(rec down --)  S4 = " << S4(N, N, 0)  << endl;

    return 0;
}
