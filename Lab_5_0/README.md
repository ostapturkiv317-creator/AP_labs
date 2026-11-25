# ЗВІТ

про виконання лабораторної роботи № 5.0
«Автоматизоване тестування»
з дисципліни «Алгоритмізація та програмування»
студента групи КН-2630б
**Турків Остап Миколайович**

---

## Умова завдання

1. (0,5 бала) Створити локальний git-репозиторій. Додати до нього папку рішення, створеного при виконанні Лабораторної роботи № 5.1. Скопіювати локальний git-репозиторій у віддалений.
2. (1 бал) Створити unit-тест до проекту. Виконати тест.
3. (0,5 бала) Внести зміни до локального репозиторію: оновлену папку рішення додати до локального репозиторію в нову гілку. Скопіювати внесені зміни у віддалений репозиторій. Злити гілки.

## Відповідь

### 1. Локальний та віддалений репозиторій

Проект Лабораторної роботи № 5.1 ([Lab_5_1.cpp](../Lab_5_1/Lab_5_1.cpp)) додано до локального git-репозиторію та скопійовано у віддалений репозиторій на GitHub:

```text
$ git log --oneline -1 -- Lab_5_1
71e42f4 Labs 1.1-5.5 (variant 33): programs and reports

$ git ls-tree --name-only origin/master Lab_5_1/
Lab_5_1/Lab_5_1.cpp
Lab_5_1/README.md

$ git ls-remote --heads origin
d4d3d4994e597ec48e66054445d687ea23a87dcd	refs/heads/branch_02
cec0b193632597f3587bad331314e8330852e352	refs/heads/master
```

### 2. Unit-тест

У рішення Visual Studio додано проект типу **Native Unit Test Project** (`File → Add → New Project → Native Unit Test Project`, режим **Add to solution**). Між проектом тесту і проектом Lab_5_1 встановлено зв'язок (`References → Add Reference → Lab_5_1`), а до тесту підключено файл `../Lab_5_1/Lab_5_1.cpp`.

Тест перевіряє функцію `f(x) = sin((1 + x² + x⁴)/(1 + x²))` трьома способами:

| Тест | Перевірка | Очікуване значення |
|---|---|---|
| `TestF_Zero` | `f(0)` | `sin(1) ≈ 0.841471` |
| `TestF_One` | `f(1)` | `sin(3/2) ≈ 0.997495` |
| `TestF_Even` | `f(−2.5) = f(2.5)` | функція парна |

Файл [UnitTest_5_0.cpp](UnitTest_5_0.cpp):

```cpp
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
```

Запуск тестів: **Test → Run All Tests**, результат у вікні **Test Explorer**.

> `[СКРІН: вікно Test Explorer з результатом 3 Passed]`
> Скрін треба зробити у Visual Studio після запуску тестів.

### 3. Нова гілка та злиття

```text
$ git checkout -b testbranch
Switched to a new branch 'testbranch'

$ git add Lab_5_0/UnitTest_5_0.cpp

$ git commit -m 'Lab 5.0: add unit test for f(x) from lab 5.1' -m 'Co-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>'
[testbranch efbb95c] Lab 5.0: add unit test for f(x) from lab 5.1
 1 file changed, 45 insertions(+)
 create mode 100644 Lab_5_0/UnitTest_5_0.cpp

$ git push -u origin testbranch
remote: 
remote: Create a pull request for 'testbranch' on GitHub by visiting:        
remote:      https://github.com/ostapturkiv317-creator/AP_labs/pull/new/testbranch        
remote: 
To https://github.com/ostapturkiv317-creator/AP_labs.git
 * [new branch]      testbranch -> testbranch
branch 'testbranch' set up to track 'origin/testbranch'.

$ git checkout master
Switched to branch 'master'
Your branch is up to date with 'origin/master'.

$ git merge testbranch -m 'Merge branch testbranch into master' -m 'Co-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>'
Updating cec0b19..efbb95c
Fast-forward (no commit created; -m option ignored)
 Lab_5_0/UnitTest_5_0.cpp | 45 +++++++++++++++++++++++++++++++++++++++++++++
 1 file changed, 45 insertions(+)
 create mode 100644 Lab_5_0/UnitTest_5_0.cpp

$ git push origin master
To https://github.com/ostapturkiv317-creator/AP_labs.git
   cec0b19..efbb95c  master -> master

$ git log --oneline --graph -4
* efbb95c Lab 5.0: add unit test for f(x) from lab 5.1
*   cec0b19 Merge branch branch_02 into master
|\  
| * d4d3d49 branch_02: replace 1.txt with 2.txt
* | 337c39e master: update 3.txt
```

## Висновки

Я навчився створювати unit-тести для функцій C++ програми засобами Visual Studio (Microsoft CppUnitTestFramework). Метод `Assert::AreEqual(expected, actual, tolerance)` порівнює очікуване й фактичне значення з допустимою похибкою, що потрібно для дійсних чисел. Також закріпив роботу з git: розміщення проекту у віддаленому репозиторії, створення окремої гілки для тесту та злиття гілок.
