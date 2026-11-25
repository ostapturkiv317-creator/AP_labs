// UnitTest_5_0.cpp
// Турків Остап Миколайович, група КН-2630б
// Лабораторна робота № 5.0
// Автоматизоване тестування.
//
// Unit-тест для функції f(x) з Лабораторної роботи № 5.1 (варіант 33):
//   f(x) = sin( (1 + x^2 + x^4) / (1 + x^2) )
//
// Проект типу "Native Unit Test Project" у Visual Studio,
// доданий у рішення з проектом Lab_5_1 (Add -> New Project -> Native Unit Test Project,
// потім References -> Add Reference -> Lab_5_1).

#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5_1/Lab_5_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest50
{
    TEST_CLASS(UnitTest50)
    {
    public:

        // f(0) = sin(1)
        TEST_METHOD(TestF_Zero)
        {
            double t = f(0);
            Assert::AreEqual(sin(1.0), t, 1e-9);
        }

        // f(1) = sin(3/2)
        TEST_METHOD(TestF_One)
        {
            double t = f(1);
            Assert::AreEqual(sin(1.5), t, 1e-9);
        }

        // f - парна функція: f(-x) = f(x)
        TEST_METHOD(TestF_Even)
        {
            Assert::AreEqual(f(2.5), f(-2.5), 1e-12);
        }
    };
}
