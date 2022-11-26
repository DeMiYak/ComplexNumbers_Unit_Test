/**
ѕроследить, что работают корректно (согласованно) все методы и операции
дл€ различных значений (вырожденных, невырожденных, положительных, отрицательных и т.д.):


* получение вещественной и мнимой части, модул€,
*(абсолютна€ величина), комплексно-сопр€женного значени€;

* операции +, - (унарные)

* присваивание (=, +=, -=, *=, /=)

* бинарные арифметические (+, -, *, /) и сравнени€ , сравнени€ (==, !=)
* дл€ всех пар типов аргументов (cplx o cplx, cplx o dbl, dbl o cplx)

* ввода и вывода (<<, >>) с помощью stringstream
* (дл€ тестов использовать строковые потоки дл€ ввода и вывода информации из строки/в строку).

*/

#include<iostream>
#include<cmath>
#include<sstream>
#include"Complex_Test.h"
#include"triangle.h"

void test_getValue()
{
    complex c1(5, 12), c2(1.0/0.0, 0.0/0.0);
    const double cre = c1.get_Re(), cim = c1.get_Im();
    const double c2re = c2.get_Re(), c2im = c2.get_Im();
    EXCEPT_EQ(cre, 5);
    EXCEPT_EQ(cim, 12);
    EXCEPT_INF(c2re);
    EXCEPT_NAN(c2im);
    EXCEPT_EQ(c1.Mo(), 13);
    c1 = c1.Co();
    EXCEPT_EQ(cre, c1.Re());
    EXCEPT_EQ(cim, -c1.Im());
};
void test_unarOperator()
{
    complex c1(5, 12), c2(1.0/0.0, -1.0/0.0);
    EXCEPT_NEG(c1, -c1);
    EXCEPT_NEG(c2, -c2);
    EXCEPT_EQ(c1, +c1);
    EXCEPT_EQ(c2, +c2);

};
void test_assignment()
{
    complex c1(1, 7), c2(1.0/0.0, -1.0/0.0);
    complex c3 = c1, c4 = c2;
    EXCEPT_EQ(c1, c3);
    EXCEPT_EQ(c2, c4);
    complex c5(-5, 8), c6(13, -1);
    c3 = {0, 0};
    c3 += c5;
    c4 = {0, 0};
    c4 -= c6;
    EXCEPT_EQ(c3, c5);
    EXCEPT_NEG(c4, c6);
    c3 *= c1;
    c4 *= c1;
    complex cBlank3 = c5*c1, cBlank4 = -c6*c1;
    EXCEPT_EQ(c3, cBlank3);
    EXCEPT_NEG(c4, cBlank4);
};
void test_binOperator()
{
    double d = 4;
    complex c1(5,-12), c2(-8, 6), c3(1, 0), c4(0, 2);
    complex c5(1.0/0.0,-1.0/0.0), c6(0.0/0.0, 0.0/0.0);
    complex Check(4, -3);
    EXCEPT_EQ(c2/(-2), Check);
    complex res = c1.Mo()*c2.Mo() - c4 + 3*c3 + (-d)*c2 + c2/d*c4; // 130 + (0, -2) + (3,0) + (32, -24) + (-3, -4);
    complex Check2(162, -30);
    std::cout << res << std::endl;
    EXCEPT_EQ(res, Check2);
};
void test_inoutOperator()
{
    complex c1(5,-12);
    double cre, cim;
    char buffer;
    std::stringstream stri;
    stri << c1;
    // std::string cStr = std::cout << c1;
    EXCEPT_EQ(stri.str(), "(5, -12)");

    stri >> buffer >> cre >> buffer >> cim >> buffer;
    std::cout << cre << " " << cim << std::endl;
    EXCEPT_EQ(cre, c1.Re());
    EXCEPT_EQ(cim, c1.Im());
};

/**
* ввода и вывода (<<, >>) с помощью stringstream
* (дл€ тестов использовать строковые потоки дл€ ввода и вывода информации из строки/в строку).

*/
