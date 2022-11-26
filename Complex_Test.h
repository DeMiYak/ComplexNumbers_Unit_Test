#ifndef COMPLEX_TEST_H_INCLUDED
#define COMPLEX_TEST_H_INCLUDED

#include<iostream>
#include<algorithm>
#include<cmath>
#include"triangle.h"

#ifndef TEST_ASSERT
#define TEST(x)                     \
    if (!(x)) std::cerr << "check " \
    << #x << " "                    \
    << " failed in file "           \
    << __FILE__                     \
    << " at line "                  \
    << __LINE__ << std::endl;
#else
#define TEST(x) assert(x);
#endif // TEST_ASSERT


#define EXCEPT_EQ(x,y) TEST((x)==(y));
#define EXCEPT_NQ(x,y) TEST((x)!=(y));
#define EXCEPT_NAN(x) TEST((x)!=(x));
#define EXCEPT_INF(x) TEST((x) == 1.0/0.0 || (x) == -1.0/0.0);
#define EXCEPT_PINF(x) TEST((x) == 1.0/0.0);
#define EXCEPT_NINF(x) TEST((x) == -1.0/0.0);
#define EXCEPT_APPR(x,y,eps)        \
    TEST(std::abs((x-y)/std::max(x,y)) < eps);
#define EXCEPT_NEG(x,y) TEST((x)==(-y));


void test_getValue();
void test_unarOperator();
void test_assignment();
void test_binOperator();
void test_inoutOperator(); // StringStream

#endif // COMPLEX_TEST_H_INCLUDED

/**
Проследить, что работают корректно (согласованно) все методы и операции
для различных значений (вырожденных, невырожденных, положительных, отрицательных и т.д.):


* получение вещественной и мнимой части, модуля,
*(абсолютная величина), комплексно-сопряженного значения;

* операции +, - (унарные)

* присваивание (=, +=, -=, *=, /=)

* бинарные арифметические (+, -, *, /) и сравнения , сравнения (==, !=)
* для всех пар типов аргументов (cplx o cplx, cplx o dbl, dbl o cplx)

* ввода и вывода (<<, >>) с помощью stringstream
* (для тестов использовать строковые потоки для ввода и вывода информации из строки/в строку).

*/
