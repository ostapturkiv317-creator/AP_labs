// pr1.cpp
// Турків Остап Миколайович, група КН-2630б
// Лабораторна робота № 1.3
// Виправлена версія: розкоментовано i++ (причина зациклення)

#include <iostream>

using namespace std;

int main()
{
    cout << "Hello, World!" << endl;

    int p = 1;
    int i = 1;
    while (i <= 10)
    {
        p *= i;
        i++;
    };
    cout << "p = " << p << "   i = " << i << endl;

    system("pause");
    return 0;
}
